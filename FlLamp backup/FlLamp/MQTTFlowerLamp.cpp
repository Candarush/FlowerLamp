#include "MQTTFlowerLamp.h"

namespace MQTTFL
{
    void MQTTloop(MyMqttWrapper* MQTT)
    {
        MQTT->loop_forever();
    }

    void InitMQTT(MyMqttWrapper* iMQTT)
    {
        mosqpp::lib_init();
        thread t(MQTTloop,iMQTT);
        t.detach();
    }

    void SendData(Lamp* lamp, Sun* sun, MyMqttWrapper* MQTT)
    {
        string sunAlt = "Высота: " + to_string(sun->altitude);
        string sunAzi = "Азимут: " + to_string(sun->azimuth);
        string lampState = "Лампа включена: " + to_string(lamp->GetState());
        MQTT->send_message(sunAlt.c_str());
        MQTT->send_message(sunAzi.c_str());
        MQTT->send_message(lampState.c_str());
    }
}
