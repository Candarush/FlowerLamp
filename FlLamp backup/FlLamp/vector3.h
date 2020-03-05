#pragma once

namespace V3
{
    class Vector3
    {
    public:
        double x, y, z;

        Vector3(double ix, double iy, double iz);

        Vector3();

        Vector3 operator -(Vector3 b);

        Vector3 operator *(double l);

        static double Length(Vector3 v);

        static double Dot(Vector3 a, Vector3 b);

        static Vector3 Normalize(Vector3 a);

        static double Angle(Vector3 a, Vector3 b);

        static Vector3 FromAltAzi(double altitude, double azimuth);
    };
}