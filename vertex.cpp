#include "vertex.h"

using namespace BE;

void Vertex::init(const Vector3 &p) {
   position = p;	
}

void Vertex::init(const Vector3 &p, const Vector3 &n) {
   init(p);
   normal = n;
}

void Vertex::init(const Vector3 &p, const Vector3 &n, const Vector3 &c) {
   init(p, n);
   color = c;
}

void Vertex::init(const Vector3 &p, const Vector3 &n, const Vector3 &c, const Vector2 &t) {
   init(p, n, c);
   texCoord = t;
}

Vertex::Vertex(const float &px, const float &py, const float &pz) {
   position.x = px;
   position.y = py;
   position.z = pz;	
}

Vertex::Vertex(const Vector3 &p) {
   init(p);
}

Vertex::Vertex(const Vector3 &p, const Vector3 &n) {
   init(p, n);
}

Vertex::Vertex(const Vector3 &p, const Vector3 &n, const Vector3 &c) {
   init(p, n);
   color = c;
}

Vertex::Vertex(const Vector3 &p, const Vector3 &n, const Vector3 &c, const Vector2 &t) {
   init(p, n, c);
   texCoord = t;
}
