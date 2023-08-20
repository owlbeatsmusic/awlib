#ifndef CONFIG_H_
#define CONFIG_H_

//void grafik_config_add_string(char *key, char *value);
int awlib_config_create(char *file_path);
int grafik_config_get_string(char *file_path, char *key, char *destination_buffer, int buffer_size);
int grafik_config_set_string(char *file_path, char *key, char *value);

#endif
