#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include "Vector3.hpp"

using namespace V3;

namespace FlowerLamp
{
    class Lamp
    {
    public:
        
        double latitude;
        double longitude;
        
        class ShadowCaster
        {
            public:
            double latitude;
            double longitude;
            double height;
            double lon_width;
            double lat_width;
            ShadowCaster(double lat, double lon, double h, double lon_w, double lat_w)
            {
                latitude = lat;
                longitude = lon;
                height = h;
                lon_width = lon_w;
                lat_width = lat_w;
            }
        };

        Lamp();

        Lamp(double ilatitude, double ilongitude);

        void CheckUnderShadow(Vector3 sunDirection, float sunAltitude, ShadowCaster object);
        
        void Update(float sunAltitude);

        bool GetState();
        
        void WriteGraphicsData(std::string filename, std::ios_base::openmode mode);
        
    private:
        bool isOn;
        
        bool IsUnderShadow(ShadowCaster object, Vector3 sunDiretion, float sunAlt);
    };

}
