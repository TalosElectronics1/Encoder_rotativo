#include "Encoder_rotativo.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Tipo de objeto Nombre(pin_dt, pin_clk, pin_sw);
Encoder_rotativo Encoder_1(6,7,5);
LiquidCrystal_I2C lcd(0x27,16,2); 


int Periodo = 100;
int Voltaje = 127;
int Corriente = 9;
int Menu;


void setup()
{
    Serial.begin(9600);
    pinMode(13,OUTPUT); 
    Encoder_1.init();

    lcd.init();// Inicializar el LCD
    lcd.backlight();//Encender la luz de fondo.
   // lcd.print("Hola Mundo");// Escribimos el Mensaje en el LCD.

}
void loop()
{
    if (Encoder_1.read_sw()) 
    {
        while(Encoder_1.read_sw())
        {
            delay(10);
        }
        Menu++;
        if(Menu>=3)
        {
            Menu=0;
        }
    }
    
    switch (Menu)
    {
        case 0:
            Periodo = Periodo + Encoder_1.read_data();
            lcd.setCursor(0,0);
            lcd.print("Periodo      ");
            lcd.setCursor(0,1);
            lcd.print(Periodo);
            lcd.print(" ms   ");
        break;

        case 1:
            Voltaje = Voltaje + Encoder_1.read_data();
            lcd.setCursor(0,0);
            lcd.print("Voltaje Ac   ");
            lcd.setCursor(0,1);
            lcd.print(Voltaje);
            lcd.print(" v   ");
        break;

        case 2:
            Corriente = Corriente + Encoder_1.read_data();
            lcd.setCursor(0,0);
            lcd.print("Corriente   ");
            lcd.setCursor(0,1);
            lcd.print(Corriente);
            lcd.print(" A   ");
        break;
    
     

    }

    
    
}