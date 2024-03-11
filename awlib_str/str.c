#include <string.h>
#include <stdio.h>

int awlib_str_compare_at_index(char *content, int index, char* compare) {
	for (int i = 0; i < strlen(compare); i++) {
		if (content[index+i] != compare[i]) return 0;
	}
	return 1;
}

// FROM OLib (java)

void awlib_str_del_first_chars(char *str, int length) {

	return;
}

void awlib_str_del_last_chars(char *str, int length) {

	return;
}


char *awlib_str_get_first_chars(char* str, int length) {

	return "";
}

char *awlib_str_get_last_chars(char* str, int length) {

	return "";
}

int awlib_str_count_chars(char* str, char chr) {
	
	return 0;
}

int awlib_str_count_strings(char* str, char* lookup_str) {
	
	return 0;
}

