#include <xc.h>
#include "pic18f4321-Config.h"
#include "LCD.h"
#include "DHT.h"

void main(void) {
    
    char RH_Decimal, RH_Integral, T_Decimal, T_Integral;
    char value[10];

    
    OSCCON = 0x72;
    ADCON1=0x0F;
    
    LCD_init();
    while (1) {
        DHT11_Start(); /* send start pulse to DHT11 module */
        DHT11_CheckResponse(); /* wait for response from DHT11 module */
        
        /* read 40-bit data from DHT11 module */
        RH_Integral = DHT11_ReadData();
        RH_Decimal = DHT11_ReadData();
        T_Integral = DHT11_ReadData(); 
        T_Decimal = DHT11_ReadData(); 

        /* convert humidity value to ascii and send it to display*/
        LCD_cursor_set(1,1);
        LCD_write_string("Humidity: ");
        sprintf(value, "%d", RH_Integral);
        LCD_write_string(value);
        sprintf(value, ".%d ", RH_Decimal);
        LCD_write_string(value);
        LCD_write_char('%');

        /* convert temperature value to ascii and send it to display*/
        LCD_cursor_set(2,1);
        LCD_write_string("Temp: ");
        sprintf(value, "%d", T_Integral);
        LCD_write_string(value);
        sprintf(value, ".%d", T_Decimal);
        LCD_write_string(value);
        LCD_write_char(0xdf);
        LCD_write_char('C');
        
        
        __delay_ms(500);
    }
    return;
    
}
