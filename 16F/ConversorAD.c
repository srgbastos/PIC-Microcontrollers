/*
Descrição: Faz a leitura dos dois canais ADC e mostra
o valor no display LCD.
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

char texto[16];
int temp_res = 0;
int temp_res2 = 0;

void main() {
     Lcd_Init(); // Inicializa LCD
     Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
     Lcd_Cmd(_LCD_CURSOR_OFF); // Comando para desligar o cursor
     Lcd_Out(1,1,"Canal AN0: "); // Escreve a mensagem1 na 1º linha, 6º coluna
     delay_ms(100);
     Lcd_Out(2,1,"Canal AN1: "); // Escreve a mensagem1 na 1º linha, 6º coluna
     delay_ms(100);

     while(1){
     temp_res = ADC_Read(0); //le canal ad0 do PIC e salva valor na variável temp_res
     temp_res2 = ADC_Read(1); //lê canal ad1 do PIC e salva valor na variável temp_res2
     Delay_10us; //delay de 10 microsegundos

     wordToStr(temp_res, texto); //converte valor da conversão do ad0 para string
     Lcd_Out(1,11,texto); //
     delay_ms(100);

     WordToStr(temp_res2, texto); //converte valor da conversão do ad1 para string
     Lcd_Out(2,11,texto); //
     delay_ms(100);
     }
}