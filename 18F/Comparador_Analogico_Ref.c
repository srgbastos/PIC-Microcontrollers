/*
Descri��o: Exemplo de uso do Comparador Anal�gico (Reference Module).
   If CVRR = 1: CVREF = ((CVR3:CVR0)/24) x CVRSRC
   Exemplo: CVR3:CVR0 = 1100b = 12d
   CVREF = (12/24) x 5volts = 2,5 volts
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: SimulIDE
*/

void interrupt(){
   if(CMIF_bit){ // Verifica interrup��o de comparadores
      CMIF_bit = 0; // Limpa flag
      PORTD.RD0 = ~PORTD.RD0; // Inverte RD0
   }
}

void main() {
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISA = 0xCF; // Configura��o de PORTA
   TRISD = 0x00; // Configura��o de PORTD

   CMCON = 0x06; // Four Inputs Multiplexed to Two Comparators
   CVRCON = 0b10101100; // Vref interna = 2,5V
   GIE_bit = 1; // Interrup��o global
   PEIE_bit = 1; // Interrup��o por perif�ricos
   CMIE_bit = 1; // Habilita interrup��o do comparador anal�gico

   while(1){
      PORTD.RD2 = CMCON.C2OUT; // Conecta C2OUT ao pino RD2
      PORTD.RD1 = CMCON.C1OUT; // Conecta C2OUT ao pino RD1
   }
}
