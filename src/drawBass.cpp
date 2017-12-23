#include "drawBass.h"
#include "FFT.h"

void drawBass::setup()
{
}

void drawBass::update()
{
    float bass = FFT::fft().getSuperLowVal();
    int particlesToAdd = ofMap(bass, 0.1, .5, 0, 1, true);
    
    std::cout << particlesToAdd << std::endl;
    
    for (int i = 0; i < particlesToAdd; i++) {
         createParticle(ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2)) ;
      
        
    }
    ofRectangle screenRect (0, 0, ofGetWidth(), ofGetHeight());
    
    
    auto iter = particles.begin();

    while (iter != particles.end())
    {
        iter->update();

        if (screenRect.inside(iter->position) == false)
        {
            iter = particles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}

void drawBass::draw()
{
    for (bassParticle& b: particles)
    {
        b.draw();
    }
}


void drawBass::createParticle(float x, float y)
{
    
    // Use fft inside components.
    float bass = FFT::fft().getLowVal();

    bassParticle b;
    b.position.x = ofGetWidth()/2;
    b.position.y = ofGetHeight()/2;
    b.position.z = 0;
    b.velocity.x = 0;
    b.velocity.y = sin(bass * 10);
    b.velocity.z = 0;
    b.speedX = 0;
    b.speedY = 0;
    b.res = bass * 2;
    b.acceleration.x = bass * 5;;
    b.acceleration.y = 0;
    b.acceleration.z = 5;
    b.orientation.z = bass * 10;
    b.orientation.y = bass * 5;
    b.orientation.x = 0;
    b.angularVelocity.x = bass * 2;
    b.angularVelocity.y = 20;
    b.angularVelocity.z = bass * 8;
    b.dim = bass * 14;
    b.color = ofColor(255 , 0, ofRandom(bass * 10));
    particles.push_back(b);

}

