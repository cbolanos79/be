#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
#include <stdlib.h>
#include "bitmap.h"

namespace BE {
   class Texture {
      void copy(const Texture &t);

      public:
         Texture() {};
         Texture(const char *s);
         Texture(const Bitmap &b);
         Texture(const Texture &s);
         Texture &operator=(const Texture &s);
         ~Texture() {};

         bool loadBMP(const char *s);
         bool bind();
         Bitmap *bitmap;
         GLuint id;

         enum {NO_BITMAP};
   };
}
#endif
