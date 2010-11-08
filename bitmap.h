#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

namespace BE {
   class Bitmap {
      void init();

      public:
         Bitmap();
         Bitmap(const char *s);
         ~Bitmap();
         Bitmap &operator=(const Bitmap &b);

         bool loadBMP(const char *file);
         typedef unsigned char byte;
         byte *data;
         int width, height;
         int bpp;

         enum {FILE_NOT_BITMAP};

   };
}
#endif
