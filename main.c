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

	//awlib_config_create("config.ini");
	//awlib_config_add_string("config.ini", "test_key_1", "värde1");



	awlib_log_create("log.txt");
	// awlib_log_print_f("log.txt", "HALLÅ, detta är viktigt", __FILE__);

	awlib_log_print_t("log.txt", "7 2189379872 9 HALLÅ, detta är viktigt 2");
	
	awlib_log_print_string("log.txt", "vadå\n");

	//char dest_buf[100];
	//awlib_config_get_string("config.ini", "test_key_1", dest_buf, 100);
	
	//printf("dest_buf=%s\n", dest_buf);
	
	//awlib_config_set_string("config.ini", "test_key_1", "byte1");

	//printf("dest_buf=%s\n", dest_buf);

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
