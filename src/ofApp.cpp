#include "ofApp.h"
#include "FFT.h"


void ofApp::setup(){
 
    ofSetVerticalSync(true);
    FFT::fft().setup();
    bass.setup();
    mid.setup();
    highRange.setup();
    

}


void ofApp::update(){
    
    FFT::fft().update();
    bass.update();
    mid.update();
    highRange.update();

}


void ofApp::draw(){
    ofSetBackgroundColor(255, 255, 255);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    bass.draw();
    mid.draw();
    highRange.draw();
    
//    FFT::fft().drawBars();
//    FFT::fft().drawDebug();
    
    
    
}

void ofApp::keyPressed(int key)
{
    
    if(key=='q'){
        FFT::fft().setVolumeRange(100);
        FFT::fft().setNormalize(false);
    }
    if(key=='r'){
        FFT::fft().setNormalize(true);
    }
}

