#include "drawMid.h"
#include "FFT.h"


void drawMid::setup()
{
    FFT::fft().setup();
  //  ofBackground(0);
    
    ofTexture pic0;
    ofTexture pic1;
    
    
    ofLoadImage(pic0, "s1.png");
    ofLoadImage(pic1, "s2.png");
    
    
    midTextures = {pic0, pic1};
}

void drawMid::update()
{
    FFT::fft().update();
    
    float mid = FFT::fft().getMidVal();
    float hihat = beat.hihat();
    ofBackground(hihat, mid, hihat);
    int particlesToAdd = ofMap(hihat, 12, 20, 2, 8, true);
    
    for (int i = 0; i < particlesToAdd; i++) {
        makeParticle(ofGetWidth()/2, ofGetHeight());
    }
    
    ofRectangle screenRect (0, 0, ofGetWidth(), ofGetHeight());
    
    auto iter = midParticles.begin();
    
    while (iter != midParticles.end())
    {
        iter->update();
        
        if (screenRect.inside(iter->midPos) == false)
        {
            iter = midParticles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    
    
}

void drawMid::draw()
{
    float mid = FFT::fft().getMidVal();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (midParticle& p: midParticles)
    {
        p.draw();
    }
    
}

void drawMid::makeParticle(float x, float y) {
    
    float mid = FFT::fft().getMidVal();
    float hihat = beat.hihat();
    
    midParticle p;
    p.midPos.x = ofRandom(ofGetWidth());
    p.midPos.y = ofRandom(ofGetWidth());
    p.midPos.z = 0;
    p.midVec.x = mid * 5;
    p.midVec.y = sin(hihat);
    p.midVec.z = 0;
    p.midAcc.x = ofRandom(hihat * 5, -1);
    p.midAcc.y = -1;
    p.midAcc.z = 0;
    p.midAng.x = 0;
    p.midAng.y = 0;
    p.midAng.z = ofRandom(-2, 2);
    p.midColor = ofColor(mid, ofRandom(mid * 5), mid * 10);
    std::size_t randomTextureIndex = ofRandom(0, midTextures.size());
    p.midText = midTextures[randomTextureIndex];
    midParticles.push_back(p);
}

