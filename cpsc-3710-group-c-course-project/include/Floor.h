#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "object.h"
#include "objectspecs.h"

//Floor class
class Floor {
    public:
    Floor() {}

    Floor(GLuint name, float centerx, float centery, float centerz, float l, float w, glm::vec3 c) {
        object = name;
        center[0] = centerx;
        center[1] = centery;
        center[2] = centerz;
        length = l;
        width = w;

        //x coordinates
        vert[0][0] = center[0] - length/2;
        vert[1][0] = center[0] - length/2;
        vert[2][0] = center[0] + length/2;
        vert[3][0] = center[0] + length/2;
        //y coordinates
        vert[0][2] = center[2] - length/2;
        vert[1][2] = center[2] + length/2;
        vert[2][2] = center[2] + width/2;
        vert[3][2] = center[2] - width/2;
        
        for (int i=0; i<4; i++) {
            vert[i][1] = center[1]; //x coordinates

            col[i][0] = c[0];
            col[i][1] = c[1];
            col[i][2] = c[2];
        }
    }

    GLfloat vert[4][3];
    GLfloat col[4][3];
    GLubyte inds[1][4] = {0, 1, 2, 3};
    GLfloat center[3];
    GLfloat length;
    GLfloat width;
    GLuint object;
};

void initfloor(Floor* f) {
    initobject(f->object, (GLfloat *) f->vert,
    sizeof(f->vert), (GLfloat *) f->col, sizeof (f->col),
    (GLubyte *) f->inds, sizeof (f->inds), GL_POLYGON);
}

#endif

