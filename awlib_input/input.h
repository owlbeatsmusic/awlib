#ifndef INPUT_H_
#define INPUT_H_

typedef int (*KeybdInputFunction)(int);

int awlib_input_detect_set_keybd_device();
int awlib_input_set_keybd_device(char *path_to_device);
int awlib_input_get_keybd_device(char *destination);

int awlib_input_start(KeybdInputFunction keybd_function);

#endif
