#ifndef _ULTRA64_CONTROLLER_H_
#define _ULTRA64_CONTROLLER_H_

typedef struct {
  unsigned short type;  // Controller type.
  unsigned char status; // Controller status.
  unsigned char errno;  // Error number.
} OSContStatus;

typedef struct {
  unsigned short button; // Which button?
  char stick_x,          // -80 <= stick_x <= 80.
       stick_y;          // -80 <= stick_y <= 80.
  unsigned char errno;   // Error number.
} OSContPad;

enum {
  A_BUTTON = 1 << 15,
  B_BUTTON = 1 << 14,
  Z_TRIG = 1 << 13,
  START_BUTTON = 1 << 12,
  U_JPAD = 1 << 11,
  D_JPAD = 1 << 10,
  L_JPAD = 1 << 9,
  R_JPAD = 1 << 8,
  DUMMY_1 = 1 << 7,
  DUMMY_2 = 1 << 6,
  L_TRIG = 1 << 5,
  R_TRIG = 1 << 4,
  U_CBUTTONS = 1 << 3,
  D_CBUTTONS = 1 << 2,
  L_CBUTTONS = 1 << 1,
  R_CBUTTONS = 1 << 0
};

int osContInit(OSMesgQueue *, unsigned char *, OSContStatus *);
void osContGetReadData(OSContPad *);

#endif
