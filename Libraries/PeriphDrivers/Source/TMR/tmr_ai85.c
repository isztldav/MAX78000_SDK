#include "tmr.h"
#include "tmr_revb.h"
#include "tmr_common.h"
#include "lpgcr_regs.h"

int MXC_TMR_Init (mxc_tmr_regs_t *tmr, mxc_tmr_cfg_t* cfg)
{
    uint8_t tmr_id;
    uint8_t clockSource = MXC_TMR_CLK0;

    if (cfg == NULL) {
        return E_NULL_PTR;
    }

    tmr_id = MXC_TMR_GET_IDX (tmr);
    MXC_ASSERT(tmr_id >= 0);

    switch(cfg->clock){
    case MXC_TMR_60M_CLK:
        if (tmr_id > 3) {               // UARTs 4-5 do not support this clock source
            return E_NOT_SUPPORTED;
        }
        clockSource = MXC_TMR_CLK1;
        MXC_SYS_ClockSourceEnable(MXC_SYS_CLOCK_ISO);
        break;

    case MXC_TMR_8M_CLK:
        if (tmr_id > 3) {               // UARTs 4-5 do not support this clock source
            return E_NOT_SUPPORTED;
        }    
        clockSource = MXC_TMR_CLK2;
        MXC_SYS_ClockSourceEnable(MXC_SYS_CLOCK_IBRO);
        break;

    case MXC_TMR_32K_CLK:
        if(tmr_id == 4) {
            clockSource = MXC_TMR_CLK1;
        }
        else if (tmr_id < 4) {
            clockSource = MXC_TMR_CLK3;
        }
        else {                          // UART 5 do not support this clock source
            return E_NOT_SUPPORTED;
        }    
        MXC_SYS_ClockSourceEnable(MXC_SYS_CLOCK_ERTCO);
        break;

    case MXC_TMR_8K_CLK:
        if (tmr_id < 4) {               // UARTs 0-3 do not support this clock source
            return E_NOT_SUPPORTED;
        }
        clockSource = MXC_TMR_CLK2;
        MXC_SYS_ClockSourceEnable(MXC_SYS_CLOCK_INRO);
        break;

    default:
        break;
    }

    //enable peripheral clock and configure gpio pins
    switch (tmr_id) {
    case 0:
        MXC_SYS_Reset_Periph (MXC_SYS_RESET0_TMR0);
        while (MXC_GCR->rst0 & MXC_F_GCR_RST0_TMR0); //look into if this is needed and if so add to function above
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR0);
        if(cfg->bitMode != TMR_BIT_MODE_16B){
            MXC_GPIO_Config (&gpio_cfg_tmr0);
        } else {
            MXC_GPIO_Config (&gpio_cfg_tmr0b);
        }
        break;

    case 1:
        MXC_SYS_Reset_Periph (MXC_SYS_RESET0_TMR1);
        while (MXC_GCR->rst0 & MXC_F_GCR_RST0_TMR1);
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR1);
        if(cfg->bitMode != TMR_BIT_MODE_16B){
            MXC_GPIO_Config (&gpio_cfg_tmr1);
        } else {
            MXC_GPIO_Config (&gpio_cfg_tmr1b);
        }
        break;

    case 2:
        MXC_SYS_Reset_Periph (MXC_SYS_RESET0_TMR3);
        while (MXC_GCR->rst0 & MXC_F_GCR_RST0_TMR2);
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR2);
        if(cfg->bitMode != TMR_BIT_MODE_16B){
            MXC_GPIO_Config (&gpio_cfg_tmr2);
        } else {
            MXC_GPIO_Config (&gpio_cfg_tmr2b);
        }
        break;

    case 3:
        MXC_SYS_Reset_Periph (MXC_SYS_RESET0_TMR3);
        while (MXC_GCR->rst0 & MXC_F_GCR_RST0_TMR3);
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR3);
        if(cfg->bitMode != TMR_BIT_MODE_16B){
            MXC_GPIO_Config (&gpio_cfg_tmr3);
        } else {
            MXC_GPIO_Config (&gpio_cfg_tmr3b);
        }
        break;

    case 4:
        MXC_GPIO_Config (&gpio_cfg_tmr4);
        MXC_SYS_Reset_Periph (MXC_SYS_RESET_TMR4);
        while(MXC_LPGCR->rst & MXC_F_LPGCR_RST_TMR4);
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR4);
        break;

    case 5:
        MXC_GPIO_Config (&gpio_cfg_tmr5);
        MXC_SYS_Reset_Periph (MXC_SYS_RESET_TMR5);
        while(MXC_LPGCR->rst & MXC_F_LPGCR_RST_TMR5);
        MXC_SYS_ClockEnable (MXC_SYS_PERIPH_CLOCK_TMR5);
        break;
    }
    return MXC_TMR_RevB_Init (tmr, cfg, clockSource);
}

