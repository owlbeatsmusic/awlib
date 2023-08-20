#ifndef INPUT_H_
#define INPUT_H_

typedef int (*KeybdInputFunction)(int);

int awlib_input_start(KeybdInputFunction keybd_function);

#endif
