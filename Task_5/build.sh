#!/bin/bash


echo "starting build"
config-pin P9.22 gpio
g++ -Wall ../Implimnetations/GPIO.cpp task5.cpp -o  Task_5 -lpaho-mqtt3c -pthread
echo "build finished"
