void gyro_interrupt() {
  gyro.dmpReady();
}

uint8_t get_gravity(int angle) {  // 4 - down

  return (angle + 180 + 11) / 22.5;
}

// void draw_particles() {

//   for (uint8_t i = 0; i < PARTICLE_AMOUNT; i++) {
//     set_pixel(sand[i].pos.x, sand[i].pos.y, 1);
//   }
// }