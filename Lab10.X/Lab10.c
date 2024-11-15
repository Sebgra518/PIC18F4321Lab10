#include <xc.h>
#include "pic18f4321-Config.h"
#include "LCD.h"
#include "DHT.h"

void main(void) {
    
    char H_num, H_decimal, T_num, T_decimal;
    
    OSCCON = 0x72;
    ADCON1=0x0F;
    
    LCD_init();
    while (1) {
        DHT11_Start(); //send start pulse
        DHT11_CheckResponse(); //wait for response
        
        //read 40-bit data from DHT11 module
        H_num = DHT11_ReadData();
        H_decimal = DHT11_ReadData();
        T_num = DHT11_ReadData(); 
        T_decimal = DHT11_ReadData(); 

        //Write Humidity
        LCD_cursor_set(1,1);
        LCD_write_string("Humidity: ");
        LCD_write_variable(H_num,0);
        LCD_write_string(".");
        LCD_write_variable(H_decimal,0);
        LCD_write_char('%');

        //Write Temperature
        LCD_cursor_set(2,1);
        LCD_write_string("Temp: ");
        LCD_write_variable(T_num,0);
        LCD_write_string(".");
        LCD_write_variable(T_decimal,0);
        LCD_write_char(0xdf);//Hex for degree symbol
        LCD_write_char('C');
        
        __delay_ms(500);
    }
    return;
    
}
