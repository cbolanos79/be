#ifndef STAGE_H_
#define STAGE_H_

#include "object.h"
#include "array.h"

/*
 * 
 * Scenario related class
 * 
 */
 
namespace BE {

   class Stage {
      /*
       * 
       * Scenario is composed by a matrix of cells
       * 
       * +------------------+
       * |                  |
       * |                  |
       * |                  |
       * |                  |
       * |                  |
       * |                  |
       * |                  |
       * |                  |
       * +------------------+
       * 
       * Each cell is defined by:
       * 
       *    Position: x,y coordinates on matrix
       *    Type: wall, breakable, water, floor, etc...
       * 
      */
      
      int _rows, _cols;
      Array<Object> _objects;
      char *_cells; // Matrix of cells mapped to vector (
      static int _cell_size;
      
      public:
         Stage() {_cell_size = 5;}
         Stage(const int &rows, const int &cols, const char *s);
         ~Stage() {};
         void render();
         
         // TODO: define methods to interact with cells
   };
}

#endif /*SCENARIO_H_*/
