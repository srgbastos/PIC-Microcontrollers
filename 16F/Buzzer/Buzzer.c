/*
Descri��o: Ao pressionar o bot�o, aciona o buzzer enviando
NL0 no pino RC1. � preciso habilitar o buzzer atrav�s da chave
seletora.
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

//ENTRADAS
#define BOTAO portb.rb0

//SAIDAS
#define BUZZER portc.rc1

void main()
{
 TRISB=0b00000001; // Bits 7...1 como saida e Bit 0 como entrada (PORTB)
 TRISC=0; // Todos os pinos configurados como sa�da do PORTC
 PORTC=0X00; // inicializa��o do PORTC

 while(1) // Loop infinito
 {
          if(!BOTAO) BUZZER = 0; //Ao pressionar o bot�o, o buzzer aciona
          else BUZZER = 1;
 }
}
