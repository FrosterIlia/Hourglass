void gyro_interrupt() {
  gyro.dmpReady();
}

uint8_t get_gravity(int angle) {  
  return (angle + 180 + 11) / 22.5;
}

