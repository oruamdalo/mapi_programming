# MAPI
Progetti e codici per il corso MAPI della Federico II con STM Discovery e IAR.

## Toolchain 
Invece di utilizzare la scheda STM32F3Discovery e IAR EW IDE, ho usato una STM32F401RE e come toolchain una minimal che utilizzi compilatori, linker e debugger "low-level". Per fare ciò ho visto con particolare attenzione [questa pagina](https://arm-software.github.io/CMSIS_5/Core/html/using_pg.html) e [questa repo](https://github.com/STMicroelectronics/STM32CubeF4)

UPDATE: guida [link](https://vivonomicon.com/2018/04/20/bare-metal-stm32-programming-part-2-making-it-to-main/)

## TODO
 - [x] Scrivere linker script adatto
 - [ ] Scrivere file di .cfg per OpenOCD (si può prendere da ChibiStudio volendo)
 - [x] Utilizzare correttamente un compilatore arm
 
