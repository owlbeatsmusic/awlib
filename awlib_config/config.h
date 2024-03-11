#ifndef CONFIG_H_
#define CONFIG_H_

// adds a key-value pair with value as string
int awlib_config_add_string(char *file_path, char *key, char *value);

// creates the config file at given filepath
// (cleared if already exsist)
int awlib_config_create(char *file_path);

// get string from config file with the 
// key as the identifier(name) for the value.
// TODO: return string instead of writing to buffer
int awlib_config_get_string(char *file_path, char *key, char *destination_buffer, int buffer_size);

// set the value of a key
int awlib_config_set_string(char *file_path, char *key, char *value);

#endif
