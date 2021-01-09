OUTPUT_ARCH (mips)

SECTIONS
{
   _LnameXDataStart = ADDR(.data);
   _LnameXDataRomStart = 0;
   .data 0x00000000 : AT(0) {
      * (.data);
   }
   _LnameXDataEnd = ADDR(.data) + SIZEOF(.data);
   _LnameXDataRomEnd = SIZEOF(.data);

   _LnameXRODataStart = ADDR(.rodata);
   _LnameXRODataRomStart = _LnameXDataRomEnd;
   .rodata : AT(_LnameXDataRomEnd) {
      * (.rodata);
   }
   _LnameXRODataEnd = ADDR( .rodata) + SIZEOF( .rodata);
   _LnameXRODataRomEnd = _LnameXDataRomEnd + SIZEOF( .rodata);

   /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.options);
      * (.gnu.attributes);
      * (.pdr);
      * (.mdebug);
      * (.gptab.bss);
      * (.gptab.data);
      * (.reginfo);
   }
}
