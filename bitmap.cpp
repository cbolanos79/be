#include <stdio.h>
#include <string.h>
#include "bitmap.h"

using namespace BE;

void Bitmap::init() {
   data = NULL;
   width = 0;
   height = 0;
   bpp = 0;
}

Bitmap::Bitmap() {
   init();
}

Bitmap::Bitmap(const char *s) {
   // FIXME: check type by extension
   if (!loadBMP(s))
      throw FILE_NOT_BITMAP;
}

Bitmap::~Bitmap() {
   if (data != NULL)
      delete[](data);
}

Bitmap &Bitmap::operator=(const Bitmap &b) {
   width = b.width;
   height = b.height;
   bpp = b.bpp;

   if (data != NULL) {
      delete[](data);
   }     
   if (b.data != NULL) {
      data = new byte[width*height*3];
      memcpy(data, b.data, b.width*b.height*3);
   } else
      data = NULL;
   return *this;
}

bool Bitmap::loadBMP(const char *file) {
   FILE *f = fopen(file, "rb");
   if (f == NULL)
      return false;

   char s[54];
   fread(s, sizeof(char)*54, 1, f);

   // Not a BMP file
   if ((s[0] != 'B') && (s[1] != 'M'))
      return false;

   width = *(int *)(s+18);
   height = *(int *)(s+22);
   bpp = *(int *)(s+28);
   int compression = *(int *)(s+30);
   if (compression)
      return false;

   data = new byte[width*height*3];
   fread(data, width*height*3, 1, f);
   fclose(f);
   return true;
}

