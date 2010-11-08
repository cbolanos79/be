#include "texture.h"

using namespace BE;

Texture::Texture(const char *s) {
   bitmap = new Bitmap(s);
   bind();
   delete(bitmap);
}

Texture::Texture(const Bitmap &b) {
   bitmap = new Bitmap(b);
   bind();
   delete(bitmap);
}

void Texture::copy(const Texture &t) {
   bitmap = NULL;
   id = t.id;
}

Texture::Texture(const Texture &t) {
   copy(t);
}

Texture &Texture::operator=(const Texture &t) {
   copy(t);
   return *this;
}

bool Texture::bind() {
   if (bitmap->data == NULL)
      return false;

   glGenTextures(1, &id);
   glBindTexture(GL_TEXTURE_2D, id);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap->width, bitmap->height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap->data);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   return true;
}
