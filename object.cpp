#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <stdio.h>
#include <math.h>
#include "object.h"
#include "vector.h"
#include "scene.h"

#include <stdio.h>

using namespace BE;

void Object::init(const float &x, const float &y, const float &z) {
   _position.x = x;
   _position.y = y;
   _position.z = z;
}

Object::Object(const float &x, const float &y, const float &z) {
   setPosition(x, y, z);
}

Object::Object(const float &x, const float &y, const float &z, const int &meshId) {
   init(x, y, z);
   addMesh(meshId);
}

void Object::copy(const Object &o) {
   _meshes = o._meshes;
   _position = o._position;
   _angles = o._angles;
}

Object::Object(const Object &o) {
   copy(o);	
}

Object &Object::operator=(const Object &o) {
   copy(o);
   return *this;	
}

void Object::addMesh(const int &id) {
   _meshes.add(id);	
}

void Object::render() {
   Scene *s = Scene::instance();
   glColor3f(0.0f, 1.0f, 0.0f);
   glPushMatrix();
      glTranslatef(_position.x, _position.y, _position.z);
      glRotatef(_angles.x, 1.0f, 0.0f, 0.0f);
      glRotatef(_angles.y, 0.0f, 1.0f, 0.0f);
      for (int i=0; i<_meshes.getCount(); i++) {
             Mesh *m = &s->meshes[_meshes[i]];
         if (m->textureId>=0) {
            glBindTexture(GL_TEXTURE_2D, s->textures[m->textureId].id); 
         }
         glBegin(GL_TRIANGLES);
         for (int j=0; j<m->vertexs.getCount(); j++) {
            Vertex *v = &s->vertexs[m->vertexs[j]];
               glColor3f(v->color.x, v->color.y, v->color.z);
               if (m->textureId>=0)
                  glTexCoord2d(v->texCoord.x, v->texCoord.y);
               glNormal3f(v->normal.x, v->normal.y, v->normal.z);
               glVertex3f(v->position.x, v->position.y, v->position.z);
         }
         glEnd();
      }
   glPopMatrix();
}

void Object::setPosition(const float &x, const float &y, const float &z) {
   _position.x = x;
   _position.y = y;
   _position.z = z;
}

void Object::setXAngle(const float &angle) {
   _angles.x = angle;
}

void Object::setYAngle(const float &angle) {
   _angles.y = angle;	
}

void Object::setZAngle(const float &angle) {
   _angles.z = angle;	
}

void Object::setAngles(const float &x, const float &y, const float &z) {
   setXAngle(x);	
   setYAngle(y);	
   setZAngle(z);	
}

float &Object::getXAngle(void) {
   return _angles.x;
}

float &Object::getYAngle(void) {
   return _angles.y;
}

float &Object::getZAngle(void) {
   return _angles.z;
}

float Object::getXPos() {
   return _position.x;	
}

float Object::getYPos() {
   return _position.y;	
}

float Object::getZPos() {
   return _position.z;	
}

void Object::setXPos(float const &x) {
   _position.x = x;	
}

void Object::setYPos(float const &y) {
   _position.y = y;	
}

void Object::setZPos(float const &z) {
   _position.z = z;	
}

