#ifndef LOG_H_
#define LOG_H_

int awlib_log_create(char *file_path);
int awlib_log_print_string(char *file_path, char *input);
int awlib_log_print_f(char *file_path, char *input, char *this_file);
int awlib_log_print_t(char *file_path, char *input);
int awlib_log_print_ft(char *file_path, char *input, char *this_file);

#endif
