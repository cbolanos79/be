#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "object.h"
#include "vector.h"
#include "mesh.h"

using namespace BE;

void Mesh::copy(const Mesh &m) {
   vertexs = m.vertexs;
   textureId = m.textureId;
}

void Mesh::init() {
   textureId = -1;	
}
Mesh::Mesh() {
   init();
}

Mesh::Mesh(const Mesh &m) {
   copy(m);	
}

Mesh &Mesh::operator=(const Mesh &m) {
   copy(m);
   return *this;
}


void Mesh::setTexture(const int &id) {
   textureId = id;
}

