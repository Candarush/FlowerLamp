#include <iostream>
#include <vector>
#include "MQTTFlowerLamp.h"

using namespace MQTTFL;
using namespace std;

int main()
{
    time_t time = std::time(0);

    Sun* sun = new Sun();
    Lamp* lamp = new Lamp(56, 37);
    std::vector<Cloud*> clouds;

    clouds.push_back(new Cloud(50,20,50,50,10));

    lamp->Update(time, sun, clouds);

    FLWriteGraphicsData(lamp, clouds, sun);

    MyMqttWrapper* MyMQTT = new MyMqttWrapper("flower", "test.mosquitto.org", 1883);
    InitMQTT(MyMQTT);

    SendData(lamp, sun, MyMQTT);

    delete lamp;
    clouds.clear();
}
