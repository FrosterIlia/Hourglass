


void move() {
  uint8_t gravity = get_gravity(degrees(gyro.getRotationX()));

  if (gravity == 4) { // down
    for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
      for (uint8_t j = 0; j < MATRIX_SIZE; j++) {
        if (get_pixel(i, j)){

          if (!get_pixel(i, j+1)) {
          set_pixel(i, j, 0);
          set_pixel(i, j+1, 1);
        }

        }
        

      }
    }
  }
}

bool isObstacle(uint8_t x, uint8_t y, uint8_t direction) {
  if (direction == 4) {
    if (get_pixel(x, y) && !get_pixel(x, y + 1)) {

      return false;  // no obstacle
    }
    return false;
  }
}