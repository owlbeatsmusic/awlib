#ifndef LOG_H_
#define LOG_H_

// creates the log file at given filepath
// (cleared if already exsist)
int awlib_log_create(char *file_path);

// output formatted input to specified log file
int awlib_log(char *file_path, char *input, ...);

// output formatted input to specified log file with timestamp
int awlib_log_t(char *file_path, char *input, ...);

#endif
