#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "objectspecs.h"
#include "camera.h"
#include <iostream>

using namespace std;

int legSwitch = 9;
bool usePerspective;

/* Defines what to do when various keys are pressed */
void keyboard (unsigned char key, int x, int y)
{glm::vec3 cameraPos;
    switch (key) {
        case 27:    // Escape KEY to quit
            exit(0) ;
            break ;
        case 102:   // f key to fullscreen
            glutFullScreen();
            break;
        case 103: // g key to switch back to 500/500 size. Doesn't use
            glutReshapeWindow(500, 500);
            break;
        case 't': //t key to setup the first floor
            setCameraNormal(bodyx, bodyy, myz, 1);
            break;
        case '1': //1 key to set a Orthographic Camera angle
            usePerspective = false;
            setOrthographicCamera();
            break;
        case '2': //2 key to set a Perspective Camera angle
            usePerspective = true;
            setPerspectiveCamera();
            break;
        case '=': // zoom in
        if(usePerspective)
            perspectiveZoom *= 0.9f;  // closer
        else
            orthoZoom *= 0.9f;        // smaller ortho box
        break;
        case '-': // zoom out
        if(usePerspective)
            perspectiveZoom *= 1.1f;  // farther
        else
            orthoZoom *= 1.1f;        // larger ortho box
        break;
        case 'a': //a key to scroll left through list of floors
            if (currentfloor == 0) currentfloor = numfloors - 1;
            else currentfloor = currentfloor - 1;
            glutPostRedisplay() ;
            break;
        case 'd': //d key to scroll right through list of floors
            if (currentfloor == numfloors - 1) currentfloor = 0;
            else currentfloor = currentfloor + 1;
            glutPostRedisplay() ;
            break;
        case 'w': //w key to move bernard up (doesn't work yet)
            bodyy = bodyy + 1;
            glutPostRedisplay() ;
            break;
        case 's': //s key to move bernard down (doesn't work yet)
            bodyy = bodyy - 1;
            glutPostRedisplay() ;
            break;
        case 'q': //q key to rotate right arm
            arm1.rotatePart(45);
            glutPostRedisplay() ;
            break ;
        case 'e': //e key to rotate left arm
            arm2.rotatePart(45);
            glutPostRedisplay() ;
            break ;
        case 'm':
            if(leg1.angle == 45 || leg1.angle == -45)
                legSwitch = -legSwitch;
            leg1.rotatePart(legSwitch);
            leg2.rotatePart(-legSwitch);
            glutPostRedisplay() ;
            break ;
        default:
            break ;
    }

    if(usePerspective)
        setPerspectiveCamera();
    else
        setOrthographicCamera();
}
#endif

