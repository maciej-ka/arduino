#include <math.h>
const int FREQOUT_PIN = 4;
const int RANGER_PIN = A0;

const float A = 1408;
const float AS = 1491.2;
const float B = 1580.3;
const float C = 1674;
const float CS = 1773.7;
const float D = 1879.5;
const float DS = 1991.1;
const float E = 2109.2;
const float F = 2235.6;
const float FS = 2367.6;
const float G = 2508.7;
const float GS = 2657.5;

float lastDistance;
float notes[12] = { A, AS, B, C, CS, D, DS, E, F, G, GS };

float read_gp2d12_range(byte pin) {
  int distance = analogRead(pin);
  if (distance < 3)
    return -1;
  return (6787.0/((float) distance - 3.0)) - 4.0;
}

void setup() {
  pinMode(RANGER_PIN, INPUT);
  Serial.begin(9600);
  lastDistance = 0;
}

void loop() {
  float distance = read_gp2d12_range(RANGER_PIN);
  Serial.println(distance);
  tone(FREQOUT_PIN, notes[map(distance, 10, 80, 0, 11)], lastDistance - distance * 50);
  lastDistance = distance;
}
