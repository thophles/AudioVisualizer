#pragma once
#include "ofMain.h"
#include "midParticle.h"
#include "ofxBeat.h"



class drawMid
{
public:
    void setup();
    void update();
    void draw();
    void makeParticle(float x, float y);
    
    std::vector<ofTexture> midTextures;
    std::vector<midParticle> midParticles;
    
    ofxBeat beat;

};
