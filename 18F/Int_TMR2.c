/*
Descri��o: Timer2 com 50ms visto no oscilosc�pio.
T_overflow = (PR2 + 1) x (4/F_cristal) x Prescale x Postscale
0,05 = (PR2 + 1) x 1us x 16 x 16 -> PR2 = 194,31 = 194
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void interrupt(void){
   if(TMR2IF_bit){
   PR2 = 194; // reinicia PR2
   TMR2IF_bit = 0; // limpa flag de interrup��o do Timer2
   LATB.RB7 = ~LATB.RB7; // inverte estado dos LEDs
   } // fim_if
} // fim_fun��o

void main(){
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISB = 0b00000000; // configura PORTB como sa�da
   PORTB = 0x00; // inicializa PORTB

//   IPEN_bit
   GIE_bit = 1; // Habilita interrup��o global
   PEIE_bit = 1; // Habilita interrup��o de perif�ricos
   TMR2IE_bit = 1; // Habilita Timer2
   TMR2IP_bit = 1; // Timer2 com alta prioridade
   TMR2 = 0;
   PR2 = 194;
   T2CON = 0b01111111; // Postscale 1:16, TMR2_ON, Prescale 1:16

   while(1){} // fim_while
}// fim_main