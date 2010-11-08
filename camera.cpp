#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "camera.h"

using namespace BE;

Camera::Camera() {
   init(0.0f, 0.0f, 0.0f);
   lookAhead();
}

Camera::Camera(const float &x, const float &y, const float &z) : Object(x, y, z) {
}

void Camera::render() {
   glTranslatef(-_position.x, -_position.y, -_position.z);
   glRotatef(_angles.x, 1.0, 0.0, 0.0);
   glRotatef(_angles.y, 0.0, 1.0, 0.0);
}

void Camera::resetLook() {
   _position.x = 0.0f;
   _position.y = 0.0f;
   _position.z = 0.0f;
   _angles.x = 0.0f;
   _angles.y = 0.0f;
}

void Camera::lookLeft() {
   _angles.y = -90.0f;
   resetLook();
}

void Camera::lookRight() {
   _angles.y = 90.0f;	
   resetLook();
}

void Camera::lookAhead() {
   _angles.y = 0.0f;	
   resetLook();
}

void Camera::lookRear() {
   _angles.y = 180.0f;
   resetLook();	
}

void Camera::zoomIn() {
   _position.z++;
}

void Camera::zoomOut() {
   _position.z--;
}

float Camera::getZoom() {
   return _position.z;	
}

void Camera::setZoom(const float &z) {
   _position.z = z;
}
