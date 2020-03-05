#include "Lamp.hpp"

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

    bool Lamp::IsUnderShadow(ShadowCaster object, Vector3 sunDirection, float sunAlt)
    {
        Vector3 shadowOffset = (Vector3::Normalize(sunDirection)) * ((object.height) / sin(sunAlt));

        if (abs(longitude - (object.longitude + shadowOffset.x)) <= object.lon_width / 2 && abs(latitude - (object.latitude + shadowOffset.y)) <= object.lat_width / 2)
        {
            return true;
        }

        return false;
    }

//    for (std::vector<ShadowCaster*>::iterator it = objects.begin(); it != objects.end(); ++it)
//    {
//        if (sunAltitude > 0 && IsUnderShadow(*(*it), sunDirection, sunAltitude))
//        {
//            isOn = true;
//            return;
//        }
//    }

    void Lamp::CheckUnderShadow(Vector3 sunDirection, float sunAltitude, ShadowCaster object)
    {
        if (!isOn && IsUnderShadow(object, sunDirection, sunAltitude))
        {
            isOn = true;
            return;
        }
    }

    void Lamp::Update(float sunAltitude)
    {
        if (sunAltitude < 0)
        {
            isOn = true;
            return;
        }

        isOn = false;
    }

    bool Lamp::GetState()
    {
        return isOn;
    }

    void Lamp::WriteGraphicsData(std::string filename, std::ios_base::openmode mode)
    {
        std::ofstream fs;
        fs.open(filename, mode);
        if (!fs.is_open())
        {
            std::cout<<"Ошибка: не удалось открыть файл.";
        }
        fs << "#Flower" << std::endl;
        fs << longitude << " " << latitude << " 0.0" << std::endl;
        fs << longitude << " " << latitude << " 2.0" << std::endl;
        fs << std::endl;

        fs.close();
    }
}
