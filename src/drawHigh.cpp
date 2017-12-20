#include "drawHigh.h"
#include "FFT.h"

void drawHigh::setup()
{
}

void drawHigh::update()
{
    float high = FFT::fft().getHighVal();
    int particlesToAdd = ofMap(high, 0.1, .5, 0, 1, true);
    
    std::cout << particlesToAdd << std::endl;
    
    for (int i = 0; i < particlesToAdd; i++) {
        drawParticle(ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2)) ;
        
        
    }
    ofRectangle screenRect (0, 0, ofGetWidth(), ofGetHeight());
    
    
    auto iter = highParticles.begin();
    
    while (iter != highParticles.end())
    {
        iter->update();
        
        if (screenRect.inside(iter->highPos) == false)
        {
            iter = highParticles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}

void drawHigh::draw()
{
    for (highParticle& h: highParticles)
    {
        h.draw();
    }
}


void drawHigh::drawParticle(float x, float y)
{
    
    // Use fft inside components.
    float high = FFT::fft().getHighVal();
    
    
    highParticle h;
    h.highPos.x = ofGetWidth()/2;
    h.highPos.y = ofGetHeight()/2;
    h.highPos.z = 0;
    h.highVec.x = 0;
    h.highVec.y = high * 10;
    h.highVec.z = 0;
    h.highAcc.x = 0;
    h.highAcc.y = high * 5;
    h.highAcc.z = 5;
    h.highspeedX = 0;
    h.highspeedY = 0;
    h.highOri.z = high * 10;
    h.highOri.y = high * 5;
    h.highOri.x = 0;
    h.highAng.x = high * 2;
    h.highAng.y = 20;
    h.highAng.z = high * 8;
    h.highDim = high * 3;
    h.highColor = ofColor(244 , high * 205, 66);
    highParticles.push_back(h);
    
}
