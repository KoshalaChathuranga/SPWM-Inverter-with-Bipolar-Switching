#include <Arduino.h>
#include <math.h>


#define OUTPUT_PIN_1 6
#define OUTPUT_PIN_2 5

long time_ref_micro;
long time_tri_micro;
float frequency_sine = 50; // Frequency of sine wave
float frequency_tri = 20 * frequency_sine; // Frequency of triangle wave



void setup() {
  Serial.begin(2000000);
}

float Reference_signal() {
  float myRefwave = 0.8 * sin(2 * PI * frequency_sine * (time_ref_micro / 1e6));
  //Serial.print("R:");
  //Serial.println(myRefwave, 3);
  return myRefwave;
}

float Carrier_signal() {
  long Carrier = time_tri_micro % (long)(1e6/frequency_tri);
  float amplitude;
  if (Carrier < (long)(1e6/(2*frequency_tri))) {
    // Rising edge
    amplitude = 4.0 * Carrier / (1e6/frequency_tri) - 1.0;
  } else {
    // Falling edge
    amplitude = 3.0 - 4.0 * Carrier / (1e6/frequency_tri);
  }
  //Serial.print("C:");
  //Serial.println(amplitude, 3);
  return amplitude;
}

void PWM_signal(float sine_wave, float triangle_wave) {
  int pwm_val;
  if (sine_wave > triangle_wave) {
    //pwm_val = 1;
    digitalWrite(OUTPUT_PIN_1, HIGH);
    digitalWrite(OUTPUT_PIN_2, LOW);
  } else {
    //pwm_val = 0;
    digitalWrite(OUTPUT_PIN_1, LOW);
    digitalWrite(OUTPUT_PIN_2, HIGH);
  }

  //Serial.print("P:");
  //Serial.println(pwm_val);
}

void loop() {
  time_ref_micro = micros();
  time_tri_micro = micros();
  float sine_wave = Reference_signal();
  float triangle_wave = Carrier_signal();
  PWM_signal(sine_wave, triangle_wave);
  //delay(100); // delay for 1ms
}
