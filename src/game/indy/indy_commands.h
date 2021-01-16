#ifndef _INDY_COMMANDS_H_
#define _INDY_COMMANDS_H_

struct indy_resource_entry {
  unsigned int resourceID;
  int type;
  int size;
  int readsize;
  int writesize;
};

struct indy_resource_entry_type3 {
  struct indy_resource_entry entry;
  unsigned char strbuffer[255];
  unsigned int data;
};

struct indy_resource_entry_type4 {
  struct indy_resource_entry entry;
  unsigned int data;
};

struct indy_resource_entry_type6 {
  struct indy_resource_entry entry;
  unsigned int data1;
  unsigned int data2;
};

extern int indy_ready;

unsigned int postindyresourcecommand(struct indy_resource_entry *param_1,
                                     unsigned int param_2);

#endif
