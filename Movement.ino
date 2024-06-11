void move(){


  set_pixel(1, 1, 1);

  set_pixel(1, 2, 1);

  set_pixel(2, 1, 1);

  

  update_matrix();
  Serial.println(get_pixel(1, 1));

  delay(500);

  set_pixel(1, 1, 0);

  update_matrix();
  Serial.println(get_pixel(1, 1));
  delay(500);
}