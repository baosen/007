OUTPUT_ARCH (mips)

SECTIONS
{
   _UbgDataStart = ADDR(.data);
   _UbgDataRomStart = 0;
   .data 0x0F000000 : AT(0) {
      * (.data);
   }
   _UbgDataEnd = ADDR(.data) + SIZEOF(.data);
   _UbgDataRomEnd = SIZEOF(.data);

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