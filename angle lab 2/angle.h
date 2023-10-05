/*************************************************************
 * 1. Name:
 *      Austin Jesperson
 * 2. Assignment Name:
 *      Practice 04: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle, now with contructors
 * 4. What was the hardest part? Be as specific as possible.
 *      It worked pretty well, originally i had the wrong project open so it wouldn't compile correctly and it took me a bit to realize what was wrong.
 * 5. How long did it take for you to complete the assignment?
 *      1 hour
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718
#define M_PI 3.14159265359

#include <string>
#include <cmath>    // for fmod()
#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include <iomanip> 
#include <sstream>

using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
private:
    double radians;

    double normalize(double radians) const
    {
        return fmod(fmod(radians, TWO_PI) + TWO_PI, TWO_PI);
    }

    double convertToDegrees(double radians) const
    {
        return normalize(radians) * (180 / M_PI);

    }

    double convertToRadians(double degrees) const
    {
        double radians = degrees * (M_PI / 180);
        return normalize(radians);
    }


public:

    // default constructor
    Angle()
    {
        radians = 0.0;
    }

    // copy constructor
    Angle(const Angle & rhs)
    {
        radians = rhs.radians;
    }

    // non-default constructor
    Angle(double degrees)
    {
        radians = convertToRadians(degrees);
    }

    double getDegrees() const
    {
        return convertToDegrees(radians);
    }

    double getRadians() const
    {
        return radians;
    }

    void setDegrees(double degrees)
    {
        radians = convertToRadians(degrees);
        this->radians = normalize(radians);
    }

    void setRadians(double radians)
    {
        this->radians = normalize(radians);
    }

    void display(std::ostream& out) const
    {
        double degrees = getDegrees();
        out.setf(ios::fixed);     // "fixed" means don't use scientific notationa
        out.setf(ios::showpoint); // "showpoint" means always show the decimal point
        out.precision(1);         // Set the precision to 1 decimal place of accuracy.

        out << degrees << "degrees";

    }

    friend TestAngle;

};


