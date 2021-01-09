#include "bondtypes.h" // game structs and types

struct BriefObjectiveStruct {
  unsigned short text;
  unsigned short difficulty;
};

struct BriefStruct {
  unsigned short brief[4];
  struct BriefObjectiveStruct objective[OBJECTIVES_MAX];
};
