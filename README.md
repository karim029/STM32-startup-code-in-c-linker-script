# STM32 Startup Code in C and Linker Script

This repository contains a simple STM32 startup code in C and a linker script for the STM32F103C8T6 microcontroller. The startup code initializes the microcontroller, copies data from Flash to RAM, and then jumps to the `main()` function.

## Contents

- [Project Files](#project-files)
- [Usage](#usage)
- [Linker Script](#linker-script)
- [License](#license)

## Project Files

- `stm32f103c8t6_startup.c`: The startup code written in C. It initializes data segments, initializes the system, and then jumps to the `main()` function.
- `LinkerScript.ld`: The linker script for the STM32F103C8T6 microcontroller. It defines memory regions for Flash and RAM.

## Usage

To use this startup code and linker script for your STM32 project:

1. Include the `stm32f103c8t6_startup.c` file in your project.
2. Configure your toolchain to use `LinkerScript.ld` as the linker script for your project.
3. Write your `main()` function, which will be called after initialization.
4. Build and flash your project to the STM32F103C8T6 microcontroller.

## Linker Script

The provided linker script defines memory regions for Flash and RAM for the STM32F103C8T6 microcontroller. This ensures that your program is correctly placed in memory.

## License

This code is provided under the [MIT License](LICENSE), so you are free to use, modify, and distribute it for your projects.

Feel free to contribute and improve this startup code if you find any issues or have suggestions.
