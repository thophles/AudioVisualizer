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
    light.enable();
    highRange.draw();
    mid.draw();
    bass.draw();
    light.disable();
    
//    FFT::fft().drawBars();
//    FFT::fft().drawDebug();
}


