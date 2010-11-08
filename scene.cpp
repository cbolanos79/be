#include <GL/glut.h>
#include <math.h>
#include "scene.h"
#include "stage.h"

using namespace BE;

Scene *Scene::inst = NULL;
 
Scene::Scene() {
   /*
   c = NULL;
   o = NULL;
   s = NULL;
   p = NULL;
   objectsCount = 0;
   */
   _lightEnabled = true;
   _textureEnabled = true;
   initOpengl();
   enableLight();
   enableTexture();
   //initStage();
   
   /*
   initCamera();
   */
}

Scene::~Scene() {
   delete(stage);
}

void Scene::loadProjection(const int &w, const int &h) {
   // Projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   GLfloat aspectRatio;
   aspectRatio = (GLfloat)w / (GLfloat) h;
   gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 0.1f, 1000.0f);
	
}

void Scene::initOpengl() {
   int W = 1024, H = 768;
   // Init states
   glViewport(0, 0, W, H);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);
   //glEnable(GL_CULL_FACE);
      

   // Lighting
   glEnable(GL_COLOR_MATERIAL);
   GLfloat diffuseLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
   GLfloat lightPos[] = {0.0f, 5.0f, 0.0f, 1.0f};
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
   /*
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
   
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    */
   
   // Specular lighting
   GLfloat specular1[] = {100.0f, 100.0f, 1.0f};
   GLfloat specular2[] = {0.0f, 0.0f, 0.0f};
   GLfloat specular3[] = {-100.0f, -100.0f, 1.0f};
   
   glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);
   glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);
   glLightfv(GL_LIGHT2, GL_SPECULAR, specular3);
   GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
   
   glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
   glMateriali(GL_FRONT, GL_SHININESS, 256);
}

void Scene::initCamera() {
	/*
   float d = (15.0*5.0);
   float r = d * sqrt(2)/2;
   camera = new Camera(0.0f, 5.0f, 0.0f);
   camera->setZoom(r + d);
   float ya=45.0f, xa=15.0f;
   camera->setYAngle(ya);
   camera->setXAngle(xa);
	*/
}

void Scene::initStage() {
   
   /*
   int cell=15, row=0, col=0;
   int size = cell * cell;
   char *m = new char[size];
   char c;
   
   for (int i=0; i<size; i++) {
   	  row = i / cell;
   	  col = i % cell;
      if ((row==0) || (row==cell-1) || ( (((row % 5) == 0) && (col%2) == 0))) {
         c = 'a';
      } else if ((col == 0) || (col == cell-1)) {
         c = 'a';
      } else {
         c = ' ';
      }
      m[i] = c;
   }
   
   stage = new Stage(cell, cell, m);
   */
   /*
   s->loadTexture();
   s->enableTexture();
   s->move(-(cell * 5)/2, 0, -(cell*5)/2);
   */
   //free(m);
}

void Scene::render() {
   glMatrixMode(GL_MODELVIEW);
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();

   camera.render();   
   for (int i=0; i<objects.getCount(); i++) {
      objects[i].render();
   }
}


void Scene::wireFrame() {
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
}

void Scene::smoothShading() {
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
   glShadeModel(GL_FLAT);
}

void Scene::gouradShading() {
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
   glShadeModel(GL_SMOOTH);
}

void Scene::enableLight() {
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   _lightEnabled = true;	
}

void Scene::disableLight() {
   glDisable(GL_LIGHTING);
   glDisable(GL_LIGHT0);	
   _lightEnabled = false;	
}

void Scene::toggleLight() {
   if (_lightEnabled)
      disableLight();
   else
      enableLight();
}

void Scene::enableTexture() {
   glEnable(GL_TEXTURE_2D);
   _textureEnabled = true;	
}

void Scene::disableTexture() {
   glDisable(GL_TEXTURE_2D);	
   _textureEnabled = false;	
}

void Scene::toggleTexture() {
   if (_textureEnabled)
      disableTexture();
   else
      enableTexture();   	
}
