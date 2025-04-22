#!/bin/bash


echo "starting build"
g++ -Wall ../Implimnetations/GPIO.cpp task2.cpp -o  Task_2 -lpaho-mqtt3c -pthread
echo "build finished"
