#ifndef VECTOR_H_
#define VECTOR_H_

#include <math.h>

/*
 * 
 * Geometric vector relatex classes
 * 
 */

namespace BE {

   class Vector2 {
   	  /*
   	   * 
   	   * 2D vecfloator
   	   * 
   	   */
      
      public:
         float x, y;
         Vector2() {};
         Vector2(const float &x1, const float &y1);
         Vector2(const Vector2 &v);
         Vector2 &operator*(const Vector2 &v);
         ~Vector2() {};
         void normalize();
   };

	
   class Vector3 {
   	  /*
   	   * 
   	   * 3D vecor
   	   * 
   	   */
      
      public:
   	 int foo;
         float x, y, z;
         Vector3() {};
         Vector3(const float &x1, const float &y1, const float &z1);
         Vector3(const Vector3 &v);
         Vector3 &operator=(const Vector3 &v);
         Vector3 operator*(const Vector3 &v) const;
         Vector3 operator+(const Vector3 &v) const;
         Vector3 operator/(const float &f) const;
         ~Vector3() {};
         void normalize();
         
         enum {DIVISION_BY_ZERO};
         
   };
   
}
#endif /*VECTOR_H_*/
