/*
Descrição:

Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

// Conexões do módulo LCD
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

void main() {

char texto[16]; // para mostrar no LCD
char contador = 0;

// Inicializa o LCD
Lcd_Init (); // Inicializa o Display
Delay_ms (100) ;
Lcd_Cmd (_LCD_CLEAR); // limpa o Display
Delay_ms (100) ;
Lcd_Cmd (_LCD_CURSOR_OFF); // Desabilita o cursor
Delay_ms (100) ;
Lcd_Out (1,1,"Encoder:");
Delay_ms (100) ;

TRISC = 1; // Entrada em RC0
PORTC.RC2 = 1; // liga a ventoinha

while(1){
         while(PORTC.RC0 == 0)
         delay_ms(1);

         while(PORTC.RC0 == 1){
         delay_ms(1000);
         contador = contador + 1;

         IntToStr(contador, texto);
         Lcd_Out(2, 1, texto);
         delay_ms(100);
         }
    }
}