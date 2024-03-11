#ifndef INPUT_H_
#define INPUT_H_

typedef int (*KeybdInputFunction)(int);

// promts you to press a key then automaticly sets 
// the keyboard device
int awlib_input_detect_set_keybd_device();

// if you have the path to your keyboard device
// use this function to set it to that.
int awlib_input_set_keybd_device(char *path_to_device);

// get the file path to your keyboard device.
int awlib_input_get_keybd_device(char *destination);

// start detecting keyboard input and send it 
// to specified funtion.
int awlib_input_start(KeybdInputFunction keybd_function);

#endif
