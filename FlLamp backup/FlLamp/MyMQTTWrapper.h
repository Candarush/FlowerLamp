#ifndef MYWQTTWRAPPER_H
#define MYWQTTWRAPPER_H

#include "/usr/local/include/mosquittopp.h"
#include <cstring>
#include <iostream>

extern std::vector<std::string> mymessages;

class MyMqttWrapper : public mosqpp::mosquittopp
{
    public:
    MyMqttWrapper(char const  *id, const char *host, int port);

    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);
    bool send_message(const  char * message);
    void on_subcribe(int mid, int qos_count, const int *granted_qos);
};
#endif
