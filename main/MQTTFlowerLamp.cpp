#include "MQTTFlowerLamp.h"

namespace MQTTFL
{
    void MQTTloop()
    {
        MQTTp->loop_forever();
    }

    void InitMQTT(MyMqttWrapper* MQTT)
    {
        mosqpp::lib_init();
        thread t(MQTTloop);
        t.detach();
    }

    void SendData(Lamp* lamp, Sun* sun, MyMqttWrapper* MQTT)
    {
        string sunAlt = "������ �������: " + to_string(sun->altitude);
        string sunAzi = "������ ������: " + to_string(sun->azimuth);
        string lampState = "����� ��������: " + to_string(lamp->GetState());
        MQTT->send_message(sunAlt.c_str());
        MQTT->send_message(sunAzi.c_str());
        MQTT->send_message(lampState.c_str());
    }
}
