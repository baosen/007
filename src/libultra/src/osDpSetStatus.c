void osDpSetStatus(int status) { *(unsigned int *)(0xA410000C) = status; }
