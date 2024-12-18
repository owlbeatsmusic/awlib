# awlib
These are meant to be lightweight and super simple basic libraries that I've needed in lots of small projetcs. These all work stand-alone so if you need just for example the logging library, then just download that folder with the file and header and you are good to go. Don't expect anything more than the bare minimum for any of them though.

**status**
 - 🟢 [Log](#logging-library): working
 - 🟢 [Input](#input-library): working	
 - 🔴 Config: not working
 - 🟡 Str: working (not near finished)

---

## Logging Library
(It's super basic)
How to use:
1. Create the log file beforehand or if you wan't to clear it(/create it) within code, use:
   ```c
   awlib_log_create("log_example.txt");
   ```
2. Then to log to the file, depending on which information you want included use:
 - **clean**
    ```c
    awlib_log("log_example.txt", "message=%d\n", 31415);
    ```
    output:
    ```c
    message=31415
    ```
    </br>
 - **timestamp**
    ```c
    awlib_log_t("log_example.txt", "message=%d\n", 92653);
    ```
    will output:
    ```c
    [2024-12-04 21:24:44]: message=92653
    ```
<br/>

<br/><br/>
## Input Library
This library only works on linux.

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
