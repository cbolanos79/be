#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

#ifdef _WIN32
 #include <windows.h>
#else
 #include <unistd.h>
#endif
#include <time.h>

#include "window.h"
#include "scene.h"
#include "camera.h"
#include "vector.h"
#include "stage.h"
#include "shapes.h"
#include "vertex.h"
#include "mesh.h"
#include "texture.h"
#include "stage.h"

#include <stdio.h>

using namespace BE;

Object *co;
bool cameraMode;

void process(int timer) {
   glutTimerFunc(33, process, 0);
   glutPostRedisplay();	
}

void display() {
   Scene *s = Scene::instance();
   /*
   for (int i=0; i<s->objects.getCount(); i++) {
      s->objects[i].setXAngle(s->objects[i].getXAngle()+0.5);
      s->objects[i].setYAngle(s->objects[i].getYAngle()+0.5);
   }*/
   s->stage->render();
   s->render();
   glutSwapBuffers();
}

void reshape(int w, int h) {
   Scene *s = Scene::instance();
   s->loadProjection(w, h); 
   glMatrixMode (GL_MODELVIEW);	
}

void processNormalKeys(unsigned char key, int x, int y) {
   Scene *s = Scene::instance();
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'a':
         co->setXPos(co->getXPos()-1.0f);
         break;
      case 'd':
         co->setXPos(co->getXPos()+1.0f);
         break;
      case 'w':
         co->setYPos(co->getYPos()+1.0f);
         break;
      case 's':
         co->setYPos(co->getYPos()-1.0f);
         break;
         
      case 'c':
         if (cameraMode) {
            co = &s->objects[0];
            cameraMode = false;
         } else {
            co = &s->camera;
            cameraMode = true;
         }
         
      case '+':
         s->camera.setZoom(s->camera.getZoom()-10);
         break;
      case '-':
         s->camera.setZoom(s->camera.getZoom()+10);
         break;
   }
}

void processSpecialKeys(int key, int x, int y) {
   Scene *s = Scene::instance();
   switch (key) {
      case GLUT_KEY_F1:
         s->wireFrame();
         break;
      case GLUT_KEY_F2:
         s->toggleLight();
         break;
      case GLUT_KEY_F3:
         s->smoothShading();
         break;
      case GLUT_KEY_F4:
         s->gouradShading();
         break;
      case GLUT_KEY_F5:
         s->toggleTexture();
         break;
      case GLUT_KEY_LEFT:
         co->setYAngle(co->getYAngle()+1.0f);
         break;
      case GLUT_KEY_RIGHT:
         co->setYAngle(co->getYAngle()-1.0f);
         break;
      case GLUT_KEY_UP:
         co->setXAngle(co->getXAngle()+1.0f);
         break;
      case GLUT_KEY_DOWN:
         co->setXAngle(co->getXAngle()-1.0f);
         break;
   }	
}

void genChaos() {
   Scene *s = Scene::instance();
   /*
   s->camera.setPosition(100, 100, 200);
   s->camera.setYAngle(45);
   s->camera.setZoom(200);
   */
   srand(time(NULL));

   Texture t("sand.bmp");
   s->textures.add(t);

   for (int i=0; i<500; i++) {
      Mesh m;
      float size = rand() % 100;
      float x = rand() % 500, y = rand() % 500, z = -(rand() % 300);
      float xa = rand() % 359, ya = rand() % 359;
      float cr = 0.01*(rand() % 101), cg = 0.01*(rand() % 101), cb = 0.01*(rand() % 101);
      if ((i%2) == 0)
         m = EquilateralTriangle(size, Vector3(cr, cg, cb));
      else
         m = Quad(size, Vector3(cr, cg, cb));
      m.setTexture(0);
      s->meshes.add(m);
      Object o;
      o.setPosition(x,y,z);
      o.setAngles(xa, ya, 0.0f);
      o.addMesh(i);
      s->objects.add(o);
   }
	
}

void genCube () {
   Scene *s = Scene::instance();

   Texture t("sand.bmp");
   s->textures.add(t);
   Mesh m = Cube(5);
   m.setTexture(0);
   s->meshes.add(m);
   for (int i=-5; i<5; i++) {
      Object o;
      o.setPosition(i*5,0,0);
      o.setAngles(0,0,0);
      o.addMesh(0);
       s->objects.add(o);
   }
   
   	
}

int main(int argc, char *argv[]) {
	
	// Glut related
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize(1024, 768);
   glutInitWindowPosition(100, 100);
   glutCreateWindow (argv[0]);
   glutDisplayFunc(display);
   glutTimerFunc(33, process, 0);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(processNormalKeys);
   glutSpecialFunc(processSpecialKeys);
   
   // World related
   cameraMode = true;
   Scene *s = Scene::instance();
   s->camera.setPosition(12, 0, 40);
   s->camera.setXAngle(10);
   s->camera.setZoom(50);
   s->stage = new Stage(5, 5, "aaaaaa   aa   aa   aaaaaa");

   //genChaos();
   //genCube();
   co = &s->camera;
   s->loadProjection(1024, 768);
   s->gouradShading();
   glutMainLoop();
   
   return 0;	
}
