#pragma once
#include "Vector3.hpp"
#include <fstream>
#include <iostream>

using namespace V3;

namespace FlowerLamp
{
    class Cloud
    {
    public:
        double latitude;
        double longitude;
        double lon_width;
        double lat_width;
        double height;
        
        Cloud();
        Cloud(double ilongitude, double ilatitude, double ix_width, double iy_width, double iheight);

        void Move(double ilongitude, double ilatitude);
        void WriteGraphicsData(std::string filename, std::ios_base::openmode mode);
        
        
    };

}
