#include <iostream>
#include <vector>
#include "MQTTFlowerLamp.hpp"

using namespace std;
using namespace MQTTFlower;

int main()
{
    time_t time = std::time(0);

    Sun* sun = new Sun();
    Lamp* lamp = new Lamp(56, 37);
    std::vector<Cloud*> clouds;

    clouds.push_back(new Cloud(50,20,50,50,10));
    clouds.push_back(new Cloud(80,10,-25,30,15));

    sun->CalculateSunPosition(lamp->longitude, lamp->latitude, time);
    lamp->Update(sun->altitude);
    for (std::vector<Cloud*>::iterator it = clouds.begin(); it != clouds.end(); ++it)
    {
        FlowerLamp::Lamp::ShadowCaster cloudToObj((*it)->longitude, (*it)->latitude, (*it)->lon_width, (*it)->lat_width, (*it)->height);
        lamp->CheckUnderShadow(sun->direction, sun->altitude, cloudToObj);
    }

    MosqMqttWrapper* MyMQTT = new MosqMqttWrapper("flower", "test.mosquitto.org", 1883);
    InitMQTT(MyMQTT);

    SendData(lamp, sun, MyMQTT);

    delete lamp;
    clouds.clear();
}
