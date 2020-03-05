#pragma once
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include "Vector3.hpp"
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
        void WriteGraphicsData(float lon, float lat, std::string filename, std::ios_base::openmode mode);
        
    };
}
