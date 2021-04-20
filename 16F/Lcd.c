/*
Descrição: Escreve a mensagem Hello World no LCD.
O simulador tem os seguintes pinos conectados:
RE2 Pulso de comando (RS)
RE1 Pulso de ENABLE (EN)
RD0 DATA0 do display
RD1 DATA1 do display
RD2 DATA2 do display
RD3 DATA3 do display
RD4 DATA4 do display
RD5 DATA5 do display
RD6 DATA6 do display
RD7 DATA7 do display
Dispositivo: PIC16F877A, cristal 4 MHz
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


char mensagem1[] = "Hello";
char mensagem2[] = "World";

void main(){
  Lcd_Init(); // Inicializa LCD
  Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
  Lcd_Cmd(_LCD_CURSOR_OFF); // Comando para desligar o cursor
  Lcd_Out(1,6,mensagem1); // Escreve a mensagem1 na 1º linha, 6º coluna
  Lcd_Out(2,6,mensagem2); // Escreve a mensagem2 na 2º linha, 6º coluna
}