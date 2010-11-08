#include "vector.h"

using namespace BE;

/*
 * 
 * Vector2
 * 
 */
Vector2::Vector2(const float &x1, const float &y1) {
   x = x1;
   y = y1;
}

Vector2::Vector2(const Vector2 &v) {
   x = v.x;
   y = v.y;
}

Vector2 &Vector2::operator*(const Vector2 &v) {
  x = (x * v.y);
  y = (-x * v.x);
  return *this;
}

void Vector2::normalize() {
   float m;
   m = sqrt((x*x) + (y*y));
   x = x/m;
   y = y/m;
}   

/*
 * 
 * Vector3
 * 
 */

Vector3::Vector3(const float &x1, const float &y1, const float &z1) {
   x = x1;
   y = y1;
   z = z1;	
}

Vector3::Vector3(const Vector3 &v) {
   x = v.x;
   y = v.y;
   z = v.z;	
}


Vector3 &Vector3::operator=(const Vector3 &v) {
   x = v.x;
   y = v.y;
   z = v.z;
   return *this;	
}
 
Vector3 Vector3::operator*(const Vector3 &v) const {
   Vector3 vaux = *this;
   vaux.x = (y * v.z) - (z * v.y);
   vaux.y = (z * v.x) - (x * v.z);
   vaux.z = (x * v.y) - (y * v.x);

   return vaux;
}

Vector3 Vector3::operator+(const Vector3 &v) const {
   Vector3 vaux = *this;
   vaux.x = x + v.x;
   vaux.y = x + v.y;
   vaux.z = x + v.z;

   return vaux;
	
}

Vector3 Vector3::operator/(const float &f) const {
   if (f - 0 < 0.001)
      throw DIVISION_BY_ZERO;
      
   Vector3 vaux = *this;
   vaux.x /= f;
   vaux.y /= f;
   vaux.z /= f;
   
   return vaux;
}
 
void Vector3::normalize() {
   float m;
   m = sqrt((x*x) + (y*y) + (z*z));
   x = x/m;
   y = y/m;
   z = z/m;	
}   
