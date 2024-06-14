void update_matrix(){
  for (uint8_t i = 0; i < MATRIX_SIZE; i++){
    buffer[i] = new_buffer[i];
    matrix.setRow(i, buffer[i]);
  }
}

void set_pixel(uint8_t x, uint8_t y, bool state){
  if (x < 0 || x > MATRIX_SIZE - 1 || y < 0 || y > MATRIX_SIZE - 1) return;
    
  if (state){
    new_buffer[MATRIX_SIZE - x - 1] |= (1 << y);
  } else {
    new_buffer[MATRIX_SIZE - x - 1] &= ~(1 << y);
  }
}

bool get_pixel(uint8_t x, uint8_t y){
  if (x < 0 || x > MATRIX_SIZE - 1 || y < 0 || y > MATRIX_SIZE - 1) return true;
  return buffer[MATRIX_SIZE - x - 1] & (1 << y) ? 1 : 0;
}

void clear_matrix(){
  for (uint8_t i = 0; i < MATRIX_SIZE; i++){
    new_buffer[i] = 0;
  }
}