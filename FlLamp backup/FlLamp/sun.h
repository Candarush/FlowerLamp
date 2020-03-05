#pragma once
#include <ctime>
#include "vector3.h"
#include "SolTrack.h"

using namespace V3;

namespace SunCalc
{
    class Sun
    {
    public:
        double altitude, azimuth;
        Vector3 direction;

        void CalculateSunPosition(time_t rawtime, double latitude, double longitude);
    };
}