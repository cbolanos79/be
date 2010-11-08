#ifndef ARRAY_H_
#define ARRAY_H_

/*
 *
 * Dinamic array of generic items
 *
 *
*/

namespace BE {
   template <class T>

   class Array {
      T *_v; // Vector of T
      int _size; // Count of items
      int _pos; // Position of last element
      static const int _resizeCount = 100; // Number of empty items to add when resizing
      
      void copy(const Array<T> &a);
      
      public:
         Array();
         Array(const int &n);
         Array(const Array<T> &a);
         ~Array();
          /*
           *
           * Append an item into array
           * If there is not enough space, create a new array and
           * dump current one
           *
          */
         int add(const T &t);
         Array<T> &operator=(const Array<T> &t);
         T &operator[](const int &i) const;
         int getCount();
         enum exception { INDEXOUTOFRANGE };

   };
   
   template <class T>
   Array<T>::Array () {
      _pos = 0;
      _v = NULL;
      _size = _resizeCount;
   }
   
   template <class T>
   Array<T>::Array (const int &n) {
      _pos = 0;
      _v = new T[n];
      _size = n;
   }

   template <class T>
   Array<T>::Array (const Array<T> &a) {
      copy(a);
   }

   template <class T>
   Array<T>::~Array() {
      if (_v != NULL)
         delete[](_v);
   }

   template <class T>
   int Array<T>::add (const T &t) {
      if (_v == NULL)
         _v = new T[_resizeCount];

      if (_pos == _size) {
         T *_vaux = new T[_size + _resizeCount];

         for (int i=0; i<_size; i++)
            _vaux[i] = _v[i];

         delete[](_v);

         _v = _vaux;
         _size += _resizeCount;
      }
      _v[_pos] = t;
      _pos++;
      return _pos-1;
   }

   template <class T>
   void Array<T>::copy(const Array<T> &a) {
      if (_v != NULL)
         delete[](_v);

      _v = new T[a._pos];
      _size = a._pos;
      _pos = 0;

      for (int i=0; i<a._pos; i++)
         add(a._v[i]);
   }

   template <class T>
   Array<T> &Array<T>::operator=(const Array<T> &t) {
      copy(t);
      return *this;
   }

   template <class T>
   T &Array<T>::operator[](const int &i) const {
      if (i>=_size)
         throw INDEXOUTOFRANGE;
      return _v[i];
   }
   
   template <class T>
   int Array<T>::getCount() {
      return _pos;
   }
}
      
#endif
