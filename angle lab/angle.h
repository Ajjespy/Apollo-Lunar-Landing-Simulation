/*************************************************************
 * 1. Name:
 *      Brighton Gold
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      I got a weird error for the display. For some reason it would say it was wrong when it looked correct, but eventually I figured it out. Actually my fiance helped me solve it. 
 * 5. How long did it take for you to complete the assignment?
 *      4 and half hours. 
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

   double normalize(double radians)
   {
      return fmod(fmod(radians, TWO_PI) + TWO_PI, TWO_PI);
   }

   double convertToDegrees(double radians)
   {
      return normalize(radians) * (180 / M_PI);

   }

   double convertToRadians(double degrees)
   {
      double radians = degrees * (M_PI / 180);
      return normalize(radians);
   }


public:

   double getDegrees()
   {  
      return convertToDegrees(radians);
   }

   double getRadians()
   {
      return radians;
   }

   void setDegrees(double degrees)
   {
      radians = convertToRadians(degrees);
      this -> radians = normalize(radians);
   }

   void setRadians(double radians)
   {
      this -> radians = normalize(radians);
   }

   void display(std::ostream& out)
   {
      double degrees = getDegrees();
      out.setf(ios::fixed);     // "fixed" means don't use scientific notationa
      out.setf(ios::showpoint); // "showpoint" means always show the decimal point
      out.precision(1);         // Set the precision to 1 decimal place of accuracy.

      out << degrees << "degrees";
      
   }

   friend TestAngle;

};


