#include "bassParticle.h"
#include "FFT.h"

bassParticle::bassParticle()
{
}


bassParticle::~bassParticle()
{
}

void bassParticle::setup(){
    
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    speedX = 2;
    speedY = 5;
    
    dim = 10;
    
    color.set(ofRandom(200),ofRandom(255),ofRandom(255));
    
    
}

void bassParticle::update()
{
    
        velocity = velocity + acceleration;
        position = position + velocity;
        orientation = orientation + angularVelocity;
        angularVelocity = angularVelocity + angularAcceleration;
    
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth()/2;
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight()/2;
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
    
   
    
}


void bassParticle::draw()
{
    ofNoFill();
    ofSetColor(color);
    
    
    
    ofPushMatrix();

    //    ofTranslate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
 
   
    ofRotateXDeg(orientation.x);
    ofRotateYDeg(orientation.y);
    ofRotateZDeg(orientation.z);
    
    ofDrawSphere(dim);
    ofPopMatrix();
 
}


