#include <math.h>

// sqrt(tan(angle) + 1)
float sqrt_tan_angle_plus_one(float angle) {
  return sqrtf(((sinf(angle) / cosf(angle)) + 1.0f));
}
