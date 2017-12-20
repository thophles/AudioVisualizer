
#include "highParticle.h"

highParticle::highParticle()
{
}


highParticle::~highParticle()
{
}
void highParticle::setup(){
    
    highx = ofGetWidth()/2;
    highy = ofGetHeight()/2;
    highspeedX = 2;
    highspeedY = 5;
    
    highDim = 10;
    
    highColor.set(ofRandom(200),ofRandom(255),ofRandom(255));
    
    
}

void highParticle::update()
{
    highAng = highAng + highAngAcc;
    highOri = highOri + highAng;
    highVec = highVec + highAcc;
    highPos = highPos + highVec;
    
    if(highx < 0 ){
        highx = 0;
        highspeedX *= -1;
    } else if(highx > ofGetWidth()){
        highx = ofGetWidth()/2;
        highspeedX *= -1;
    }
    
    if(highy < 0 ){
        highy = 0;
        highspeedY *= -1;
    } else if(highy > ofGetHeight()){
        highy = ofGetHeight()/2;
        highspeedY *= -1;
    }
    
    highx+=highspeedX;
    highy+=highspeedY;
    
    
}


void highParticle::draw()
{
    ofNoFill();
    ofSetColor(highColor);
    
    ofPushMatrix();
    ofTranslate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    ofRotateXDeg(highOri.x);
    ofRotateYDeg(highOri.y);
    ofRotateZDeg(highOri.z);
    
    ofDrawSphere(highDim);
    ofPopMatrix();
}
