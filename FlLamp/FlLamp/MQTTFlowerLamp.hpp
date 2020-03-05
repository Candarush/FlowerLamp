#pragma once

#include "MosqMQTTWrapper.hpp"
#include "Lamp.hpp"
#include "Cloud.hpp"
#include "Sun.hpp"
#include <thread>

using namespace SunCalc;
using namespace FlowerLamp;
using namespace MQTTW;

namespace MQTTFlower
{
    void MQTTloop(MQTTW::MosqMqttWrapper* MQTT);

    void InitMQTT(MQTTW::MosqMqttWrapper* MQTT);

    void SendData(Lamp* lamp, Sun* sun, MQTTW::MosqMqttWrapper* MQTT);
}
