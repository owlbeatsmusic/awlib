# awlib
After working on "grafik" I decided to create this instead. So some files will be originated from "grafik".

## Logging Library
(It's super basic)
How to use:
1. Create the log file beforehand or if you wan't to clear it(/create it) within code, use:
   ```c
   awlib_log_create("log_example.txt");
   ```
2. Then to log to the file, depending on which information you want included use:
 - **Time & Date**
   ```c
   awlib_log_print_t("log_example.txt", "message");
   ```
   this will output to the *./log_example.txt*:
   ```
   [2024-02-09 12:00:37]: message
   ```
   <br/><br/>
 - **File**
   ```c
   awlib_log_print_f("log_example.txt", "message");
   ```
   this will output to the *./log_example.txt*:
   ```
   [main.c]: message 
   ```
   <br/><br/>
 - **Time, Date & File**

These will not add line break so to append strings and numbers to the log message use:
   ```c
   awlib_log_print_string("log_example.txt", "message");
   ```
   ```c
   awlib_log_print_int("log_example.txt", 123);
   ```
   ```c
   awlib_log_print_float("log_example.txt", 3.14, 2); // 2 is the ammount of decimals
   ```

<br/><br/>
## Input Library
How to use:
1. Add both files from *awlib_input/* or the directory.
<br/><br/>
2. In your file(example: main.c) you first need to decide which way to set the keyboard input device:
 - **Automatic**:
	```c
	awlib_input_detect_set_keybd_device()
	```
	This will prompt you to press any key and it then sets the keyboard input device to the right device.
<br/><br/>
 - **Manual**:
 	  ```c
 	awlib_input_set_keybd_device(char *path_to_device)
 	```
 	This avoids any prompts if you have the current device in for example a config file.
	
 	> **⚠️ The event device can change on boot**: <br/> This usually dosnt happen with built-in keyboards!
<br/><br/>

3. Create a function where the keyboard input gets sent:
	```c
	int my_keyboard_function(int key_code) {
		printf("keycode=%d\n", key_code);
		return 0;
	}
	```
	Then use the:
	```c
	awlib_input_start(my_keyboard_function);
	```
	and the input will run until your program is finished, you can for example add a `sleep(10)` after the input start to let it run for 10 seconds.
