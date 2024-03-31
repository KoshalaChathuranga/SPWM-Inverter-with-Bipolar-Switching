# SPWM Inverter with Bipolar Switching

Design and Test of a SPWM Inverter with Bipolar Switching

## Introduction

This project involves the design and testing of a Sinusoidal Pulse Width Modulation (SPWM) inverter utilizing bipolar switching. SPWM is a technique used to generate a sinusoidal waveform from a DC input by varying the width of the pulses in a PWM signal. In this project, we explore the implementation of SPWM with bipolar switching to achieve efficient and accurate generation of sinusoidal output.

## Test Circuit

To test the SPWM inverter with bipolar switching, you will need the following components:

- Arduino Mega board
- L298N H-bridge driver
- DC source voltage: 12 V
- Load: Purely resistive, 100 Ω/5 W
- Reference signal: Sinewave (frequency = 50 Hz, amplitude = 0.8 V)
- Carrier signal: Triangular (frequency = 1 kHz, amplitude = 1 V)

### Wiring Instructions

Connect the components as follows:

- Connect the DC source voltage (12 V) to the input of the L298N H-bridge driver.
- Connect the output pins of the H-bridge driver to the load (resistor).
- Connect the Arduino Mega board to the H-bridge driver:
  - Pin 5 (OUTPUT_PIN_1) of the Arduino to IN2 of the H-bridge driver.
  - Pin 6 (OUTPUT_PIN_2) of the Arduino to IN1 of the H-bridge driver.

## Method 1: Using Delay-Based SPWM

The first method involves a delay-based approach for SPWM generation. It utilizes pre-defined delay values to control the switching of the H-bridge driver, thereby generating the SPWM waveform. This method is relatively simple and straightforward but may not offer the same level of flexibility and precision as other methods.

## Method 2: Using Sine and Triangle Wave Generation

The second method involves generating sine and triangle waves using mathematical functions to achieve SPWM. This approach calculates the amplitude of the reference sine wave and the carrier triangle wave at each time step and compares them to determine the switching states of the H-bridge driver. This method offers greater flexibility and precision in waveform generation but may be more computationally intensive.

