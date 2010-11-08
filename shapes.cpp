#include <math.h>
#include "object.h"
#include "shapes.h"
#include "scene.h"

using namespace BE;

void EquilateralTriangle::build(const float &s, const Vector3 &color) {
   float sm = s/2.0, y=(s*(sqrt(3)/2));
   Vector3 u(-sm, -y/2, 0.0f), v(sm, -y/2, 0.0f), w(0, y/2, 0.0f);
   
   // Normal is always orthogonal on Z axis
   Vector3 normal(0.0f, 0.0f, 1.0f);
   
   Scene *sc = Scene::instance();
   vertexs.add(sc->vertexs.add(Vertex(u, normal, color, Vector2(0, 0))));
   vertexs.add(sc->vertexs.add(Vertex(v, normal, color, Vector2(1, 0))));
   vertexs.add(sc->vertexs.add(Vertex(w, normal, color, Vector2(1, 1))));
	
}
EquilateralTriangle::EquilateralTriangle(const float &s) : Mesh() {
   build(s, Vector3(1.0f, 1.0f, 1.0f));
}

EquilateralTriangle::EquilateralTriangle(const float &s, const Vector3 &color) : Mesh() {
   build(s, color);
}

void Quad::build(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, const Vector3 &color) {
   /* Quad is generated using four triangles and drawing on ANTI CLOCKWISE
    * 
    * v4       v3
    * +--------+
    * |\      /|
    * | \    / |
    * |  \  /  |
    * |   \/   |
    * |   /\   |
    * |  /  \  |
    * | /    \ |
    * |/      \|
    * +--------+
    * v1       v2
    * 
    */
    
   Vector3 normal = Vector3(v1) * Vector3(v2);
   normal.normalize();
   
   Vector3 center((v1.x+v3.x)/2, (v1.y+v3.y)/2, (v1.z+v2.z)/2);

   Scene *sc = Scene::instance();
   
   // Left
   vertexs.add(sc->vertexs.add(Vertex(v1, normal, color, Vector2(0.0f, 0.0f))));
   vertexs.add(sc->vertexs.add(Vertex(center, normal, color, Vector2(0.5f, 0.5f))));
   vertexs.add(sc->vertexs.add(Vertex(v4, normal, color, Vector2(0.0f, 1.0f))));
   
   // Bottom
   vertexs.add(sc->vertexs.add(Vertex(v1, normal, color, Vector2(0.0f, 0.0f))));
   vertexs.add(sc->vertexs.add(Vertex(v2, normal, color, Vector2(0.0f, 1.0f))));
   vertexs.add(sc->vertexs.add(Vertex(center, normal, color, Vector2(0.5f, 0.5f))));

   // Right
   vertexs.add(sc->vertexs.add(Vertex(v2, normal, color, Vector2(1.0f, 0.0f))));
   vertexs.add(sc->vertexs.add(Vertex(v3, normal, color, Vector2(1.0f, 1.0f))));
   vertexs.add(sc->vertexs.add(Vertex(center, normal, color, Vector2(0.5f, 0.5f))));

   // Top
   vertexs.add(sc->vertexs.add(Vertex(center, normal, color, Vector2(0.5f, 0.5f))));
   vertexs.add(sc->vertexs.add(Vertex(v3, normal, color, Vector2(1.0f, 1.0f))));
   vertexs.add(sc->vertexs.add(Vertex(v4, normal, color, Vector2(0.0f, 1.0f))));
}

Quad::Quad(const float &s) : Mesh() {
   float m = s/2;
   build(Vector3(-m, -m, 0.0f),\
         Vector3(m, -m, 0.0f),\
         Vector3(m, m, 0.f),\
         Vector3(-m, m, 0.f),
         Vector3(1.0f, 1.0f, 1.0f));
}

Quad::Quad(const float &s, const Vector3 &color) : Mesh() {
   float m = s/2;
   build(Vector3(-m, -m, 0.0f),\
         Vector3(m, -m, 0.0f),\
         Vector3(m, m, 0.f),\
         Vector3(-m, m, 0.f),
         color);
}

Cube::Cube(const float &s) : Quad() {
   float m = s/2;
   
   // Front
   build(Vector3(-m, -m, m),\
         Vector3(m, -m, m),\
         Vector3(m, m, m),\
         Vector3(-m, m, m),\
         Vector3(1.0f, 1.0f, 1.0f));
         
   // Back
   build(Vector3(-m, -m, -m),\
         Vector3(m, -m, -m),\
         Vector3(m, m, -m),\
         Vector3(-m, m, -m),\
         Vector3(1.0f, 1.0f, 1.0f));
         
   // Top
   build(Vector3(-m, m, m),\
         Vector3(m, m, m),\
         Vector3(m, m, -m),\
         Vector3(-m, m, -m),\
         Vector3(1.0f, 1.0f, 1.0f));
         
   // Bottom
   build(Vector3(-m, -m, m),\
         Vector3(m, -m, m),\
         Vector3(m, -m, -m),\
         Vector3(-m, -m, -m),\
         Vector3(1.0f, 1.0f, 1.0f));

   // Left
   build(Vector3(-m, -m, -m),\
         Vector3(-m, -m, m),\
         Vector3(-m, m, m),\
         Vector3(-m, m, -m),\
         Vector3(1.0f, 1.0f, 1.0f));

   // Right
   build(Vector3(m, -m, -m),\
         Vector3(m, -m, m),\
         Vector3(m, m, m),\
         Vector3(m, m, -m),\
         Vector3(1.0f, 1.0f, 1.0f));

}
