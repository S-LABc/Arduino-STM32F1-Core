/*
 * libmaple linker script for "hid_bootloader_c4" builds.
 *
 * A Flash build puts .text (and .rodata) in Flash, and
 * .data/.bss/heap (of course) in SRAM, but offsets the sections by
 * enough space to store the HID bootloader, which lives in low
 * Flash and uses low memory.
 */

MEMORY
{
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 6K
  rom (rx)  : ORIGIN = 0x08000800, LENGTH = 14K
}

/* Provide memory region aliases for common.inc */
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_BSS", ram);
REGION_ALIAS("REGION_RODATA", rom);

/* Let common.inc handle the real work. */
INCLUDE common.inc
