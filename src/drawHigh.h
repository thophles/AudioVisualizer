#pragma once
#include "ofMain.h"
#include "highParticle.h"
#include "ofxBeat.h"



class drawHigh
{
public:
    void setup();
    void update();
    void draw();
    void drawParticle(float x, float y);
    
    std::vector<highParticle> highParticles;
    
    glm::vec3 highPosition;
    glm::vec3 highVelocity;
    glm::vec3 highAcceleration;
    glm::vec3 highRotation;
    
    ofxBeat snare;
    
};

