#include "MyMQTTWrapper.h"

using namespace std;

namespace MQTT
{
    MyMqttWrapper::MyMqttWrapper(const char* id, const char* host, int port) : mosquittopp(id)
    {
        int keepalive = 60;
        connect(host, port, keepalive);
    };

    void MyMqttWrapper::on_connect(int rc)
    {
        if (rc == 0)
        {
            subscribe(NULL, "M30-212B-18/Game");
        }
    };

    void MyMqttWrapper::on_message(const struct mosquitto_message* message) {
        setlocale(LC_CTYPE, "rus");
        if (!strcmp(message->topic, "M30-212B-18/Game")) {
            cout << message->payload << endl;
        }
    };

    bool MyMqttWrapper::send_message(const  char* message)
    {
        publish(NULL, "M30-212B-18/Game", (int)strlen(message), message, 2, false);
        return true;
    };
}