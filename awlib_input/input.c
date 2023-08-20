#include <linux/input.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>



// input device detector 
struct DetectorThreadArgs {
	int event_device_number;
};

char event_device_file_path[64];
char mouse_device_file_path[64];

int current_event_device_number = -1;

void *event_thread(void *arg) {
	struct DetectorThreadArgs *args = (struct DetectorThreadArgs *)arg;
	int event_device_number = args->event_device_number;
	
	char *prefix = "/dev/input/event";
	// 10 is the largest length of a integer in charcters
	char device_number_string[10];
	sprintf(device_number_string, "%d", event_device_number);

	char event_device_path[sizeof(prefix) + sizeof(device_number_string)];

	strcat(event_device_path, prefix);
	strcat(event_device_path, device_number_string);

	int fd = open(event_device_path, O_RDONLY);
	if (fd == -1) {
		perror("error openeing input device");
		return 0;
	
	}
	
	struct input_event ev;
	while (1) {
		//printf("loop: %s\n", event_device_path);
		ssize_t n = read(fd, &ev, sizeof(struct input_event));
		if (n == (ssize_t)-1) {
			perror("error reading input");
			close(fd);
			return 0;
		}

		if (ev.type == EV_KEY) {
			current_event_device_number = event_device_number;
			return 0;
		}	
	}
}

int awlib_input_detect_set_device() {

	int devices = 0;

	// event devices
	DIR *dir = opendir("/dev/input");
	if (dir== NULL) {
		perror("error opening directory(/dev/input");
		return EXIT_FAILURE;
	}
	
	char *prefix = "event";
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (strncmp(entry->d_name, prefix, strlen(prefix)) == 0) {
			devices++;
		}
	}
	closedir(dir);

	printf("devices=%d\n", devices);

	pthread_t threads[devices];
	for (int i = 0; i < devices; i++) {
		struct DetectorThreadArgs args;
		args.event_device_number = i;
		if (pthread_create(&threads[i], NULL, event_thread, (void *)&args) != 0) {
			perror("error: failed to create thread");
			return EXIT_FAILURE;
		}
		usleep(10000);
	}
	
	char input_char;
	printf("Enter a charcter: ");
	fflush(stdout);
	scanf("%c", &input_char);
	fflush(stdout);
	
	sprintf(event_device_file_path, "/dev/input/event%d", current_event_device_number);
	printf("keyboard input device detected: \"%s\"\n", event_device_file_path);

	for (int i = 0; i < devices; i++) {
		pthread_cancel(threads[i]);
	}

	return 0;
	
}

int awlib_input_set_device(char *path_to_device) {
	strcpy(event_device_file_path, path_to_device);
	return 0;
}

int awlib_input_get_device(char *destination) {
	strcpy(destination, event_device_file_path);
	return 0;
}



// keyboard input
typedef int (*KeybdInputFunction)(int);
KeybdInputFunction keyboard_function;

pthread_t keyboard_thread;
void *keyboard_input_thread(void *arg) {

	int fd = open(event_device_file_path, O_RDONLY);
	if (fd == -1) {
		printf("error opening \"%s\" device\n", event_device_file_path);
		return 0;
	}

	struct input_event ev;

	while (1) {	
		ssize_t n = read(fd, &ev, sizeof(struct input_event));
		if (n == (ssize_t)-1) {
			perror("error reading event");
			close(fd);
			return 0;
		}

		if (ev.type == EV_KEY && ev.value == 1) {
			(*keyboard_function)(ev.code);
		}
	}
	return 0;

}

// main
int awlib_input_start(KeybdInputFunction keyboard_destination_function) {

	keyboard_function = keyboard_destination_function;
	
	if (pthread_create(&keyboard_thread, NULL, keyboard_input_thread, NULL) != 0) {
		perror("error: failed to create keyboard thread");
		return EXIT_FAILURE;
	}
}

int awlib_input_stop() {
	pthread_cancel(keyboard_thread);
}




