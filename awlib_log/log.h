#ifndef LOG_H_
#define LOG_H_

// creates the log file at given filepath
// (cleared if already exsist)
int awlib_log_create(char *file_path);

// appending variables the at end of log file
int awlib_log_print_string(char *file_path, char *input);
int awlib_log_print_int(char *file_path, int input);
int awlib_log_print_float(char *file_path, float input, int decimals);

// print message with time at the start of the line.
int awlib_log_print_t(char *file_path, char *input);

// print message with file at the start of the line.
int awlib_log_print_f(char *file_path, char *input);

// print with file and time at the start of the line 
int awlib_log_print_ft(char *file_path, char *input, char *this_file);

#endif
