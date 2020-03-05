#include "MQTTFlowerLamp.hpp"
#include <thread>
#include <string>

namespace MQTTFlower
{
    void MQTTloop(MosqMqttWrapper* MQTT)
    {
        MQTT->loop_forever();
    }

    void InitMQTT(MosqMqttWrapper* iMQTT)
    {
        mosqpp::lib_init();
        std::thread t(MQTTloop,iMQTT);
        t.detach();
    }

    void SendData(Lamp* lamp, Sun* sun, MosqMqttWrapper* MQTT)
    {
        std::string sunAlt = "Высота: " + std::to_string(sun->altitude);
        std::string sunAzi = "Азимут: " + std::to_string(sun->azimuth);
        std::string lampState = "Лампа включена: " + std::to_string(lamp->GetState());
        MQTT->send_message(sunAlt.c_str());
        MQTT->send_message(sunAzi.c_str());
        MQTT->send_message(lampState.c_str());
    }
}
