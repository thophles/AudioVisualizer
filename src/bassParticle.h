#pragma once
#include "ofMain.h"

class bassParticle {
    
public:
    
    bassParticle();
    ~bassParticle();
    
    void setup();
    void update();
    void draw();
    
    
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 orientation;
    glm::vec3 angularVelocity;
    glm::vec3 angularAcceleration;
    
    int dim;
    int res;
   
    
    int x;
    int y;
    float speedY;
    float speedX;
    ofColor color;
    
    
};

