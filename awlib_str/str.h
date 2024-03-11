#ifndef STR_H_
#define STR_H_

int awlib_str_compare_at_index(char *content, int index, char* compare);

// from OLib (java)
void awlib_str_del_first_chars(char *str, int length);
void awlib_str_del_last_chars(char *str, int length);
char *awlib_str_get_first_chars(char* str, int length);
char *awlib_str_get_last_chars(char* str, int length);
int awlib_str_count_chars(char* str, char chr);
int awlib_str_count_strings(char* str, char* lookup_str);

#endif
