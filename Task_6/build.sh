#!/bin/bash


echo "starting build"
config-pin P9.22 gpio
g++ -Wall ../Implimnetations/derek_LED.cpp task6.cpp -o  Task_6 -lpaho-mqtt3c -pthread
echo "build finished"
