
#include "FFT.h"


ProcessFFT& FFT::fft()
{
    static ProcessFFT _fft;
    return _fft;
}

