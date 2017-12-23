#pragma once
#include "ofMain.h"
#include "ofxFX.h"
#include "ofxBeat.h"
#include "drawMid.h"
#include "drawHigh.h"
#include "drawBass.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    drawBass bass;
    drawMid mid;
    drawHigh highRange;
    ofVec2f oldM;
    ofSoundPlayer sound;
    ofLight light;
  
};
