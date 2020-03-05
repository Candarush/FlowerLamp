#include "flowerlamp.h"

namespace FlowerLamp
{
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
        std::cout << "Высота: " + std::to_string(sun->altitude) << std::endl;
        std::cout << "Азимут: " + std::to_string(sun->azimuth) << std::endl;
        std::cout << "Лампа включена: " << isOn << std::endl;
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
