#!/bin/bash


echo "starting build"
g++ -Wall ../Implimnetations/AnalogIn.cpp task1.cpp -o Task_1 -lpaho-mqtt3c
echo "build finished"
