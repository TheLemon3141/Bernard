#ifndef CYLINDER_H
#define CYLINDER_H

#include "object.h"

//number of sides of all cylinders
const GLint numpoints = 32;

//Cylinder class
class Cylinder {
    public:
    Cylinder(float centerx, float centery, float centerz, float l, float r, float a) {
        center[0] = centerx;
        center[1] = centery;
        center[2] = centerz;
        length = l;
        radius = r;
        angle = a;
    }

    void rotatePart(float a) {
        angle += a;
    }

    float center[3];
    float length;
    float radius;
    float angle;
};

void initcylinder (GLuint object, GLfloat height, GLfloat radius, GLint points, GLfloat* cen, GLfloat angle) {
    GLfloat vert[points+1][3];
    GLfloat col[points+1][3];
    GLubyte inds[1][points+1];

    GLfloat x, y, z;

    GLfloat radians = angle*(M_PI/180);

    for (int i = 0; i < points+1; ++i) {
        GLfloat u = i/(GLfloat)points;

        vert[i][0] = radius*cos(2*M_PI*u) +cen[0];
        vert[i][2] = radius*sin(2*M_PI*u) +cen[2];
        

        if (i%2 == 0) {
            vert[i][1] = height/2 + cen[1];
        } else {
            vert[i][1] = -height/2 + cen[1];
        }

        x = vert[i][0];
        y = vert[i][1];
        z = vert[i][2];

        vert[i][0] -= cen[0];
        vert[i][1] -= height/2 + cen[1];
        vert[i][2] -= cen[2];

        //rotation on x-axis
        vert[i][1] = (vert[i][1]*cos(radians) - vert[i][2]*sin(radians));
        vert[i][2] = (vert[i][1]*sin(radians) + vert[i][2]*cos(radians));

        vert[i][0] += cen[0];
        vert[i][1] += height/2 + cen[1];
        vert[i][2] += cen[2];
        
        col[i][0] = 0.0;
        col[i][1] = 1.0;
        col[i][2] = 0.0;
        inds[0][i] = i;
    }

    initobject(object, (GLfloat *) vert,
    sizeof(vert), (GLfloat *) col, sizeof (col),
    (GLubyte *) inds, sizeof (inds), GL_TRIANGLE_STRIP) ;
}

#endif
