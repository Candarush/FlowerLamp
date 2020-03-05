# Имя компилятора
CC=g++

# Имя линковщика
LINKER=g++

detector: Vector3.o Soltrack.o Sun.o Lamp.o Cloud.o MosqMQTTWrapper.o MQTTFlowerLamp.o main.o 
	$(CC) -std=c++11 -I"/usr/local/include" -L"/usr/local/lib" -o detector detector main.o sun.o flowerlamp.o sun.o soltrack.o vector3.o mymqttwrapper.o -lmosquitto -lmosquittopp 
Vector3.o: Vector3.hpp
	$(LINKER) -c Vector3.cpp
main.o:
	$(LINKER) -c main.cpp
MQTTFlowerLamp.o: MQTTFlowerLamp.hpp
	$(LINKER) -c MQTTFlowerLamp.cpp
MosqMQTTWrapper.o: MosqMQTTWrapper.hpp
	$(LINKER) -c MosqMQTTWrapper.cpp
Lamp.o: Lamp.hpp
	$(LINKER) -c Lamp.cpp
Cloud.o: Cloud.hpp
	$(LINKER) -c Cloud.cpp
Sun.o: Sun.hpp
	$(LINKER) -c Sun.cpp
Soltrack.o: SolTrack.h
	$(LINKER) -o soltrack.o -c SolTrack.c
