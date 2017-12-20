#pragma once
#include "ofMain.h"
#include "bassParticle.h"


class drawBass
{
public:
    void setup();
    void update();
    void draw();
    void createParticle(float x, float y);
    

    std::vector<bassParticle> particles;
    
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 rotation;
};



