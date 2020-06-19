#include "internal/alarm.h"

int alarm_internal_subscribe(subscribe_cb cb, void *userdata) {
  return subscribe(DRIVER_NUM_ALARMDT, 0, cb, userdata);
}

int alarm_internal_set(uint32_t reference, uint32_t dt) {
  return command(DRIVER_NUM_ALARMDT, 4, (int)reference, (int)dt);
}

int alarm_internal_stop(void) {
  return command(DRIVER_NUM_ALARMDT, 3, 0, 0);
}

unsigned int alarm_internal_frequency(void) {
  return (unsigned int) command(DRIVER_NUM_ALARMDT, 1, 0, 0);
}
