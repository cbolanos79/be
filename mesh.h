#ifndef MESH_H_
#define MESH_H_

#include <GL/gl.h>
#include "vector.h"
#include "vertex.h"
#include "array.h"
#include "bitmap.h"

/*
 * 
 * Mesh related class
 * 
 */

using namespace std;
 
namespace BE {
   class Mesh {
   	  void init();
      void copy(const Mesh &m);
   	  
      public:
      	 Mesh();
      	 Mesh(const Mesh &m);
         Mesh &operator=(const Mesh &m);
         ~Mesh() {};
         void setTexture(const int &id);

         int textureId;
         Array<int> vertexs;
   };
}

#endif /*MESH_H_*/
