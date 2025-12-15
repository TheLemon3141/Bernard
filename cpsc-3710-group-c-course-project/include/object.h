#ifndef OBJECT_H
#define OBJECT_H

#include "objectspecs.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *) NULL + (bytes))
#define NumberOf(array) (sizeof(array)/sizeof(array[0]))
enum {Vertices, Colors, Elements} ; // For arrays for object

// VERTEX BUFFER OBJECT SPECIFICATIONS /////////////////
const int numobjects = 88; // number of objects for buffer
const int numperobj = 3; // Vertices, colors, indices
GLuint buffers[numperobj]; // List of buffers for geometric data
GLuint objects[numobjects]; // For each object
GLenum PrimType[numobjects]; // Primitive Type (quads, polygons)
GLsizei NumElems[numobjects]; // Number of geometric elements

// INITIALIZING BUFFERS OF AN OBJECT //
/* 
  object: name of object
  vert: position of verticies on the object
  sizevert: size of array containing vertices
  col: color data for each vertex
  sizecol: size of array containing color data
  inds: indeces corresponding to a vertex and its color data
  sizeind: size of array containing indeces
  type: primitive type used to create object
*/
void initobject (GLuint object, GLfloat* vert, GLint sizevert, GLfloat*
    col, GLint sizecol, GLubyte* inds, GLint sizeind, GLenum type) {
        int offset = object * numperobj;   //offset between objects
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices+offset]) ; //binds a named buffer object
        glBufferData(GL_ARRAY_BUFFER, sizevert, vert, GL_STATIC_DRAW); //creates and initializes a buffer object's data store
        glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0)) ; //defines an array of vertex data (size, type, stride (bite offset in consecutive vertices), pointer to first vertex in array)
        glEnableClientState(GL_VERTEX_ARRAY) ;
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Colors+offset]) ;
        glBufferData(GL_ARRAY_BUFFER, sizecol, col,GL_STATIC_DRAW);
        glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0)) ;
        glEnableClientState(GL_COLOR_ARRAY) ;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[Elements+offset]) ;
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeind, inds,GL_STATIC_DRAW);
        PrimType[object] = type ;
        NumElems[object] = sizeind ;
}

// DRAW A VERTEX OBJECT /////////
void drawobject(GLuint object) {
    int offset = object * numperobj ;
    glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices+offset]) ;
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0)) ;
    glEnableClientState(GL_VERTEX_ARRAY) ;
    glBindBuffer(GL_ARRAY_BUFFER, buffers[Colors+offset]) ;
    glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0)) ;
    glEnableClientState(GL_COLOR_ARRAY) ;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
    buffers[Elements+offset]) ;
    glDrawElements(PrimType[object], NumElems[object],
    GL_UNSIGNED_BYTE, BUFFER_OFFSET(0)) ;
}

// initializes the program
void init(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity() ;
    glClearColor(0.2, 0.0, 0.2, 0.0);   //Defines "background colour"
    glEnable(GL_DEPTH_TEST);    //compares a fragment's depth value with the buffer's content
    lightStuff();
}

#endif
