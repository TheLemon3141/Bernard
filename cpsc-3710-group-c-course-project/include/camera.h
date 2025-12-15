#ifndef CAMERA_H
#define CAMERA_H

#include "lighting.h"
#include "objectspecs.h"

float mouseoldx;
float mouseoldy;
float eyex = 0;
float eyey = 0;
float eyez = 0;
float scalefactor = 1;
float orthoZoom = 1.0f;        
float perspectiveZoom = 1.0f;

void setCamera(glm::vec3 eye, glm::vec3 look, glm::vec3 up) {
        glMatrixMode(GL_MODELVIEW);
        //y axis angle, aspect ratio, near clip, far clip
        gluPerspective(0, 1, 0, 15);

        glm::vec3 l = glm::normalize(look - eye);
        glm::vec3 r = glm::normalize(glm::cross(look, up));
        glm::vec3 u = glm::cross(r, l);
        
        float myMatrix[16] = {
            r[0], r[1], r[2], (glm::dot(-r, eye)),
            u[0], u[1], u[2], (glm::dot(-u, eye)),
            -l[0], -l[1], -l[2], (glm::dot(l, eye)),
            0, 0, 0, 1
        };
        glLoadMatrixf(myMatrix);
        glutPostRedisplay() ;
}

//Sets camera position, looking at world origin.
void setCameraPosition(float camerax, float cameray, float cameraz) {
        glMatrixMode(GL_MODELVIEW) ; //is GL_MODELVIEW the one we want?
        glLoadIdentity() ;
        //eyex eyey eyez centerx centery centerz upx upy upz
        //setCamera({camerax, cameray, cameraz},{-camerax,-cameray,0},{0,1,1}) ;
        gluLookAt(camerax, cameray, cameraz,-camerax,-cameray,0,0,1,1) ;
        glutPostRedisplay() ;
        lightStuff();
}

//Sets camera at a normal to point x, y, z at a scale factor of zoom.
void setCameraNormal(float x, float y, float z, float zoom) {
    glm::vec3 lookAtPoint = {x, y, z};
    glm::vec3 normal = glm::normalize(lookAtPoint);
    setCamera({-normal[0]*zoom, -normal[1]*zoom, -normal[2]*zoom}, lookAtPoint, {0,1,0});
    eyex = -normal[0]*zoom;
    eyey = -normal[1]*zoom;
    eyez = -normal[2]*zoom;
    glutPostRedisplay() ;
}

void newPerspective(float angle) {
        glMatrixMode(GL_MODELVIEW);
        gluPerspective(angle, 1, 0, 15);
        glLoadIdentity();
        //eyex eyey eyez centerx centery centerz upx upy upz
        glutPostRedisplay();
}

void setPerspectiveCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectRatio = 500.0f / 500.0f;
    gluPerspective(45.0f, aspectRatio, 0.1f, 10.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera moves along the diagonal from above
    glm::vec3 eyePos = glm::vec3(1.5f, 1.5f, 2.0f) * perspectiveZoom;
    gluLookAt(eyePos.x, eyePos.y, eyePos.z,
              0.0f, 0.1f, -0.75f,
              0.0f, 1.0f, 0.0f);

    glutPostRedisplay();
}


void setOrthographicCamera()
{
    glm::vec3 robotCenter = {0.0f, 0.1f, -0.75f};
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float left   = -1.5f * orthoZoom;
    float right  =  1.5f * orthoZoom;
    float bottom = -1.0f * orthoZoom;
    float top    =  1.5f * orthoZoom;
    float nearVal = 0.1f;
    float farVal  = 5.0f;

    glOrtho(left, right, bottom, top, nearVal, farVal);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera in front of robot, looking at its center
    glm::vec3 eye = robotCenter + glm::vec3(0,0,2.0f); // in front along +Z
    glm::vec3 up  = {0,1,0};
    gluLookAt(eye.x, eye.y, eye.z,
              robotCenter.x, robotCenter.y, robotCenter.z,
              up.x, up.y, up.z);

    glutPostRedisplay();
}


#endif
