#include <cmath>
#include "Vector3.hpp"

namespace V3
{
    Vector3::Vector3(double ix, double iy, double iz)
    {
        x = ix;
        y = iy;
        z = iz;
    }
    Vector3::Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3 Vector3::operator -(Vector3 b)
    {
        return Vector3(x - b.x, y - b.y, z - b.z);
    }

    Vector3 Vector3::operator *(double l)
    {
        return Vector3(x * l, y * l, z * l);
    }

    double Vector3::Length(Vector3 v)
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    double Vector3::Dot(Vector3 a, Vector3 b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    Vector3 Vector3::Normalize(Vector3 a)
    {
        double length = Length(a);
        return Vector3(a.x / length, a.y / length, a.z / length);
    }

    double Vector3::Angle(Vector3 a, Vector3 b)
    {
        return Dot(a, b) / (Length(a) * Length(b));
    }

    Vector3 Vector3::FromAltAzi(double altitude, double azimuth)
    {
        const double Deg2Rad = 3.14159265358979323846 / 180.0;
        double z = sin(altitude * Deg2Rad);
        double hyp = cos(altitude * Deg2Rad);
        double y = hyp * cos(azimuth * Deg2Rad);
        double x = hyp * sin(azimuth * Deg2Rad);
        return Vector3(x, y, z);
    }
}
