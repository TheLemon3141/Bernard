#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <iostream>
//#include "shaders.h"
GLuint vertexshader, fragmentshader, shaderprogram ; // shaders

//library for 3d mathematics
#include <glm/glm.hpp>
#include <vector>
#include "include/mouse.h"
#include "include/keyboard.h"
#include "include/objectspecs.h"
#include "include/Cylinder.h"
#include "include/Floor.h"
#include "include/object.h"
//#include <iostream>

using namespace glm;
using namespace std;

int oldTimeSinceStart = 0;

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Initialization in init() for Drawing
    glGenBuffers(numperobj*numobjects, buffers) ;
    //initialize the objects and then draw them

/*
    initobject(FLOOR, (GLfloat *) floorverts, sizeof(floorverts),
    (GLfloat *) floorcol, sizeof (floorcol), (GLubyte *) floorinds,
    sizeof (floorinds), GL_POLYGON) ;

    initobject(FLOOR2, (GLfloat *) floorverts2,
    sizeof(floorverts2), (GLfloat *) floorcol2, sizeof (floorcol2),
    (GLubyte *) floorinds2, sizeof (floorinds2), GL_POLYGON) ;
*/

// load image data form a file using stb_image.h or something else
    GLuint floorTextures[3];
    glCreateTextures(GL_TEXTURE_2D, 3, floorTextures);
    glBindTexture(GL_TEXTURE_2D, floorTextures[currentfloor]);
//^generate and bind
//upload image data to GPU using glTexImage2d
//set texure params-- filtering (gl_linear, gl_nearest) or wrapping (gl_repeat, gl_clamp_to_edge) using glTexParameteri
//define vertex data with both position and texture coords normally in range 0, 1
//create and fill a vbo with that data^
//use a vao (vertex array object) to manage attribute pointers
//write shaders to handle texture lookup
//in render loop, bind the texture and the VAO, use the shader program, and issue a drawing command like glDrawArrays
// googled "apply a texture to a polygon opengl v3"

    Floor* floorlist[3];
    floorlist[0] = (&floor1);
    floorlist[1] = (&floor2);
    floorlist[2] = (&floor3);
    initfloor(floorlist[currentfloor]);
    drawobject(floorlist[currentfloor]->object);

    initcylinder(ARM1, arm1.length, arm1.radius, numpoints, arm1.center, arm1.angle);
    initcylinder(ARM2, arm2.length, arm2.radius, numpoints, arm2.center, arm2.angle);
    initcylinder(BODY, body.length, body.radius, numpoints, body.center, body.angle);
    initcylinder(LEG1, leg1.length, leg1.radius, numpoints, leg1.center, leg1.angle);
    initcylinder(LEG2, leg2.length, leg2.radius, numpoints, leg2.center, leg2.angle);
    initcylinder(HEAD, head.length, head.radius, numpoints, head.center, head.angle);

    drawobject(ARM1);
    drawobject(ARM2);
    drawobject(BODY);
    drawobject(LEG1);
    drawobject(LEG2);
    drawobject(HEAD);

    glutSwapBuffers();
    glFlush (); 
}

// MAIN FUNCTION ///////////////
int main(int argc, char** argv)
{
    glutInit(&argc, argv);  //initializes GLUT library

    // Requests the type of buffers (Single, RGB).
    // Think about what buffers you would need...
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //display mode. Default.

    glutInitWindowSize(500, 500);       //window size
    glutInitWindowPosition(100, 100);   //window position
    glutCreateWindow("myWindow");   // makes a window
    glewInit();
    init(); // Always initialize first

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);   //actually displays our window
    glutMouseFunc(mouse) ;
    glutMotionFunc(mousedrag) ;
    //glutPassiveMotionFunc(mousemove) ;
    glutMainLoop(); // Start the main code
    return 0; /* ANSI C requires main to return int. */
}

// TO COMPILE: "make" (or "make all")
// TO RUN: "./bernard"
