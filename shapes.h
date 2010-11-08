#ifndef TRIANGLES_H_
#define TRIANGLES_H_

#include "mesh.h"
#include "object.h"

namespace BE {
   class EquilateralTriangle : public Mesh {
      void build(const float &s, const Vector3 &color);
      public:
         EquilateralTriangle(const float &s);
         EquilateralTriangle(const float &s, const Vector3 &color);
   };
   
   class Quad : public Mesh {
   	  protected:
   	     void build(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, const Vector3 &color);
      public:
         Quad() {};
         Quad(const float &s);
         Quad(const float &s, const Vector3 &color);
   };
   
   class Cube : public Quad {
      public:
         Cube(const float &s);   	
         Cube(const float &s, const Vector3 &color);
   };
}

#endif /*TRIANGLES_H_*/
