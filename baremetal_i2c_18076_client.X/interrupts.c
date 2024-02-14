#include "interrupts.h"
#include "mssp1_client.h"

#include <xc.h>

void initInterrupts(void)
{
    INTCONbits.PEIE = 1;                                                        // Enable peripheral interrupts
    INTCONbits.GIE = 1;                                                         // Enable global interrupts
}

volatile int state = 0;


// Runs once when arduino starts i2c comms, but never again for some reason
void __interrupt() ISR(void)
{
//    state = !state;
//    PORTCbits.RC3 = state;
    // Neither of these bits ever seem to be set
    if ((PIR1bits.SSP1IF) || (PIR2bits.BCL1IF))
    {        
        //Call I2C Handler
        _MSSP_ProcessInterrupt();
    }
//    INTCONbits.GIE = 1;                                                         // Enable global interrupts
}
