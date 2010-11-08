#ifndef VERTEX_H_
#define VERTEX_H_

#include "vector.h"

/*
 * 
 * Vertex related class
 * 
 */

namespace BE {

   class Vertex {
      /*
       *
       * A vertex is defined by:
       * 
       *    Position: x,y,z space coordinates (euclidean space)
       *    Normal: a normal vector (it must be calcultated) 
       *    Texture: x,y texture coordinates (0,0 means no texture)
       * 
       */
      
      void init();
      void init(const Vector3 &p);
      void init(const Vector3 &p, const Vector3 &n);
      void init(const Vector3 &p, const Vector3 &n, const Vector3 &c);
      void init(const Vector3 &p, const Vector3 &n, const Vector3 &c, const Vector2 &t);
            
      public:
         Vertex() {};
         Vertex(const float &px, const float &py, const float &pz);
         Vertex(const Vector3 &p);
         Vertex(const Vector3 &p, const Vector3 &n);
         Vertex(const Vector3 &p, const Vector3 &n, const Vector3 &c);
         Vertex(const Vector3 &p, const Vector3 &n, const Vector3 &c, const Vector2 &t);
         ~Vertex() {};

         Vector3 position; // Position
         Vector3 normal; // Normal
         Vector3 color;
         Vector2 texCoord; // Texture coordinates
   };
}

#endif /*VERTEX_H_*/
