/*
Descrição: Faz a leitura do canal 0 do ADC e mostra
o valor no display LCD.
Dispositivo: PIC16F877A, cristal 4 MHz
Bibliotecas: ADC, Conversions, C_String, Lcd
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

char texto[16]; // para mostrar no LCD
unsigned int valor_AD ; // para a leitura do ADC
float volts; // para mudar a escala desejada

void main () {
TRISD = 0x00; // define PortE como saida - LCD
TRISE = 0x00; // define PortE como saida - LCD
TRISA = 0xFF; // define PortA como entrada

// Inicializa o LCD
Lcd_Init (); // Inicializa o Display
Delay_ms (100) ;
Lcd_Cmd ( _LCD_CLEAR ); // limpa o Display
Delay_ms (100) ;
Lcd_Cmd ( _LCD_CURSOR_OFF ); // Desabilita o cursor
Delay_ms (100) ;
Lcd_Out (1,1,"Voltimetro [V]");
Delay_ms (100) ;

while(1){
         valor_AD =ADC_Read(0); // lê canal 0
         volts = (float)valor_AD*((float)1000/(float)1024);
         // converte valor volts em string
         FloatToStr(volts, texto);
         // envia para o LCD o valor string da conversão A/D
         Lcd_Out(2, 1, texto);
         delay_ms(100);
         }
}