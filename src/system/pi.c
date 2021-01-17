// "Parallel interface" used to asynchronously/DMA read and write from ROM and SRAM.
#include <message.h>

#define PI_COMMAND_BUFFER_SIZE 8

OSMesg piCmdBuf[PI_COMMAND_BUFFER_SIZE];
OSMesgQueue piCmdQ;

void start_pi_manager(void) {
  osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, PI_COMMAND_BUFFER_SIZE);
}
