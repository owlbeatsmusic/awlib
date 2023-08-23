#ifndef CONFIG_H_
#define CONFIG_H_

int awlib_config_add_string(char *file_path, char *key, char *value);
int awlib_config_create(char *file_path);
int awlib_config_get_string(char *file_path, char *key, char *destination_buffer, int buffer_size);
int awlib_config_set_string(char *file_path, char *key, char *value);

#endif
