/***** Includes *****/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "mxc.h"
#include "led.h"
#include "board.h"
#include "fcr_regs.h"
#include "sema_regs.h"

/***** Definitions *****/

/***** Globals *****/

/***** Functions *****/

// *****************************************************************************
int main(void)
{
    int count = 0;

    Debug_Init();             // Set up RISCV JTAG
    MXC_ICC_Enable(MXC_ICC1); // Enable cache

    printf("Hello World from RISC-V!\n");

    for (count = 0; count < 10; count++)
    {
        LED_On(LED1);
        MXC_Delay(500000);
        LED_Off(LED1);
        MXC_Delay(500000);
        printf("count risc-v: %d\n", count);
    }

    // Signal the Cortex-M4
    MXC_SEMA->irq0 = MXC_F_SEMA_IRQ0_EN | MXC_F_SEMA_IRQ0_CM4_IRQ;

    return 0;
}
