/*
Descri��o: Ao pressionar o bot�o (ativo em NL0), liga um led
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

//ENTRADAS
#define BOTAO PORTB.RB0
//#define BOTAO LATB0_bit  // Experimente usar esse comando

//SAIDAS
#define LED LATD6_bit

void main()
{
 ADCON1 = 0x0F; // Pinos de IO como digitais. Experimente tirar esse comando.
 TRISB=0b00000001; // Bits 7...1 como saida e Bit 0 como entrada (PORTB)
 TRISD=0; // Todos os pinos configurados como sa�da do PORTD
 PORTD=0X00; // inicializa��o do PORTD

 while(1) // Loop infinito
 {
   if(!BOTAO) LED = 1; //Ao pressionar o bot�o o led acende
   else LED=0;
 }
}