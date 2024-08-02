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

#define MAIN_PERIOD 100
#define CLOCK_PERIOD 1350  // 1 minute

#define OFFSET 14

#define PARTICLES 50


Gyroscope gyro;
MD_MAX72XX matrix1 = MD_MAX72XX(HARDWARE_TYPE, CS_PIN1, MAX_DEVICES);
MD_MAX72XX matrix2 = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN2, CLK_PIN2, CS_PIN2);

uint8_t buffer1[MATRIX_SIZE];
uint8_t new_buffer1[MATRIX_SIZE];

uint8_t buffer2[MATRIX_SIZE];
uint8_t new_buffer2[MATRIX_SIZE];


void setup() {
  randomSeed(analogRead(A0));
  Wire.begin();

  matrix1.begin();
  matrix2.begin();

  gyro.begin();
  clear_matrix(1);
  clear_matrix(2);

  delay(25); // giving gyroscope some time to start giving correct values

  uint8_t top_matrix = get_top_matrix(get_gravity(gyro.get_angle()));
  top_matrix = top_matrix == 0 ? random(1, 3) : top_matrix;

  fill(top_matrix);

  update_matrix(top_matrix);

}

Timer main_timer(MAIN_PERIOD);
Timer clock_timer(CLOCK_PERIOD);

void loop() {

  if (main_timer.isReady()) {
    move_all(1);
    move_all(2);
    update_matrix(1);
    update_matrix(2);
  }

  if (clock_timer.isReady()) {
    uint8_t top_matrix = get_top_matrix(get_gravity(gyro.get_angle()));

    if (top_matrix == 1) {
      if (get_pixel(7, 0, 1) && !get_pixel(0, 0, 2)) {
        set_pixel(7, 0, 0, 1);
        set_pixel(0, 0, 1, 2);
      }
    } else if (top_matrix == 2) {
      if (get_pixel(0, 0, 2) && !get_pixel(7, 0, 1)) {
        set_pixel(7, 0, 1, 1);
        set_pixel(0, 0, 0, 2);
      }
    }
  }
}