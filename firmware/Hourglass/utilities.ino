uint8_t get_gravity(int angle) {
  uint16_t gravity = ((angle + 180 + 11) / 22.5 + OFFSET);
  return gravity % 16;
}

uint8_t get_top_matrix(uint8_t gravity) {
  if (gravity >= 5 && gravity <= 7) return 2;
  else if (gravity >= 13 && gravity <= 15) return 1;
  return 0;
}

void fill(uint8_t top_matrix) {
  for (uint8_t i = 0; i < PARTICLES; i++){
    set_pixel(i % MATRIX_SIZE, i / MATRIX_SIZE, 1, top_matrix);
  }
}