/*
Descrição: Ao pressionar o botão, aciona o buzzer enviando
NL0 no pino RC1. É preciso habilitar o buzzer através da chave
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
 TRISC=0; // Todos os pinos configurados como saída do PORTC
 PORTC=0X00; // inicialização do PORTC

 while(1) // Loop infinito
 {
          if(!BOTAO) BUZZER = 0; //Ao pressionar o botão, o buzzer aciona
          else BUZZER = 1;
 }
}
