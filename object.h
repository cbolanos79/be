#ifndef OBJECT_H_
#define OBJECT_H_

#include <GL/gl.h>
#include <list>
#include "vector.h"
#include "vertex.h"
#include "array.h"
#include "bitmap.h"
#include "mesh.h"

/*
 * 
 * Object related class
 * 
 */

using namespace std;
 
namespace BE {
   class Object {
      /*
       * An object is defined by:
       *    Vertexs: position, normal, texture, etc... (take a look en Vertex class)
       *    Angles: object has an angle for each axis (initially 0)
       *    Position: position on space (cartesian coordinates)
       * 
       */
       
   	  protected:
   	     // Meshes
         Array<int> _meshes; 
         
         // Position
         Vector3 _position; 
         
         // Angles
         Vector3 _angles;
         
         // Auxiliar functions
         void copy(const Object &o);
         void init(const float &x, const float &y, const float &z);
         
      public:
         Object() {};
         Object(const float &x, const float &y, const float &z);
         Object(const float &x, const float &y, const float &z, const int &meshId);
         Object(const Object &o);
         Object &operator=(const Object &o);
         virtual ~Object() {};
         
         void addMesh(const int &id);
         
         virtual void render();
         
         // Axis angles
         void setXAngle(const float &angle);
         void setYAngle(const float &angle);
         void setZAngle(const float &angle);
         void setAngles(const float &x, const float &y, const float &z);
         
         float &getXAngle(void);
         float &getYAngle(void);
         float &getZAngle(void);
         
         // Position
         void setPosition(const float &x, const float &y, const float &z);
         
         float getXPos();
         float getYPos();
         float getZPos();
         
         void setXPos(float const &x);
         void setYPos(float const &y);
         void setZPos(float const &z);
         
         // TODO: Texture related
           
   };

}

#endif /*OBJECT_H_*/
