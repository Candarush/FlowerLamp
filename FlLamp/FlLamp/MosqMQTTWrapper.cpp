#include "/usr/local/include/mosquittopp.h"
#include "MosqMQTTWrapper.hpp"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <locale>
#include <vector>
#include <string>

namespace MQTTW
{
    MosqMqttWrapper::MosqMqttWrapper(const char *id, const char *host, int port) : mosquittopp(id)
    {
        int keepalive = 60;
        connect(host, port, keepalive);
        printf("Создал MQTTwrapper.\n");
    };

    void MosqMqttWrapper::on_connect(int rc)
    {
        if (rc == 0)
        {
            subscribe(NULL, "M30-212B-18/FlowerLamp");
        }
    }

    void MosqMqttWrapper::on_message(const struct mosquitto_message *message){
        setlocale(LC_CTYPE, "rus");
        if(!strcmp(message->topic, "M30-212B-18/FlowerLamp")){
            std::cout<<message->payload<<std::endl;
        }
    };

    bool MosqMqttWrapper::send_message(const  char * message)
    {
        int ret = publish(NULL,"M30-212B-18/Game",(int)strlen(message),message,2,false);
        return ( ret == MOSQ_ERR_SUCCESS );
    }
}
