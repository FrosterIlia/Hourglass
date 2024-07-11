const int8_t OBSTACLE_X_OFFSET[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int8_t OBSTACLE_Y_OFFSET[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

const int8_t GRAVITY_CHECK[16][3] = { { 0, -2, -2 },  // 0   // -1 means no check
                                      { 1, 0, 2 },    // 1
                                      { 1, -2, -2 },  // 2 // -2 means random choice
                                      { 1, 2, 0 },    // 3
                                      { 2, -2, -2 },  // 4
                                      { 3, 2, 4 },    // 5
                                      { 3, -2, -2 },  // 6
                                      { 3, 4, 2 },    // 7
                                      { 4, -2, -2 },  // 8
                                      { 5, 4, 6 },    // 9
                                      { 5, -2, -2 },  // 10
                                      { 5, 6, 4 },    // 11
                                      { 6, -2, -2 },  // 12
                                      { 7, 6, 0 },    // 13
                                      { 7, -2, -2 },  // 14
                                      { 7, 0, 6 } };  // 15


void move_all(uint8_t matrix_number) {
  uint8_t gravity = get_gravity(gyro.getRotationX());

  for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
    for (uint8_t j = 0; j < MATRIX_SIZE; j++) {
      if (get_pixel(i, j, matrix_number)) {
        move(i, j, get_movement_direction(i, j, gravity, matrix_number), matrix_number);
      }
    }
  }
}


int8_t get_movement_direction(uint8_t x, uint8_t y, uint8_t gravity, uint8_t matrix_number) {
  for (uint8_t i = 0; i < 3; i++) {
    if (GRAVITY_CHECK[gravity][i] == -1) return -1;
    if (GRAVITY_CHECK[gravity][i] == -2) {

      int8_t check_order_value = random(0, 2) ? 1 : -1;

      if (!isObstacle(x, y, GRAVITY_CHECK[gravity][0] + check_order_value, matrix_number)) return GRAVITY_CHECK[gravity][0] + check_order_value;
      if (!isObstacle(x, y, GRAVITY_CHECK[gravity][0] - check_order_value, matrix_number)) return GRAVITY_CHECK[gravity][0] - check_order_value;

      break;
    }
    if (!isObstacle(x, y, GRAVITY_CHECK[gravity][i], matrix_number)) return GRAVITY_CHECK[gravity][i];
  }

  return -1;
}

void move(uint8_t x, uint8_t y, int8_t direction, uint8_t matrix_number) {  // direction from 0 to 7

  if (direction < 0) return;
  set_pixel(x, y, 0, matrix_number);
  set_pixel(x + OBSTACLE_X_OFFSET[direction], y + OBSTACLE_Y_OFFSET[direction], 1, matrix_number);
}



bool isObstacle(uint8_t x, uint8_t y, uint8_t direction, uint8_t matrix_number) {  // direction from 0 to 7
  if (get_pixel(x + OBSTACLE_X_OFFSET[direction], y + OBSTACLE_Y_OFFSET[direction], matrix_number) || get_pixel_new(x + OBSTACLE_X_OFFSET[direction], y + OBSTACLE_Y_OFFSET[direction], matrix_number)) {

    return true;  // obstacle detected
  }
  return false;
}