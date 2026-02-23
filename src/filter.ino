// =========================================================================
// Htotal_v7.ino
//
// Testing on A0 instead of A2 to check for pin-specific noise.
// Double-cascaded biquad filter + pot volume control.
// =========================================================================

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>

// --- Pot settings --------------------------------------------------------
#define POT_PIN          A4 
#define VOL_MIN          0.001 
#define VOL_MAX          0.5 
#define POT_INTERVAL_MS  50 
#define POT_DEADBAND     10 
#define POT_SMOOTH       0.3 

// --- Audio objects ------------------------------------------------------- 
AudioInputAnalog         in(A2); 
AudioFilterBiquad        htotal1; 
AudioFilterBiquad        htotal2; 
AudioOutputI2S           out; 
AudioControlSGTL5000     audioShield; 
 
// --- Signal chain -------------------------------------------------------- 
AudioConnection c1(in,      0, htotal1, 0); 
AudioConnection c2(htotal1, 0, htotal2, 0); 
AudioConnection c3(htotal2, 0, out,     0); 
AudioConnection c4(htotal2, 0, out,     1); 
 
// --- State --------------------------------------------------------------- 
float    smoothedPot = 409.0; 
float    lastSentPot = -99.0; 
uint32_t lastPotRead = 0; 
 
// ========================================================================= 
void setup() { 
  pinMode(POT_PIN, INPUT); 
 
  AudioMemory(30); 
 
  audioShield.enable(); 
  audioShield.volume(0.5); 
 
  //                              b0              b1              b2              a1              a2 
  double s0[] = {  0.4031285387, -0.4892925572,  0.1958418664, -0.2318435712,  0.0000000000 }; 
  double s1[] = {  1.0000000000, -1.2137300050,  0.4857940360, -1.5265360471,  0.5897956163 }; 
  double s2[] = {  1.0000000000, -1.2137491504,  0.4858061508, -1.0847847561,  0.1977489355 }; 
  double s3[] = {  1.0000000000, -0.7093023256,  0.0000000000, -1.7349880661,  0.8068858754 }; 
  
  htotal1.setCoefficients(0, s0);  htotal2.setCoefficients(0, s0); 
  htotal1.setCoefficients(1, s1);  htotal2.setCoefficients(1, s1); 
  htotal1.setCoefficients(2, s2);  htotal2.setCoefficients(2, s2); 
  htotal1.setCoefficients(3, s3);  htotal2.setCoefficients(3, s3); 
} 
  
// ========================================================================= 
void loop() { 
  if (millis() - lastPotRead >= POT_INTERVAL_MS) { 
    lastPotRead = millis(); 
  
    float raw = analogRead(POT_PIN); 
    smoothedPot = smoothedPot + POT_SMOOTH * (raw - smoothedPot); 
  
    if (abs(smoothedPot - lastSentPot) > POT_DEADBAND) { 
      float linear = smoothedPot / 1023.0; 
      float vol    = VOL_MIN * pow(VOL_MAX / VOL_MIN, linear); 
      audioShield.volume(vol); 
      lastSentPot  = smoothedPot; 
    } 
  } 
}
