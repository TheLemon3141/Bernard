#ifndef OBJECTSPECS
#define OBJECTSPECS

#include "Cylinder.h"
#include "Floor.h"
#include <vector>

enum {FLOOR1, FLOOR2, FLOOR3, ARM1, ARM2, BODY, LEG1, LEG2, HEAD} ; // For objects, for the floor
//numobjects is in object.h

const int numfloors = 3;
unsigned currentfloor = 1;  //choose 0, 1, or 2

    glm::vec3 pink = {1.0, 0, 0.7};
    glm::vec3 brown = {0.5, 0.3, 0};
    glm::vec3 white = {1.0, 1.0, 1.0};

    Floor floor1(FLOOR1, 0, -.28, -0.5, 1, 1, white);
    Floor floor2(FLOOR2, 0, -.28, -1, 2, 2, pink);
    Floor floor3(FLOOR3, 0, -.28, -1, 0.5, 3, brown);

//    Floor(float centerx, float centery, float centerz, float l, float w) {

//global list of floors
/*

// FLOOR SPECIFICATIONS /////////
const GLfloat floorverts[4][3] = {  //floor vertices
    {0.5, 1, -0.5}, 
    {-0.5, 1, -0.5}, 
    {-0.5, -1, -0.5},
    {0.5, -1, -0.5}
} ;

const GLfloat floorcol[4][3] = {    //floor colour
    {1.0, 0.0, 0.0}, // red
    {1.0, 1.0, 0.0}, // yellow
    {1.0, 1.0, 1.0}, // white
    {0.0, 0.0, 0.0}  // black
} ;
const GLubyte floorinds[1][4] = { {0, 1, 2, 3} } ;  //floor indices

// FLOOR 2 SPECIFICATIONS ///////////////////
const GLfloat floorverts2[4][3] = { //a new floor vertices
    {1, 1, -1}, 
    {-1, 1, -1}, 
    {-1, -1, -1}, //not slanted
    {1, -1, -1}
} ;
const GLfloat floorcol2[4][3] = {   //a new floor colour
    {1.0, 0.0, 1.0}, 
    {1.0, 0.0, 1.0}, 
    {1.0, 0.0, 1.0}, //all magenta
    {1.0, 0.0, 1.0}
} ;
const GLubyte floorinds2[1][4] = { {0, 1, 2, 3} } ; //a new floor indices
*/

//Bernard coordinates
float myz = -0.75;
float bodyx = 0;
float bodyy = 0.25;

//Body Movement
float arm1Ang = 0.0;
float arm2Ang = 0.0;

//Bernard objects
//x, y, z, length, radius, angle
Cylinder arm1(-0.0625 + bodyx, -0.15 + bodyy, myz, 0.35, 0.0125, arm1Ang);
Cylinder arm2(0.0625 + bodyx, -0.15 + bodyy, myz, 0.35, 0.0125, arm2Ang);
Cylinder body(0 + bodyx, 0 + bodyy, myz, 0.25, 0.05, 0.0);
Cylinder leg1(-0.025 + bodyx, -0.35 + bodyy, myz, 0.35, 0.0125, 0.0);
Cylinder leg2(0.025 + bodyx, -0.35 + bodyy, myz, 0.35, 0.0125, 0.0);
Cylinder head(0 + bodyx, 0.2 + bodyy, myz, 0.125, 0.025, 0.0);


#endif
