/*
Descri��o: Exemplo de uso do Comparador Anal�gico.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: SimulIDE
*/

void main() {
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISA = 0xCF; // Configura��o de PORTA
   TRISD=0x00; // Configura��o de PORTD
   CMCON = 0x02; // Two Independent Comparators

   while(1){
      PORTD.RD2 = CMCON.C2OUT; // Conecta C2OUT ao pino RD2
      PORTD.RD1 = CMCON.C1OUT; // Conecta C2OUT ao pino RD1
   }
}