void MXC_TMR_Shutdown (mxc_tmr_regs_t *tmr)
{
    MXC_ASSERT (MXC_TMR_GET_IDX (tmr) >= 0);

    MXC_TMR_RevB_Shutdown (tmr);

    // System settigns
    //diasble peripheral clock
    if (tmr == MXC_TMR0) {
        MXC_SYS_ClockDisable (MXC_SYS_PERIPH_CLOCK_TMR0);
    }

    if (tmr == MXC_TMR1) {
        MXC_SYS_ClockDisable (MXC_SYS_PERIPH_CLOCK_TMR1);
    }

    if (tmr == MXC_TMR2) {
        MXC_SYS_ClockDisable (MXC_SYS_PERIPH_CLOCK_TMR2);
    }

    if (tmr == MXC_TMR3) {
        MXC_SYS_ClockDisable (MXC_SYS_PERIPH_CLOCK_TMR3);
    }

    if (tmr == MXC_TMR4) {
        MXC_LPGCR->pclkdis |= MXC_F_LPGCR_PCLKDIS_TMR4;
    }

    if (tmr == MXC_TMR5) {
        MXC_LPGCR->pclkdis |= MXC_F_LPGCR_PCLKDIS_TMR5;
    }
}

void MXC_TMR_Start (mxc_tmr_regs_t* tmr)
{
    MXC_TMR_RevB_Start (tmr);
}

void MXC_TMR_Stop (mxc_tmr_regs_t* tmr)
{
    MXC_TMR_RevB_Stop (tmr);
}

int MXC_TMR_SetPWM (mxc_tmr_regs_t* tmr, uint32_t pwm)
{
    return MXC_TMR_RevB_SetPWM (tmr,pwm);
}

uint32_t MXC_TMR_GetCompare (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_GetCompare (tmr);
}

uint32_t MXC_TMR_GetCapture (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_GetCapture (tmr);
}

uint32_t MXC_TMR_GetPeriod (mxc_tmr_regs_t* tmr, mxc_tmr_clock_t clock, uint32_t prescalar, uint32_t frequency)
{
    uint32_t clockFrequency = PeripheralClock;
    uint8_t tmr_id = MXC_TMR_GET_IDX (tmr);

    MXC_ASSERT (tmr_id >= 0);   

    if(tmr_id > 3) {
        switch(clock){
        case MXC_TMR_APB_CLK:
            clockFrequency = IBRO_FREQ;
            break;

        case MXC_TMR_32K_CLK:
            clockFrequency = ERTCO_FREQ;
            break;

        case MXC_TMR_8K_CLK:
            clockFrequency = INRO_FREQ;
            break;

        default:
            break;            
        }
    }
    else {
        switch(clock){
        case MXC_TMR_APB_CLK:
            clockFrequency = PeripheralClock;
            break;

        case MXC_TMR_60M_CLK:
            clockFrequency = ISO_FREQ;
            break;

        case MXC_TMR_8M_CLK:
            clockFrequency = IBRO_FREQ;
            break;

        case MXC_TMR_32K_CLK:
            clockFrequency = ERTCO_FREQ;      
            break;

        default:
            break;
        }
    }

    return MXC_TMR_RevB_GetPeriod (tmr, clockFrequency, prescalar, frequency);
}

uint32_t MXC_TMR_GetCount (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_GetCount (tmr);
}

void MXC_TMR_ClearFlags (mxc_tmr_regs_t* tmr)
{
    MXC_TMR_RevB_ClearFlags (tmr);
}

uint32_t MXC_TMR_GetFlags (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_GetFlags (tmr);
}

void MXC_TMR_EnableInt (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_EnableInt (tmr);
}

void MXC_TMR_DisableInt (mxc_tmr_regs_t* tmr)
{
    return MXC_TMR_RevB_DisableInt (tmr);
}

void MXC_TMR_SetCompare (mxc_tmr_regs_t *tmr, uint32_t cmp_cnt)
{
    MXC_TMR_RevB_SetCompare (tmr,cmp_cnt);
}

void MXC_TMR_SetCount (mxc_tmr_regs_t *tmr, uint32_t cnt)
{
    MXC_TMR_RevB_SetCount (tmr,cnt);
}

void MXC_TMR_Delay (mxc_tmr_regs_t *tmr, unsigned long us)
{
    MXC_TMR_Common_Delay (tmr,us);
}

void MXC_TMR_TO_Start (mxc_tmr_regs_t *tmr, unsigned long us)
{
    MXC_TMR_RevB_TO_Start (tmr,us);
}

int MXC_TMR_TO_Check (mxc_tmr_regs_t *tmr)
{
    return MXC_TMR_Common_TO_Check (tmr);
}

void MXC_TMR_TO_Stop (mxc_tmr_regs_t *tmr)
{
    MXC_TMR_Common_TO_Stop (tmr);
}

void MXC_TMR_TO_Clear (mxc_tmr_regs_t *tmr)
{
    MXC_TMR_Common_TO_Clear (tmr);
}

unsigned int MXC_TMR_TO_Elapsed (mxc_tmr_regs_t *tmr)
{
    return MXC_TMR_Common_TO_Elapsed (tmr);
}

unsigned int MXC_TMR_TO_Remaining (mxc_tmr_regs_t *tmr)
{
    return MXC_TMR_Common_TO_Remaining (tmr);
}

void MXC_TMR_SW_Start (mxc_tmr_regs_t *tmr)
{
    return MXC_TMR_Common_SW_Start (tmr);
}

unsigned int MXC_TMR_SW_Stop (mxc_tmr_regs_t *tmr)
{
    return MXC_TMR_Common_SW_Stop (tmr);
}

int MXC_TMR_GetTime (mxc_tmr_regs_t *tmr, uint32_t ticks, uint32_t *time, mxc_tmr_unit_t *units)
{
    return MXC_TMR_RevB_GetTime (tmr, ticks, time, units);
}