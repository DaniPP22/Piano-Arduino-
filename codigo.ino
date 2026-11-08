#include "MIDIUSB.h"


const int pinDo = 9;  // Nota 51
const int pinRe = 8;  // Nota 52
const int pinMi = 7;  // Nota 53
const int pinFa = 6;  // Nota 54
const int pinSol = 5; // Nota 55
const int pinLa = 4;  // Nota 56
const int pinSi = 3;  // Nota 57
const int led = 10;  

int estadoAntDo = LOW;
int estadoAntRe = LOW;
int estadoAntMi = LOW;
int estadoAntFa = LOW;
int estadoAntSol = LOW;
int estadoAntLa = LOW;
int estadoAntSi = LOW;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t msg = {0x09, (byte)(0x90 | channel), pitch, velocity};
  MidiUSB.sendMIDI(msg);
  MidiUSB.flush();
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t msg = {0x08, (byte)(0x80 | channel), pitch, velocity};
  MidiUSB.sendMIDI(msg);
  MidiUSB.flush();
}

void setup() {
  pinMode(pinDo, INPUT);
  pinMode(pinRe, INPUT);
  pinMode(pinMi, INPUT);
  pinMode(pinFa, INPUT);
  pinMode(pinSol, INPUT);
  pinMode(pinLa, INPUT);
  pinMode(pinSi, INPUT);
  pinMode(led, OUTPUT);        
}

void loop() {
  // --- DO (Pin 9 -> Nota 51) ---
  int estadoActDo = digitalRead(pinDo);
  if (estadoActDo != estadoAntDo) {
    if (estadoActDo == HIGH) { digitalWrite(led, HIGH); noteOn(0, 51, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 51, 0); }
    delay(50);
  }
  estadoAntDo = estadoActDo;

  // --- RE (Pin 8 -> Nota 52) ---
  int estadoActRe = digitalRead(pinRe);
  if (estadoActRe != estadoAntRe) {
    if (estadoActRe == HIGH) { digitalWrite(led, HIGH); noteOn(0, 52, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 52, 0); }
    delay(50);
  }
  estadoAntRe = estadoActRe;

  // --- MI (Pin 7 -> Nota 53) ---
  int estadoActMi = digitalRead(pinMi);
  if (estadoActMi != estadoAntMi) {
    if (estadoActMi == HIGH) { digitalWrite(led, HIGH); noteOn(0, 53, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 53, 0); }
    delay(50);
  }
  estadoAntMi = estadoActMi;

  // --- FA (Pin 6 -> Nota 54) ---
  int estadoActFa = digitalRead(pinFa);
  if (estadoActFa != estadoAntFa) {
    if (estadoActFa == HIGH) { digitalWrite(led, HIGH); noteOn(0, 54, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 54, 0); }
    delay(50);
  }
  estadoAntFa = estadoActFa;

  // --- SOL (Pin 5 -> Nota 55) ---
  int estadoActSol = digitalRead(pinSol);
  if (estadoActSol != estadoAntSol) {
    if (estadoActSol == HIGH) { digitalWrite(led, HIGH); noteOn(0, 55, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 55, 0); }
    delay(50);
  }
  estadoAntSol = estadoActSol;

  // --- LA (Pin 4 -> Nota 56) ---
  int estadoActLa = digitalRead(pinLa);
  if (estadoActLa != estadoAntLa) {
    if (estadoActLa == HIGH) { digitalWrite(led, HIGH); noteOn(0, 56, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 56, 0); }
    delay(50);
  }
  estadoAntLa = estadoActLa;

  // --- SI (Pin 3 -> Nota 57) ---
  int estadoActSi = digitalRead(pinSi);
  if (estadoActSi != estadoAntSi) {
    if (estadoActSi == HIGH) { digitalWrite(led, HIGH); noteOn(0, 57, 127); }
    else { digitalWrite(led, LOW); noteOff(0, 57, 0); }
    delay(50);
  }
  estadoAntSi = estadoActSi;
}






