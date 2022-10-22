# The MAX78000 SDK

Refer to [Getting Started with the MAX78000 Evaluation Kit](https://github.com/MaximIntegratedAI/MaximAI_Documentation/blob/master/MAX78000_Evaluation_Kit/README.md) for details on using the SDK.

## Release Notes

August 26, 2022
* Improved documentation for the options available in the makefile system.
* Addded USB examples for MAX78002
* Fix missing TFT_ENABLE flag from some CNN demos
* Fix memory allocation bug in CNN digit-detection-demo
* Add SD card functionality to ImgCapture example
* Update HM0360 mono drivers
* Fix SW_STEAMING -> SW_STREAMING typo in HM0360 drivers
* Re-work project.mk for projects specifically targeting the 0V7692 camera.

August 7, 2022
* Updated CMSIS library to version 5.9.0.
* Improved MIPI-CSI2 API.
* Added support for flash read and flash write locking.
* Improved RTC busy flag checking.
* Added multi-transaction mode to SPI API.
* Added support to select the voltage levels (VDDIO or VDDIOH) for the 
  camera interface.
* Added Winbond SPI Flash driver.
* Added VS Code project files for all examples.
* Added makefile switch to allow selection of ARM ABI.
* Added missing definition for GCR_RST.usb field.
* Added missing USB register definitions.
* Fixed incorrect size of RTC_SSEC.ssec field.
* Improved support for IPLL and EBO clocks.
* Improved the makefile system.
* Added function to get/set the system clock divider.
* Added aisegment_unet, camvid_unet, cifar-100-mixed, cifar-100-residual, 
  cifar-100-simplewide2x-mixed, digit-detection-demo, svhn_tinierssd, 
  UNet-highres-demo, and ImgCapture-Serial, ARM-DSP, cifar-100-effnet2, 
  cifar-200-mobilenet-v2-0.75, imagenet, and WearLeveling examples.
* Added ability to seperately enable/disable the instruction caches.
* Abstracted external memory interfaces into a common set of functions.
* Added support for PAG7920, color HM0360, monochrome HM0360 cameras.
* Deprecated NVIC_SetVector (CMSIS 3 version) in favor 
  of MXC_NVIC_SetVector
* Changed presence pulse register flag location in the
  1-wire registers 
* Modified ADC asynchronous conversion function to accept the 
  configuration parameter by reference
* Fixed bug when using an ADC external scale setting of 3
* Added correct cache flushing code after all flash writes
* Added generic transmit functions for I2S
* Fixed error that caused I2C underflows to no be reported correctly
* Improved asynchronous I2C master transactions 
* Fixed I2C slave bug that would attempt to call the callback functions
  even when one had not been provided
* Changed the RTC get time funtion to not block when the RTC was busy

April 11, 2022
* Added power down mode to MAX78000 and MAX78002 LP examples.
* Added support for various cameras into the MAX78002 CameraIF example.
* Added TFT use into MAX78002 cats-dogs_demo example.
* Added MIPI-CSI2 peripheral driver and example for MAX78002.
* Fixed incorrect memory size in MAX78002's GCC linker script.
* Added contrast and brightness settings to camera driver.
* Fixed I2C general call addressing enable/disable bug.
* Resolved pointer alignment warnings.
* Added support for enabling/disabling the IPLL clock for the MAX78002.
* Added VSCode support for all example projects.
* Added I2C_SCAN example for MAX78000 and MAX78002.
* Added kws20_demo for MAX78002.
* Added additional 3rd party camera, display, and touch screen drivers.
* Added BSP for MAX78000 audio board.

February 15, 2022
* Moved common board support files to /Libraries/MiscDrivers folder.
* Added FreeRTOS examples for the MAX78000 and MAX78002.
* Added cats-dogs_demo for the MAX78002.
* Fixed bit position for OWM presence detect bit.
* Exposed function to read RTC busy flag.
* Exposed function to read intermediate RX and TX count for UART 
  asynchronous transactions.
* Added support for bi-directional I2S.

December 10, 2021
* Improved RGB565 support for TFT driver.
* Fixed baud rate calculations for UART0 through UART2.
* Added low power mode example.
* Added ability to query progress of asynchronous UART transactions.
* Added 16- and 8-bit accesses to the CRC data register.
* Fixed issue with SPI callbacks not being called when using DMA.
* Fixed issue selecting the appropriate clock divider when initializing timers.
* Fixed issue with releasing DMA channels after UART DMA transaction complete.

September 20, 2021
* Updated all Eclipse project files to resolve indexer errors.
* Added support for additional camera models.
* Changed startup file to enable instruction cache by default.
* Added libary MXC_SYS library function to retreive the device's unique serial number.
* Fixed bug in SPI baud rate calculations.
* Added callback functions for I2S DMA operations.
* Added GPIO ports 2 and 3 to the low power wakeup functions.
* Added RTC trimming function.
* Improved Semaphore support.
* Improved WUT support.
* Fixed incorrect clock source calculations when configuring timers.

June 15, 2021
* Added touchscreen support to faceid_evkit and faceid_evkit-riscv demos.
* Added DMA streaming mode to camera driver.
* Fixed support for P3.0 and P3.1 GPIO pins.
* Changed internal handling of DMA instances.
* Improved I2S support for various word sizes when using DMA.
* Fixed timer code to select the proper source clock.
* Modified UART baud rate selection code.

April 30, 2021
* Added SD card over SPI support for the MAX78000FTHR board.

April 14, 2021
* Added low power support to facid_evkit and kws20_demo examples.
* Updated low power APIs to use low power names provided in the Users Guide.
* Added luminance support to OV7692 camera driver.
* Added support for SPI mode selection in SPI API.
* Added support for VDDIO/VDDIOH selection in SPI API.
* Fixed alignment issue in Flash API.
* Added additional configuration functions to I2C API.
* Added faceid_evkit-risv, kws20_demo-risv, rps, and rps-demo examples.
* Added board support files for the MAXREFDES178.

January 24, 2021
* Modified Camera driver to accept a DMA channel to use.
* Added support for the MAX78000 feather board's optional add-on display.
* Changed some examples to extract the CNN functionality into its own source file.
* Renamed the BBFC block to GCFR to match the User Guide contents.
* Renamed wakeup timer CN register to CTRL to match the User Guide contents.
* Minor updates to OV7692 camera driver.
* Reduced the number of DMA channels supported to 4, matching the hardware.
* Added access functions for certain RISC-V core registers.
* Added initial implementation of RISC-V MXC_Delay() function.
* Adjusted internal peripheral driver functions to allow better compatibility with other Maxim microcontrollers.
* Renamed cats-vs-dogs-chw example to cats-vs-dogs.
* Renamed kws20 example to kws_v3.

November 6, 2020
* Added missing GCR registers and fields.
* Cleaned up PWRSEQ registers.
* Improved low power functionality support.
* Removed MXC_Delay functions from the RISC-V libraries.

October 23, 2020
* Added support for MAX78000 FTRH Rev A board.
* Modified camera driver to use DMA.
* Set CRC data register data types properly to contol access width.
* Added missing ECC IRQ.
* Added missing semaphore registers.
* Added implementation of 1-Wire API.

September 24, 2020
* Added mnist-streaming example.
* Modified cats-dogs_demo to use DMA.
* Added 8-bit and 16-bit accessors to CRC data register.
* Added missing WELR and RLR registers to FLC block.
* Corrected the address for the TRIMSIR block.

September 4, 2020
* Resolved warning in AES initialization code.

September 3, 2020
* Added faceid_evkit example.
* Adeded snake_game_demo example.
* Completed Wakeup Timer (WUT) example.
* Modified TFT libraries to support different screen orientations.
* Improved DMA support in the camera.
* Changed FCR register and field names to match user guide.
* Reordered watchdog timer instances to match the user guide.
* Removed unused ECC files.
* Set the correct base addresses for the low-power comparators.
* Added functions to allow wake up from low-power timers.
* Updated the flash controller code to the latest revision.
* Improved full-duplex communication code for UART.

July 9, 2020
* Moved camera driver files from the example folders to the Libraries\Boards\MAX78000 folder.
* Replaced the CNN/cats_dogs-chw-fifo example with the CNN/cats-dogs_demo example.

July 1, 2020
* Added macros for referencing evaluation kit LEDs by their name on the board.
* Improved support for the TFT display on the evaluation kit.
* Added MXC_UART_ReadCharacterRaw and MXC_UART_WriteCharacterRaw functions.  The "Raw" functions are non-blocking and will return an error code if a character cannot be read or written.  The "non-raw" functions will block until the character can be processed.
* Improved support for paralled camera interface.
* Added these examples: CameraIF, cats_dogs-chw-fifo, faceid, faceid_demo, 

June 16, 2020
* Updated the CNN/kws20_demo example application.  The most significant update being the addition of TFT support.
* Updated the wakeup timer (WUT) example to include deep sleep mode.
* Modified the TFT and touchscreen code in the board folder to be more board independent.
* Corrected some misnamed registers in adc_regs.h.
* Replaced all instances of IntEnable and IntDisable with EnableInt and Disable to maintain consistency across all drivers.
* Added support for the low-power GPIO pins (P3.0 and P3.1).

June 7, 2020
* In the Documentation folder of the SDK, added a MAX78000.html file which serves as a single source for all MAX78000 related documents.
* Added a README.md file for each example.
* Added automatic configuration of ADC GPIO pins.
* Fixed minor GPIO peripheral library bugs.
* Added optional configuration of TMR GPIO pins.

May 21, 2020
* Initial Release

## Known Issues & Upcoming Features

* Debug support for the RISC-V core has not been validated.
* There will be more examples coming in a future release.
* The Eclipse projects show errors and warnings indicating there are unresolved references.  However, the projects still build and run correctly.
* When uninstalling the SDK using the maintenance tool, an error will occur referring to the fstab file.  This error can be ignored - the uninstall will still complete.
* The MXC_Delay library is not complete when building for the RISC-V core.

## Example Status

| Example              |  GCC Status | Eclipse Support | Notes                                                                                           |
|----------------------|:-----------:|:---------------:|-------------------------------------------------------------------------------------------------|
| ADC                  |   Complete  |       Yes       | The overflow, low limit, and high limit are not reported properly in the example.               |
| AES                  |   Complete  |       Yes       |                                                                                                 |
| CameraIF             |   Complete  |       Yes       |                                                                                                 |
| CNN/cats-dogs_demo   |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/cats-vs-dogs     |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/cifar-10         |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/cifar-100        |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/faceid           |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/faceid_demo      |   Complete  |       No        |                                                                                                 |
| CNN/faceid_evkit     |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/kws20_demo       |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/kws20_v3         |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/mnist            |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CNN/mnist-riscv      |   Complete  |     Partial     | Debug support for code running on the RISC-V is not yet supported in Eclipse.                   |
| CNN/mnist-streaming  |   Complete  |     Partial     | Debug support for code running on the RISC-V is not yet supported in Eclipse.                   |
| CNN/snake_game_demo  |   Complete  |       Yes       | The project can be imported into Eclipse, but cannot be created using the New project wizard.   |
| CRC                  |   Complete  |       Yes       |                                                                                                 |
| DMA                  |   Complete  |       Yes       |                                                                                                 |
| ECC                  |   Complete  |       Yes       |                                                                                                 |
| Flash                |   Complete  |       Yes       |                                                                                                 |
| GPIO                 |   Complete  |       Yes       |                                                                                                 |
| Hello_World          |   Complete  |       Yes       |                                                                                                 |
| I2C                  |   Complete  |       Yes       |                                                                                                 |
| I2S                  |   Complete  |       Yes       |                                                                                                 |
| ICC                  |   Complete  |       Yes       |                                                                                                 |
| LP                   | In Progress |   In Progress   |                                                                                                 |
| Pulse_Train          |   Complete  |       Yes       |                                                                                                 |
| RTC                  |   Complete  |       Yes       |                                                                                                 |
| SPI                  |   Complete  |       Yes       |                                                                                                 |
| TFT_Demo             |   Complete  |       Yes       |                                                                                                 |
| TMR                  |   Complete  |       Yes       |                                                                                                 |
| TRNG                 |   Complete  |       Yes       |                                                                                                 |
| UART                 |   Complete  |       Yes       |                                                                                                 |
| Watchdog             |   Complete  |       Yes       |                                                                                                 |
| WUT                  |   Complete  |       Yes       |                                                                                                 |
