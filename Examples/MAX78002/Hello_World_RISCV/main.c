
#include <stdlib.h>
#include <stdint.h>
#include "mxc.h"
#include "gcfr_regs.h"
#include "fcr_regs.h"
#include "sema_regs.h"

/***** Definitions *****/

/***** Globals *****/

/***** Functions *****/

// *****************************************************************************

extern volatile void const *__FlashStart_; // Defined in linker file

void WakeISR(void)
{
    MXC_SEMA->irq0 = MXC_F_SEMA_IRQ0_EN & ~MXC_F_SEMA_IRQ0_CM4_IRQ;
}

int main(void)
{
    MXC_ICC_Enable(MXC_ICC0); // Enable cache

    // Switch to 100 MHz clock
    MXC_SYS_Clock_Select(MXC_SYS_CLOCK_IPO);
    SystemCoreClockUpdate();

    MXC_FCR->urvbootaddr = (uint32_t)&__FlashStart_; // Set RISC-V boot address
    MXC_SYS_ClockEnable(MXC_SYS_PERIPH_CLOCK_SMPHR); // Enable Sempahore clock
    NVIC_SetVector(RISCV_IRQn, WakeISR);             // Set wakeup ISR

    printf("ARM is waiting...\n");

    // DO NOT DELETE THIS LINE:
    MXC_Delay(SEC(2)); // Let debugger interrupt if needed

    MXC_SYS_ClockEnable(MXC_SYS_PERIPH_CLOCK_CPU1); // Enable RISC-V clock

    __WFI(); // Let RISC-V run

    printf("ARM is back...\n");

    return 0;
}
