# MAPI
Minimal toolchain and sample example projects on STM32 MCU without using any HAL driver. Projects from course "Laboratorio di misure" for Computer Science Engineering in Federico II.

## Toolchain
For the course the STM32F3Discovery MCU is used, and IAR Embedded Workbench IDE is used for programming and debugging.
I already had a STM32 MCU, which is the STM32F401RE on the NUCLEO64 board. So instead of using the Discovery, I used this one.

<b>Why didn't I use IAR ER?</b> For two main reasons:
- I wanted to understand what was going under the hood while I was using IAR
- I wanted a very lightweight toolchain which I could customize based on my preferences

## Usage
Using the Makefile it is possibile to compile the project. Edit it based on your arm compiler path, your code and the libraries you use.

The following commands are executed for:
- Flashing: 
```console 
foo@bar:~$ st-flash write filename.bin FLASH_MEMORY_ADDRESS
```

- Debugging: First open a connection with [st-util](https://github.com/stlink-org/stlink), then debug with gdb 
```console 
foo@bar:~$ st-util
[in a separate terminal]

foo@bar:~$ arm-eabi-none-gdb filename.elf
[...]
(gbd) target extended-remote :port_number (usually :4242)
(gdb) load
(gdb) continue
```

## TODO
 - [x] Write linker_script.ld
 - [ ] Write .cfg for OpenOCD (can take this one from ChibiStudio maybe - I should first check the LICENSE)
 - [x] Properly use arm compiler and generate Makefile
 - [ ] Improve default debugger usage
 
## Requirements
- [st-link for communication with the board](https://github.com/stlink-org/stlink)
- [ARM toolchain (compiler, linker, debugger)] (https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain)


## Credits
- [CMSIS](https://arm-software.github.io/CMSIS_5/General/html/index.html)
- [STM32 libraries and other configurations files](https://github.com/STMicroelectronics/STM32CubeF4)
- [Bare Metal STM32 guide series](https://vivonomicon.com/2018/04/20/bare-metal-stm32-programming-part-2-making-it-to-main/)
- [st-link open source tools](https://github.com/stlink-org/stlink)

