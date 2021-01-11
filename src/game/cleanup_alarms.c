void stop_alarm(void);
void check_deactivate_gas_sound(void);

void cleanupAlarms(void) {
  stop_alarm();
  check_deactivate_gas_sound();
}
