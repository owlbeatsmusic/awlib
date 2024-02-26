#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

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

int awlib_log_print_string(char *file_path, char *input) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);
	
	if (fputs(input, log_file) == EOF) {
		perror("error while writing to log file");
		fclose(log_file);
		return -1;
	}
	fclose(log_file);
	return 0;
}

int awlib_log_print_int(char *file_path, int input) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);
	
	char input_buf[(int)((ceil(log10(input))+1))];
	sprintf(input_buf, "%d", input);

	if (fputs(input_buf, log_file) == EOF) {
		perror("error while writing to log file");
		fclose(log_file);
		return -1;
	}
	fclose(log_file);
	return 0;
}

int awlib_log_print_float(char *file_path, float input, int decimals) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);

	char input_buf[(int)(ceil(log10((input))+1)) + decimals];
	sprintf(input_buf, "%f", input);
	//gcvt(input, sizeof(input_buf)/sizeof(char), input_buf);

	if (fputs(input_buf, log_file) == EOF) {
		perror("error while writing to log file");
		fclose(log_file);
		return -1;
	}
	fclose(log_file);
	return 0;
}


//                  time
int awlib_log_print_t(char *file_path, char *input) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);

	// time string
	time_t current_time;
	struct tm *local_time;
	char formatted_time[33];
	
	current_time = time(NULL);
	local_time = localtime(&current_time);
	strftime(formatted_time, sizeof(formatted_time), "[%Y-%m-%d %H:%M:%S]: ", local_time);
	
	if (fputs(formatted_time, log_file) == EOF) {
		perror("[t] error while writing to log file");
		fclose(log_file);
		return -1;
	}

	fclose(log_file);
	awlib_log_print_string(file_path, input);
	
	return 0;
}

//                  file
int awlib_log_print_f(char *file_path, char *input, char *this_file) {
	FILE *log_file = fopen(file_path, "a");
	awlib_log_checkfile_internal(log_file);

	char dest_buffer[50] = "[";
	strcat(dest_buffer, this_file);
	strcat(dest_buffer, "]: ");

	if (fputs(dest_buffer, log_file) == EOF) {
		perror("([f] error while writing to log file");
		fclose(log_file);
		return -1;
	}

	fclose(log_file);
	awlib_log_print_string(file_path, input);
	
	return 0;
}
//                  file & time
int awlib_log_print_ft(char *file_path, char *input, char *this_file) {
	return 0;
}


