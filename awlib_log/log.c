#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int awlib_log_checkfile_internal(FILE *log_file) {
	if (log_file == NULL) {
		perror("error: failed to open logfile");
		return -1;
	}
	return 0;
}

int awlib_log_create(char *file_path) {
	FILE *log_file = fopen(file_path, "w");
	awlib_log_checkfile_internal(log_file);
	fclose(log_file);

	return 0;
}

int awlib_log(char *file_path, char *input, ...) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);


	/* for using formatting for input (eg: %d) */
	va_list va;
	char output[strlen(input)];
	va_start(va, input);
	vsprintf(output, input, va);
	va_end(va);

	
	if (fputs(output, log_file) == EOF) {
		perror("error while writing to log file");
		fclose(log_file);
		return -1;
	}
	fclose(log_file);
	return 0;
}

int awlib_log_t(char *file_path, char *input, ...) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);

	va_list va;


	time_t current_time;
	struct tm *local_time;
	char formatted_time[33];
	
	current_time = time(NULL);
	local_time = localtime(&current_time);
	strftime(formatted_time, sizeof(formatted_time), "[%Y-%m-%d %H:%M:%S]: ", local_time);
	
	awlib_log(file_path, "%s", formatted_time);
	awlib_log(file_path, input, va);

	return 0;
}
