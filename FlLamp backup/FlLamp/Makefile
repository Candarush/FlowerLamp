# Имя компилятора
CC=g++

# Имя линковщика
LINKER=g++

detector: vector3.o soltrack.o sun.o flowerlamp.o MyMQTTWrapper.o MQTTFlowerLamp.o main.o 
	$(CC) -std=c++11 -o detector detector main.o sun.o flowerlamp.o sun.o soltrack.o vector3.o mymqttwrapper.o -lmosquitto -lmosquittopp
vector3.o: vector3.h
	$(LINKER) -c vector3.cpp
main.o:
	$(LINKER) -c main.cpp
MQTTFlowerLamp.o: MQTTFlowerLamp.h
	$(LINKER) -c MQTTFlowerLamp.cpp
MyMQTTWrapper.o: MyMQTTWrapper.h
	$(LINKER) -c MyMQTTWrapper.cpp
flowerlamp.o: flowerlamp.h
	$(LINKER) -c flowerlamp.cpp
sun.o: sun.h
	$(LINKER) -c sun.cpp
soltrack.o: SolTrack.h
	$(LINKER) -o soltrack.o -c SolTrack.c
