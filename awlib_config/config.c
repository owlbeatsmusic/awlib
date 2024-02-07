#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define KEY_VALUE_SETS_SIZE 64
#define KEY_VALUE_SET_BUFFER_SIZE 128

typedef struct {
	char key_buffer[KEY_VALUE_SET_BUFFER_SIZE];
	char value_buffer[KEY_VALUE_SET_BUFFER_SIZE];
} KeyValueSet;

int awlib_config_parse_internal(char *file_content, int file_length, KeyValueSet key_value_sets[]) {
	
	char temp_buf[128];
	memset(temp_buf, 0, sizeof(temp_buf)); // clear temp_buf
	printf("temp_buf=\"%s\"\n", temp_buf);
	
	int temp_buf_index = 0;
	int key_value_sets_index = 0;

	for (int i = 0; i < file_length+1; i++) {
		if (file_content[i] == '=') {
			strcpy(key_value_sets[key_value_sets_index].key_buffer, temp_buf);
		}
		if (file_content[i] == '\n') {
			strcpy(key_value_sets[key_value_sets_index].value_buffer, temp_buf);
			key_value_sets_index++;
		}
		if (file_content[i] == '=' || file_content[i] == '\n') {
			memset(temp_buf, 0, sizeof(temp_buf)); // clear temp_buf
			temp_buf_index = 0;
			i++;
		}
		temp_buf[temp_buf_index] = file_content[i];
		temp_buf_index++;
	}
	return 0;
}

int awlib_config_add_string(char *file_path, char *key, char *value) {
	
	return 0;
}

int awlib_config_create(char* file_path) {
	FILE *file = fopen(file_path, "w");
	if (file == NULL) {
		perror("error while opening/creating config file");
		return -1;
	}
	fclose(file);
	return 0;
}

int awlib_config_get_string(char *file_path, char *key, char *destination_buffer, int buffer_size) {
	if (buffer_size != KEY_VALUE_SET_BUFFER_SIZE) {
		printf("error: destination_buffer needs to be %d\n", KEY_VALUE_SET_BUFFER_SIZE);
		return -1;
	}
	FILE *file = fopen(file_path, "r"); 
	if (file == NULL) {
		printf("error: failed to open config file(%s)\n", file_path);
		return -1;
	}

	fseek(file, 0L, SEEK_END);
	int file_length = ftell(file);
	fseek(file, 0L, SEEK_SET);
	
	char *file_content = (char *)malloc(file_length * sizeof(char) + 1);
	if (file_content == NULL) {
		perror("error: Memory allocation failed");
		fclose(file);
		return -1;
	}
	
	fread(file_content, file_length, 1, file);
	file_content[file_length] = '\0';

	KeyValueSet key_value_sets[KEY_VALUE_SETS_SIZE];
	
	awlib_config_parse_internal(file_content, file_length, key_value_sets);

	// find matching key and set destination buffer
	for (int i = 0; i < KEY_VALUE_SETS_SIZE; i++) {
		if (strcmp(key_value_sets[i].key_buffer, key) != 0) continue;
		for (int j = 0; j < KEY_VALUE_SET_BUFFER_SIZE; j++) {
			destination_buffer[j] = key_value_sets[i].value_buffer[j];
		}
		break;
	}

	return 0;
}


int awlib_config_set_string(char *file_path, char *key, char *value) {	
	FILE *file = fopen(file_path, "r"); 
	if (file == NULL) {
		printf("error: failed to open config file(%s)\n", file_path);
		return -1;
	}
	
	fseek(file, 0L, SEEK_END);
	int file_length = ftell(file);
	fseek(file, 0L, SEEK_SET);
	
	char *file_content = (char *)malloc(file_length * sizeof(char) + 1);
	if (file_content == NULL) {
		perror("error: Memory allocation failed");
		fclose(file);
		return -1;
	}
	
	fread(file_content, file_length, 1, file);
	file_content[file_length] = '\0';
	
	KeyValueSet key_value_sets[KEY_VALUE_SETS_SIZE];

	awlib_config_parse_internal(file_content, file_length, key_value_sets);

	
	// find matching key and set value
	for (int i = 0; i < KEY_VALUE_SETS_SIZE; i++) {
		if (strcmp(key_value_sets[i].key_buffer, key) != 0) continue;
		memset(key_value_sets[i].value_buffer, 0, sizeof(key_value_sets[i].value_buffer));
		for (int j = 0; j < strlen(value); j++) {
			key_value_sets[i].value_buffer[j] = value[j];
		}
		break;
	}


	// write back to file
	free(file_content);
	fclose(file);
	
	file = fopen(file_path, "w"); 
	if (file == NULL) {
		printf("error: failed to open config file(%s)\n", file_path);
		return -1;
	}
	for (int i = 0; i < KEY_VALUE_SETS_SIZE; i++) {
		if (strlen(key_value_sets[i].key_buffer) == 0 || 
		   (strlen(key_value_sets[i].key_buffer) == 1 && (int)key_value_sets[i].key_buffer[0] == strlen(value))) continue;
		printf("%s=%s\n", key_value_sets[i].key_buffer, key_value_sets[i].value_buffer);
		fprintf(file, "%s=%s\n", key_value_sets[i].key_buffer, key_value_sets[i].value_buffer);
	}

	// print the key_value_sets array
	for (int i = 0; i < KEY_VALUE_SETS_SIZE; i++) {
		printf("%d:\n   key  : %d\n   value: %s\n", i, (int)key_value_sets[i].key_buffer[0], key_value_sets[i].value_buffer);
	}

	
	return 0;
}
