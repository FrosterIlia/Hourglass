#include "Gyroscope.h"
#include "Timer.h"
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES	11

#define CS_PIN    10  // or SS

#define MATRIX_SIZE 8


Gyroscope gyro;
MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

uint8_t buffer[8];
uint8_t new_buffer[8];

void setup() {
  Serial.begin(9600);
  Wire.begin();

  matrix.begin();

  attachInterrupt(0, gyro_interrupt, RISING);
  
}

Timer main_timer(1000);

void loop() {

  gyro.tick();
  if (main_timer.isReady()){
    move();
  }

  update_matrix();
  
}