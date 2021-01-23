float sub_GAME_7F05C440(float arg0) {
  float temp_f2;
  if (arg0 <= 0.0f)
    return (float)(int)arg0;
  temp_f2 = (float)(int)arg0;
  if (arg0 == temp_f2)
    return temp_f2;
  return temp_f2 + 1.0f;
}

int sub_GAME_7F05C4B8(float arg0) {
  int temp_f8;
  if (arg0 <= 0.0f)
    return (int)arg0;
  temp_f8 = (int)arg0;
  if (arg0 == (float)temp_f8)
    return temp_f8;
  return temp_f8 + 1;
}
