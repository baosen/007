#include "chrai.h"

void cleanupAlarms(void) {
  stop_alarm();
  check_deactivate_gas_sound();
}
