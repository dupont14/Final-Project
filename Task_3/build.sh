#!/bin/bash

echo "starting build"

config-pin P9.22 pwm
g++ -Wall ../Implimnetations/GPIO.cpp ../Implimnetations/PWM.cpp ../Implimnetations/util.cpp  task3.cpp -o Task_3 -lpaho-mqtt3c -pthread
echo "build finished"
