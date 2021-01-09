OUTPUT_ARCH (mips)

SECTIONS
{
   _UbriefDataStart = ADDR(.data);
   _UbriefDataRomStart = 0;
   .data 0x00000000 : AT(0) {
      * (.data);
   }
   _UbriefDataEnd = ADDR(.data) + SIZEOF(.data);
   _UbriefDataRomEnd = SIZEOF(.data);

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
