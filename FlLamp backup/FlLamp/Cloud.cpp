#include "Cloud.hpp"

namespace FlowerLamp
{
    Cloud::Cloud()
    {
        latitude = 0;
        longitude = 0;
        height = 0;
        lon_width = 0;
        lat_width = 0;
    }

    Cloud::Cloud(double ilongitude, double ilatitude, double ix_width, double iy_width, double iheight)
    {
        latitude = ilatitude;
        longitude = ilongitude;
        height = iheight;
        lon_width = ix_width;
        lat_width = iy_width;
    }

    void Cloud::Move(double ilongitude, double ilatitude)
    {
        latitude += ilatitude;
        longitude += ilongitude;
    }

    Vector3 Cloud::GetShadowOffset(Vector3 sunDirection, float sunAlt)
    {
        double distanceToCloud = (height) / sin(sunAlt);
        Vector3 vecToCloud = (Vector3::Normalize(sunDirection)) * distanceToCloud;
        Vector3 offset = Vector3(-vecToCloud.x, -vecToCloud.y, 0);
        return offset;
    }
}
