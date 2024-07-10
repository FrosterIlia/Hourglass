void update_matrix(uint8_t matrix_number) {
  if (matrix_number == 1) {
    for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
      buffer1[i] = new_buffer1[i];
      matrix1.setRow(i, buffer1[i]);
    }
  } else if (matrix_number == 2) {
    for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
      buffer2[i] = new_buffer2[i];
      matrix2.setRow(i, buffer2[i]);
    }
  }
}

void set_pixel(uint8_t x, uint8_t y, bool state, uint8_t matrix_number) {
  if (x < 0 || x > MATRIX_SIZE - 1 || y < 0 || y > MATRIX_SIZE - 1) return;

  if (state) {
    if (matrix_number == 1) new_buffer1[MATRIX_SIZE - x - 1] |= (1 << y);
    else if (matrix_number == 2) new_buffer2[MATRIX_SIZE - x - 1] |= (1 << y);

  } else {
    if (matrix_number == 1) new_buffer1[MATRIX_SIZE - x - 1] &= ~(1 << y);
    else if (matrix_number == 2) new_buffer2[MATRIX_SIZE - x - 1] &= ~(1 << y);
  }
}

bool get_pixel(uint8_t x, uint8_t y, uint8_t matrix_number) {
  if (x < 0 || x > MATRIX_SIZE - 1 || y < 0 || y > MATRIX_SIZE - 1) return true;
  if (matrix_number == 1) return buffer1[MATRIX_SIZE - x - 1] & (1 << y) ? 1 : 0;
  else if (matrix_number == 2) return buffer2[MATRIX_SIZE - x - 1] & (1 << y) ? 1 : 0;
}

bool get_pixel_new(uint8_t x, uint8_t y, uint8_t matrix_number) {
  if (x < 0 || x > MATRIX_SIZE - 1 || y < 0 || y > MATRIX_SIZE - 1) return true;
  if (matrix_number == 1) return new_buffer1[MATRIX_SIZE - x - 1] & (1 << y) ? 1 : 0;
  else if (matrix_number == 2) return new_buffer2[MATRIX_SIZE - x - 1] & (1 << y) ? 1 : 0;
}

void clear_matrix(uint8_t matrix_number) {
  if (matrix_number == 1) {
    for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
      new_buffer1[i] = 0;
    }
  }

  else if (matrix_number == 2) {
    for (uint8_t i = 0; i < MATRIX_SIZE; i++) {
      new_buffer2[i] = 0;
    }
  }
}