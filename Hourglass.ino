#include "Gyroscope.h"
#include "Timer.h"
#include "Particles.h"

#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 11
#define CS_PIN 10  // or SS
#define MATRIX_SIZE 8

#define PERIOD 100

#define PARTICLE_AMOUNT 100


Gyroscope gyro;
MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

uint8_t buffer[8];
uint8_t new_buffer[8];

//Particle sand[PARTICLE_AMOUNT];


void setup() {
  Serial.begin(9600);
  Wire.begin();

  matrix.begin();
  clear_matrix();
  set_pixel(1, 0, 1);
  set_pixel(1, 1, 1);
  update_matrix();
  attachInterrupt(0, gyro_interrupt, RISING);
  // for (uint8_t i = 0; i < PARTICLE_AMOUNT; i++){
  //   sand[i] = Particle(i, 1);
  // }
}

Timer test_timer(1000);
Timer main_timer(PERIOD);

void loop() {

  gyro.tick();

  if (main_timer.isReady()) {
    //clear_matrix();

    move();
    // set_pixel(1, 1, 1);

    //draw_particles();
    update_matrix();
  }

  if (test_timer.isReady()) {
    Serial.println(get_gravity(gyro.getRotationX()));
  }
}