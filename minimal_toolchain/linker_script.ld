/*
    @author: daloski, aka oruamdalo
    @desc: Linker script for STM32F401RE
*/

_estack = 0x20018000;

MEMORY{
    FLASH( rx )     : ORIGIN = 0x08000000, LENGTH = 512K
    RAM ( rwx )      : ORIGIN = 0x20000000, LENGTH = 96K
}