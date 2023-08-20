#include "awlib_input/input.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int keyboard_input(int key_code) {
	printf("keycode=%d\n", key_code);
	return 0;
}

int main() {
	awlib_input_start(keyboard_input);
	sleep(3);
}
