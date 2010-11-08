#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include "array.h"
#include "stage.h"
#include "scene.h"
#include "texture.h"
#include "mesh.h"
#include "shapes.h"

using namespace BE;

Stage::Stage(const int &rows, const int &cols, const char *cells) {
   _rows = rows;
   _cols = cols;
   int size = _rows * _cols;
   //_cells = new char[size];
   	
   //strcpy(_cells, cells);
   
   Scene *sc = Scene::instance();
   Texture t("sand.bmp");
   sc->textures.add(t);
   Mesh m = Cube(5);
   m.setTexture(0);
   sc->meshes.add(m);
   

   // Generate objects for stage
   int x=0, z=0;
   for (int i=0; i<size; i++) {
   	  x = (i%_cols);
   	  if (x==0) {
   	     z++;
   	  }
      Object o;
      o.setPosition(x*5,0,z*5);
      o.setAngles(0,0,0);
      if (cells[i] != ' ')
         o.addMesh(0);
      sc->objects.add(o);
      
   }
}


void Stage::render() {
   for (int i=0; i<_objects.getCount(); i++)
      _objects[i].render();

}
