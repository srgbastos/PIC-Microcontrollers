/*
Descrição: Contador de eventos com o Timer1
Dispositivo: PIC16F877A
Compilador: mikroC. Bibliotecas Lcd e Conversions
Simulador: PICSimLab
*/

// pinagem do LCD
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

// declaração de variáveis
char texto[16];
unsigned int contador = 0;

void main() {
     TRISD = 0; // configura PORTD como saída
     TRISE = 0; // configura PORTE como saída
     TRISC = 0x01; // configura PORTC.RC0 como entrada
     PORTC.RC2 = 1; // liga a ventoinha

     Lcd_Init(); // Inicializa o Display
     delay_ms(100) ;
     Lcd_Cmd(_LCD_CLEAR);
     delay_ms(100) ;
     Lcd_Cmd(_LCD_CURSOR_OFF);
     delay_ms(100) ;
     Lcd_Out(1,1,"Contagem: ");
     delay_ms(100) ;

     T1CON = 0b10000011; // liga TIMER1, prescaler 1:1, modo 16 bits, clock externo

     TMR1H = 0x00; //// carrega valor de contagem inicial do TIMER1
     TMR1L = 0x00;

     while(1){
        contador = TMR1L; // lê o valor do timer1, parte baixa
        contador = contador + TMR1H*256; // lê o valor do timer1, parte alta
        WordToStr(contador, texto); // converte para string
        Lcd_Out(2,1,texto); // escreve variavel texto
        delay_ms(100) ;
     }
}