#ifndef LOG_H_
#define LOG_H_

int awlib_log_create(char *file_path);
int awlib_log_print(char *file_path, char *input);
int awlib_log_print_file(char *file_path, char *input);
int awlib_log_print_date(char *file_path, char *input);
int awlib_log_print_file_date(char *file_path, char *input);

#endif
