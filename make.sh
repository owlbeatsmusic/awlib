#!/bin/zsh

gcc -o main main.c awlib_log/log.c awlib_config/config.c awlib_str/str.c -lm
