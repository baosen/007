#include "bondconstants.h"

struct BriefObjectiveStruct {
  unsigned short text;
  unsigned short difficulty;
};

#define OBJECTIVES_MAX 10

struct BriefStruct {
  unsigned short brief[4];
  struct BriefObjectiveStruct objective[OBJECTIVES_MAX];
};
