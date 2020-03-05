#pragma once

#include "MyMQTTWrapper.h"
#include "flowerlamp.h"
#include <thread>

using namespace SunCalc;
using namespace FlowerLamp;
using namespace std;
using namespace mosqpp;

namespace MQTTFL
{
    void MQTTloop(MyMqttWrapper* MyMQTT);

    void InitMQTT(MyMqttWrapper* MQTT);

    void SendData(Lamp* lamp, Sun* sun, MyMqttWrapper* MQTT);
}
