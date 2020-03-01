# Имя компилятора
CC=g++

# Имя линковщика
LINKER=g++

# Путь к директории заголовков mosquitto
MOSQPATH="C:\Program Files\mosquitto\devel"

# Путь к директории библиотеки mosquitto
MOSQLIB="C:\Program Files\mosquitto\devel"

detector: vector3.o soltrack.o sun.o flowerlamp.o MyMQTTWrapper.o MQTTFlowerLamp.o main.o 
	$(CC) -I$(MOSQPATH) -o detector main.o sun.o flowerlamp.o sun.o soltrack.o vector3.o mymqttwrapper.o -L$(MOSQLIB) -lmosquittopp 
vector3.o:
	$(LINKER) -c vector3.cpp
main.o:
	$(LINKER) -c main.cpp
MQTTFlowerLamp.o:
	$(LINKER) -c MQTTFlowerLamp.cpp
MyMQTTWrapper.o:
	$(LINKER) -c MyMQTTWrapper.cpp
flowerlamp.o:
	$(LINKER) -c flowerlamp.cpp
sun.o:
	$(LINKER) -c sun.cpp
soltrack.o:
	$(LINKER) -o soltrack.o -c SolTrack.c