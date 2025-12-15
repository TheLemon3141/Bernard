#ifndef LIGHTING_H
#define LIGHTING_H

//Our custom lighting effects
void lightStuff() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //Enables colours to work with lighting
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 127);
    glShadeModel(GL_SMOOTH);


    GLfloat lightPosition[] = {1.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    GLfloat ambientColour[] = {1.0f, 1.0f, 1.0f, 1.0f}; //white
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColour);

    GLfloat specularColour[] = {1.0, 1.0, 1.0, 1.0}; //white
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularColour);

    GLfloat spotDirection[] = {0, 0, -1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
}
#endif
