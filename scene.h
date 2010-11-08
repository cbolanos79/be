#ifndef SCENE_H_
#define SCENE_H_

#include <list>
#include "object.h"
#include "array.h"
#include "camera.h"
#include "stage.h"
#include "texture.h"

using namespace BE;

/*
 * 
 * Programs window attributes
 * 
 */

namespace BE { 
   class Scene {
   	  /*
   	   * 
   	   * Scene is composed by objects, camera, light and player.
   	   * 
   	   * Player is a pointer to an object which interacts with user
   	   * 
   	   */

   	  bool _lightEnabled;
   	  bool _textureEnabled;
   	  
      public:
         Scene();
         ~Scene();
         Array<Vertex> vertexs;
         Array<Mesh> meshes;
         Array<Texture> textures;
         Array<Object> objects;
         Camera camera;
         Stage *stage;

         /* Singleton */
         static Scene *inst;
         static Scene *instance() {
            if (!inst)
               inst = new Scene;
            return inst;
         }
         void loadProjection(const int &w, const int &h);
         void initOpengl();
         void initCamera();
         void initStage();
         void render();
         
         void wireFrame();
         void smoothShading();
         void gouradShading();
         
         void enableLight();
         void disableLight();
         void toggleLight();
         
         void enableTexture();
         void disableTexture();
         void toggleTexture();
         
   };
}

#endif /*Scene_H_*/
