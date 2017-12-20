#include "midParticle.h"

midParticle::midParticle()
{
}


midParticle::~midParticle()
{
}


void midParticle::update()
{
    midAng = midAng + midAngAcc;
    midOri = midOri + midAng;
    
    midVec = midVec + midAcc;
    midPos = midPos + midVec;
    
}


void midParticle::draw()
{
    ofFill();
    ofSetColor(midColor);
    
    ofPushMatrix();
    ofTranslate(midPos);
    ofRotateXDeg(midOri.x);
    ofRotateYDeg(midOri.y);
    
    
    midText.draw(-midText.getWidth() / 2, -midText.getHeight() / 2);
    
    ofPopMatrix();
}
