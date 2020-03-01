#include "sun.h"

namespace SunCalc
{
    void Sun::CalculateSunPosition(time_t rawtime, double latitude, double longitude)
    {
        Time time;
        tm* tmp = gmtime(&rawtime);
        time.year = tmp->tm_year + 1900;
        time.month = tmp->tm_mon + 1;
        time.day = tmp->tm_mday + 1;
        time.hour = tmp->tm_hour - 3;
        time.minute = tmp->tm_min;
        time.second = tmp->tm_sec;
        Location sunLoc;
        sunLoc.latitude = latitude;
        sunLoc.longitude = longitude;
        Position outPos;
        SolTrack(time, sunLoc, &outPos, 1, 1, 1, 0);

        altitude = outPos.altitude;
        azimuth = outPos.azimuthRefract;
        direction = Vector3::FromAltAzi(altitude, azimuth);
    }
}