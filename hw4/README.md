# MIDI and Arduino

In this assignment, we were asked to build our own MIDI controller using Arduino. I decided to make a random chord generator with a MIDI to CV converter that I had and wanted to experiment with. I wrote code for the device using the Arduino IDE, since it uses the ATMega328p, the same microcontroller as the Arduino Nano. This code reads in MIDI data, and whenever a note is pressed, it generates 4 random notes and sends them to a digital to analog converter which outputs the corresponding notes to 4 vontage controlled oscillators. There are only 7 possible notes, which are all in the same harmonic series. This means that it will always make a major chord in the same key.

The resulting sound is a chord of 4 sawtooth waves, which are then run through a MakeNoise Mimeophon, which adds a dark space echo effect. The sound is very horror-movie like, especially since the possible note combinations are relatively low frequency.
