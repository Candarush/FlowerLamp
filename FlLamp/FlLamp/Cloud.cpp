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

    void Cloud::WriteGraphicsData(std::string filename, std::ios_base::openmode mode)
    {
        std::ofstream fs;
        fs.open(filename, mode);
        if (!fs.is_open())
        {
            std::cout<<"Ошибка: не удалось открыть файл.";
        }
        fs << "#Cloud" << std::endl;
        fs << longitude - lon_width / 2 << " " << latitude - lat_width / 2 << " " << height << std::endl;
        fs << longitude + lon_width / 2 << " " << latitude - lat_width / 2 << " " << height << std::endl;
        fs << longitude + lon_width / 2 << " " << latitude + lat_width / 2 << " " << height << std::endl;
        fs << longitude - lon_width / 2 << " " << latitude + lat_width / 2 << " " << height << std::endl;
        fs << longitude - lon_width / 2 << " " << latitude - lat_width / 2 << " " << height << std::endl;
        fs << std::endl;

        fs.close();
    }
}
