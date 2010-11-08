#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"

/*
 * 
 * Virtual camera relates class
 * 
 */
 
namespace BE {
   class Camera : public Object {
      float _zoom; // Just zoom :P
      void resetLook(void); // Sets position to (0,0,0) and zoom to 0
   
      public:
         Camera();
         Camera(const float &x, const float &y, const float &z);
         void render(); // A camera doesn't render anything but it transforms model view matrix
         void lookLeft();
         void lookRight();
         void lookAhead();
         void lookRear();
         
         void zoomOut();
         void zoomIn();
         float getZoom();
         void setZoom(const float &z);
   };
}

#endif
