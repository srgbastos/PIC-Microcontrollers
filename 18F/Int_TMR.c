/*
Descrição: Pisca o led 7 do PORTB em intervalos de 5 segundos
utilizando o TIMER0. Pisca led 6 com delay_ms(500).

Para 8 bits: T_overflow = (256 - TMR0L)x(4/F_cristal)xPrescaler
Para 16 bits: T_overflow = (65536 - TMR0)x(4/F_cristal)xPrescaler
   5 = (65536 - TMR0) x 1us x 256
   TMR = 46005d = B3B5h
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void interrupt(void){
   if(INTCON.TMR0IF==1){
   TMR0H = 0xB3; // reinicia TMR0H
   TMR0L = 0xB5; // reinicia TMR0L
   INTCON.TMR0IF=0; // limpa flag de interrupção do Timer0
   LATB.RB7 = ~LATB.RB7; // inverte estado dos LEDs
   } // fim_if
} // fim_função

void main(){
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISB = 0b00000000; // configura PORTB como saída
   PORTB = 0x00; // inicializa PORTB

   T0CON = 0b10000111; // Timer0_ON, 16bits, Internal_clock, 1:256
   TMR0H = 0xB3; // Inicia TMR0H
   TMR0L = 0xB5; // Inicia TMR0L

   INTCON.GIE = 1; // Global Interrupt Enable bit
   INTCON.TMR0IE = 1; // Timer0 Interrupt Enable bit

   RCON.IPEN = 1; // Interrupt Priority Enable. Bit=1 Enable priority levels on interrupts
   INTCON2.TMR0IP = 1; // TMR0IP: High Priority

   while(1){
      LATB.RB6 = ~LATB.RB6;
      delay_ms(500);
   } // fim_while
}// fim_main