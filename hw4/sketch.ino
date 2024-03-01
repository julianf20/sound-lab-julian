#include <MIDI.h>
#include <SPI.h>


MIDI_CREATE_DEFAULT_INSTANCE();
int keyboard[120];
int notes[7] = {36, 45, 60, 72, 81, 96, 108};
//correspond to to DAC output voltage, between 0 and 256. Every increment of 3 is 1/12 volt

struct dac {
  int note;
  int gate;
  int priority;
};

struct dac myDAC[4];

const int loadPin = 10;
const int ledPin = A5;

const int DACa = 0,
          DACb = 2,
          DACc = 4,
          DACd = 6,
          DACe = 8,
          DACf = 10,
          DACg = 12,
          DACh = 14;

const int gate_a = 2,
          gate_b = 3,
          gate_c = 4,
          gate_d = 5,
          gate_e = 6,
          gate_f = 7,
          gate_g = 8,
          gate_h = 9;
          

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  dACWrite(0, notes[random(6)]);
  dACWrite(2, notes[random(6)]);
  dACWrite(4, notes[random(6)]);
  dACWrite(6, notes[random(6)]);
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void dACWrite(int channel, int level) {
  digitalWrite(loadPin,HIGH);
  SPI.transfer(channel);
  SPI.transfer(level);
  digitalWrite(loadPin,LOW);
}


void setup()
{

    Serial.begin(31250);

    MIDI.setHandleNoteOn(handleNoteOn);

    MIDI.setHandleNoteOff(handleNoteOff);

    //MIDI.begin(MIDI_CHANNEL_OMNI);

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(loadPin, OUTPUT);
    pinMode(gate_a, OUTPUT);
    pinMode(gate_b, OUTPUT);
    pinMode(gate_c, OUTPUT);
    pinMode(gate_d, OUTPUT);
    pinMode(gate_e, OUTPUT);
    pinMode(gate_f, OUTPUT);
    pinMode(gate_g, OUTPUT);
    pinMode(gate_h, OUTPUT);
    
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV16);
    SPI.setDataMode(SPI_MODE1);

    digitalWrite(loadPin,LOW);
    
    delay(5000);
    Serial.println("START");
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
}

void loop()
{

    MIDI.read();

}
