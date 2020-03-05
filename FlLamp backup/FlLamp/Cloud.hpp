#pragma once
#include "vector3.h"

using namespace V3;

namespace FlowerLamp
{
    class Cloud
    {
        public:
            double latitude;
            double longitude;
            double lon_width, lat_width, height;

        Cloud();

        Cloud(double ilongitude, double ilatitude, double ix_width, double iy_width, double iheight);

        void Move(double ilongitude, double ilatitude);
        
        Vector3 GetShadowOffset(Vector3 sunDirection, float sunAlt);
    };

}
