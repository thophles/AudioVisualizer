#pragma once

#include "ofMain.h"
#include "ofxFX.h"
#include "ofxBeat.h"
#include "ofxFluid.h"
#include "drawBass.h"
#include "drawMid.h"
#include "drawHigh.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

    
    int width, height;

	//ProcessFFT fft;
    drawBass bass;
    drawMid mid;
    drawHigh highRange;
    ofxFluid fluid;
    ofVec2f oldM;
    ofSoundPlayer sound;
};
