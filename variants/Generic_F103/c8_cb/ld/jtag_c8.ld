/*
 * libmaple linker script for "jtag_c8" builds.
 *
 * A "JTAG" build puts .text (and .rodata) in Flash, and
 * .data/.bss/heap (of course) in SRAM, but links starting at the
 * Flash and SRAM starting addresses (0x08000000 and 0x20000000
 * respectively). This will wipe out a HID bootloader if there's one
 * on the board, so only use this if you know what you're doing.
 *
 * Of course, a "JTAG" build is perfectly usable for upload over SWD,
 * the system memory bootloader, etc. The name is just a historical
 * artifact.
 */

MEMORY
{
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
  rom (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
}

/* Provide memory region aliases for common.inc */
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_BSS", ram);
REGION_ALIAS("REGION_RODATA", rom);

/* Let common.inc handle the real work. */
INCLUDE common.inc
