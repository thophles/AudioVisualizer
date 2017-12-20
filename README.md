AudioVisualizer

This project used the OpenFrameworks C++ library to create an audio visualizer. It currently gathers the data from the volume of the low, mid, and high frequency ranges, as well as beats.

The software has the ability to respond to live audio or music streamed from another application. To respond to streaming music, you must download Soundflower and Jack, two free programs that make it easy to re-route audio. In the ofxEasyFFt cpp file, make sure lines 28-29 aren't commented out. Adjust the device ID based on your computer's available device list. To respond to live audio, comment out lines 28-29 and uncomment line 30.