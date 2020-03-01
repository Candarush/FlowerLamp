#pragma once

#include "C:\Program Files\mosquitto\devel\mosquittopp.h" 
#include <cstring>
#include <iostream>
#include <locale>

namespace MQTT
{
    class MyMqttWrapper : public mosqpp::mosquittopp
    {
    public:
        MyMqttWrapper(char const* id, const char* host, int port);

        void on_connect(int rc);
        void on_message(const struct mosquitto_message* message);
        bool send_message(const  char* message);
    };
}