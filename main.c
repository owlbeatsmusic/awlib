#include "awlib_config/config.h"
#include "awlib_input/input.h"
#include "awlib_log/log.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_keyboard_function(int key_code) {
	printf("keycode=%d\n", key_code);
	return 0;
}

int main() {

	awlib_log_create("log.txt");
	// awlib_log_print_f("log.txt", "HALLÅ, detta är viktigt", __FILE__);
	awlib_log_print_t("log.txt", "HALLÅ, detta är viktigt");

/* input example

	awlib_input_detect_set_keybd_device();
	
	//awlib_input_set_keybd_device("custom/file/path");
	
	char event_device[64];
	awlib_input_get_keybd_device(event_device);
	printf("get=%s\n", event_device);

	awlib_input_start(my_keyboard_function);
	sleep(1);
*/

	return 0;
}
