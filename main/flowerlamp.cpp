#include "flowerlamp.h"

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

    Vector3 Cloud::GetShadowOffset(Sun* sun)
    {
        double distanceToCloud = (height) / sin(sun->altitude);
        Vector3 vecToCloud = (Vector3::Normalize(sun->direction)) * distanceToCloud;
        Vector3 offset = Vector3(-vecToCloud.x, -vecToCloud.y, 0);
        return offset;
    }

    
    Lamp::Lamp()
    {
        latitude = 0;
        longitude = 0;
    }

    Lamp::Lamp(double ilatitude, double ilongitude)
    {
        latitude = ilatitude;
        longitude = ilongitude;
    }

    bool Lamp::IsUnderShadow(Cloud cloud, Sun* sun)
    {
        Vector3 shadowOffset = cloud.GetShadowOffset(sun);

        if (abs(longitude - (cloud.longitude + shadowOffset.x)) <= cloud.lon_width / 2 && abs(latitude - (cloud.latitude + shadowOffset.y)) <= cloud.lat_width / 2)
        {
            return true;
        }

        return false;
    }

    void Lamp::Update(time_t dateTime, Sun* sun, std::vector<Cloud*> clouds)
    {
        sun->CalculateSunPosition(dateTime, latitude, longitude);

        for (std::vector<Cloud*>::iterator it = clouds.begin(); it != clouds.end(); ++it)
        {
            if (sun->altitude > 0 && IsUnderShadow(*(*it), sun))
            {
                isOn = true;
                return;
            }
        }

        if (sun->altitude > 0)
        {
            isOn = false;
            return;
        }

        isOn = true;
    }

    bool Lamp::GetState()
    {
        return isOn;
    }

    void Lamp::PrintState(time_t dateTime, Sun* sun, std::vector<Cloud*> clouds)
    {
        Update(dateTime, sun, clouds);
        std::cout << "Высота столнца: " + std::to_string(sun->altitude) << std::endl;
        std::cout << "Азимут солнца: " + std::to_string(sun->azimuth) << std::endl;
        std::cout << "Лампа работает: " << isOn << std::endl;
    }

    void FLWriteGraphicsData(Lamp* lamp, std::vector<Cloud*> clouds, Sun* sun)
    {
        std::ofstream fs;
        fs.open("graphicsdata.d");
        fs << "#X  Y  Z" << std::endl;
        fs << "#Flower" << std::endl;
        fs << lamp->longitude << " " << lamp->latitude << " 0.0" << std::endl;
        fs << lamp->longitude << " " << lamp->latitude << " 2.0" << std::endl;
        fs << std::endl;

        fs << "#SunVector" << std::endl;
        fs << lamp->longitude << " " << lamp->latitude << " 0.0" << std::endl;
        fs << lamp->longitude + sun->direction.x * 50 << " " << lamp->latitude + sun->direction.y * 50 << " " << sun->direction.z * 50 << std::endl;
        fs << std::endl;

        for (std::vector<Cloud*>::iterator it = clouds.begin(); it != clouds.end(); ++it) {
            fs << "#Cloud" << std::endl;
            fs << (*it)->longitude - (*it)->lon_width / 2 << " " << (*it)->latitude - (*it)->lat_width / 2 << " " << (*it)->height << std::endl;
            fs << (*it)->longitude + (*it)->lon_width / 2 << " " << (*it)->latitude - (*it)->lat_width / 2 << " " << (*it)->height << std::endl;
            fs << (*it)->longitude + (*it)->lon_width / 2 << " " << (*it)->latitude + (*it)->lat_width / 2 << " " << (*it)->height << std::endl;
            fs << (*it)->longitude - (*it)->lon_width / 2 << " " << (*it)->latitude + (*it)->lat_width / 2 << " " << (*it)->height << std::endl;
            fs << (*it)->longitude - (*it)->lon_width / 2 << " " << (*it)->latitude - (*it)->lat_width / 2 << " " << (*it)->height << std::endl;
            fs << std::endl;
        }

        fs.close();
    }
}