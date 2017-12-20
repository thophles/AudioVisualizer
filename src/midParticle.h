#pragma once
#include "ofMain.h"

class midParticle {
    
public:
    
     midParticle();
    ~midParticle();
    
    void update();
    void draw();
    
    
    glm::vec3 midPos;
    glm::vec3 midVec;
    glm::vec3 midAcc;
    
    
    
    
    ofColor midColor;
    
    glm::vec3 midOri;
    glm::vec3 midAng;
    glm::vec3 midAngAcc;
    
    ofTexture midText;
    
    
};
