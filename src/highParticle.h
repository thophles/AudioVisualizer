#pragma once
#include "ofMain.h"

class highParticle {
    
public:
    
    highParticle();
    ~highParticle();
    void setup();
    void update();
    void draw();
    
    
    glm::vec3 highPos;
    glm::vec3 highVec;
    glm::vec3 highAcc;
    glm::vec3 highOri;
    glm::vec3 highAng;
    glm::vec3 highAngAcc;

    ofColor highColor;
    int highDim;
    int highx;
    int highy;
    float highspeedY;
    float highspeedX;

    
    
};
