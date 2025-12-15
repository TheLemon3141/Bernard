#ifndef MOUSE_H
#define MOUSE_H

#include "camera.h"

/* Defines a Mouse callback to zoom in and out */
/* This is done by modifying gluLookAt
*/
/* The actual motion is in mousedrag
*/
/* mouse simply sets state for mousedrag
*/
void mouse(int button, int state, int x, int y)
{    mouseoldx = x ; mouseoldy = y ; // so we can move wrt x , y
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

    }
    else if (button == 3 && state == GLUT_DOWN) { // scroll in

    }
    else if (button == 4 && state == GLUT_DOWN) { // scroll out

    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // Reset gluLookAt

    }
}

void mousedrag(int x, int y) {
    float xdif = x - mouseoldx;
    float ydif = y - mouseoldy;
    float yoffset = 0;
    float zoomspeed = 0.001;
    eyex += zoomspeed*xdif ;
    eyey += zoomspeed*ydif ;

    // Where do we look from
    //if (eyez < 0)eyez = 0.0 ;  //prevents eyez from becoming negative
    mouseoldy = y ;
    mouseoldx = x ;
    // Set the eye location again
    setCameraPosition(eyex*scalefactor,-eyey*scalefactor + yoffset, -eyey*scalefactor - 0.5) ;
}

//not used yet
void mousemove(int x, int y) {
    float eyex = 1.005*x;
    float eyey = 1.005*y;
    setCameraPosition(eyex,-eyey,eyez) ;
}
#endif
