#include "Gyroscope.h"
#include "Timer.h"

#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 2
#define CS_PIN1 10  // or SS
#define MATRIX_SIZE 8

#define DATA_PIN2 6
#define CLK_PIN2 7
#define CS_PIN2 5

#define PERIOD 100

#define PARTICLE_AMOUNT 30


Gyroscope gyro;
MD_MAX72XX matrix1 = MD_MAX72XX(HARDWARE_TYPE, CS_PIN1, MAX_DEVICES);
MD_MAX72XX matrix2 = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN2, CLK_PIN2, CS_PIN2);

uint8_t buffer1[MATRIX_SIZE];
uint8_t new_buffer1[MATRIX_SIZE];

uint8_t buffer2[MATRIX_SIZE];
uint8_t new_buffer2[MATRIX_SIZE];


void setup() {
  Serial.begin(9600);
  Wire.begin();

  matrix1.begin();
  matrix2.begin();

  gyro.begin();
  clear_matrix(1);
  clear_matrix(2);


  update_matrix(1);
  update_matrix(2);
  attachInterrupt(0, gyro_interrupt, RISING);

}

Timer test_timer(1000);
Timer main_timer(PERIOD);

void loop() {

  gyro.tick();

  if (main_timer.isReady()) {
    move_all(1);
    move_all(2);

    update_matrix(1);
    update_matrix(2);
  }

  if (test_timer.isReady()) {
    set_pixel(7, 0, 1, 1);
    set_pixel(0, 1, 1, 2);
  }
}