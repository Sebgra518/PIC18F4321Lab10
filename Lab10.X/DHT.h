//Modified Library from: Electronic Wings

#ifndef DHT_H
    #define	DHT_H

    #define _XTAL_FREQ 8000000  //Frequency of the sytem clock


    #include <xc.h>
    #include <stdio.h>

    #define Data_Out LATA0              /* assign Port pin for data*/
    #define Data_In PORTAbits.RA0       /* read data from Port pin*/
    #define Data_Dir TRISAbits.RA0      /* Port direction */

    void DHT11_Start();
    char DHT11_ReadData();
    void DHT11_CheckResponse();
#endif	/* DHT_H */