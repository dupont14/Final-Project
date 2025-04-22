#!/bin/bash

echo "starting build"
config-pin P9.30 gpio_pu
g++ -Wall ../Implimnetations/GPIO.cpp  task4.cpp -o Task_4 -lpaho-mqtt3c -pthread
echo "build finished"


