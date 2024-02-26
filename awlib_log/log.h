#ifndef LOG_H_
#define LOG_H_

int awlib_log_create(char *file_path);

int awlib_log_print_string(char *file_path, char *input);
int awlib_log_print_int(char *file_path, int input);
int awlib_log_print_float(char *file_path, float input, int decimals);

int awlib_log_print_t(char *file_path, char *input);
int awlib_log_print_ft(char *file_path, char *input, char *this_file);

#endif
