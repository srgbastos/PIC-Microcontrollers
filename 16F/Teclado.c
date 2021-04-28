/*
Descrição: Configura o teclado e o LCD. O teclado matricial tem 12 teclas
multiplexadas no PORTD e PORTB do PIC. As teclas são ativas em NL0.

    RB1 RB2 RB0
RD3 1   2   3
RD2 4   5   6
RD1 7   8   9
RD0 *   0   #

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

void lcdr(char a[8]){
     TRISD = 0; // Configura PORTD como saída
     Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
     Lcd_Out_CP(a); // Escreve na posição atual do cursor
     TRISD = 255; // Configura PORTD como entrada
}

void main(){
     char var; //define variável
     TRISD = 0; // Configura PORTD como saída
     TRISE = 0; // Configura PORTE como saída

     Lcd_Init(); // Inicializa LCD
     Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
     Lcd_Cmd(_LCD_CURSOR_OFF); // Comando para desligar o cursor
     delay_ms(100);

     TRISD = 255; // Configura PORTD como entrada
     TRISB = 0; // Configura PORTB como saida
     PORTB = 255;

     while(1){
              PORTB.RB1 = 0; //habilita primeira coluna do teclado
              var = PORTD;
              if (var.f0 == 0) lcdr("*");
              else if (var.f1 == 0) lcdr("7");
              else if (var.f2 == 0) lcdr("4");
              else if (var.f3 == 0) lcdr("1");
              PORTB.RB1 = 1; //desabilita primeira coluna do teclado

              PORTB.RB2 = 0; //habilita segunda coluna do teclado
              var = PORTD;
              if (var.f0 == 0) lcdr("0");
              else if (var.f1 == 0) lcdr("8");
              else if (var.f2 == 0) lcdr("5");
              else if (var.f3 == 0) lcdr("2");
              PORTB.RB2 = 1; //desabilita segunda coluna do teclado

              PORTB.RB0 = 0; //habilita terceira coluna do teclado
              var = PORTD;
              if (var.f0 == 0) lcdr("#");
              else if (var.f1 == 0) lcdr("9");
              else if (var.f2 == 0) lcdr("6");
              else if (var.f3 == 0) lcdr("3");
              PORTB.RB0 = 1; //desabilita terceira coluna do teclado
     }
}