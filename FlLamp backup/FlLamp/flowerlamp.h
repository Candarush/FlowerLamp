#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vector3.h"
#include "sun.h"
#include "Cloud.hpp"
#include "MyMQTTWrapper.h"

using namespace V3;
using namespace SunCalc;

namespace FlowerLamp
{
    class Lamp
    {
    private:
        bool isOn;

    public:
        double latitude;
        double longitude;

        Lamp();

        Lamp(double ilatitude, double ilongitude);

        bool IsUnderShadow(Cloud cloud, Sun* sun);

        void Update(time_t dateTime, Sun* sun, std::vector<Cloud*> clouds);

        bool GetState();

        void PrintState(time_t dateTime, Sun* sun, std::vector<Cloud*> clouds);
    };

    void FLWriteGraphicsData(Lamp* lamp, std::vector<Cloud*> clouds, Sun* sun);
}
