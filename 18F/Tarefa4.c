/* TAREFA1
Descrição: Exemplo de uso do Comparador Analógico com interrupção.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: SimulIDE
*/

/*
void interrupt(){
   if(CMIF_bit){ // Verifica interrupção de comparadores
      PIR2.CMIF = 0;
      if(C1OUT_bit) PORTD.RD7 = ~PORTD.RD7;
   }
}

void main() {
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISA = 0xCF; // Configuração de PORTA
   TRISD=0x00; // Configuração de PORTD

   INTCON.GIE = 1;
   INTCON.PEIE = 1;
   PIE2.CMIE = 1;
   CMCON = 0x02; // Two Independent Comparators

   while(1){
      PORTD.RD2 = CMCON.C2OUT; // Conecta C2OUT ao pino RD2
      PORTD.RD1 = CMCON.C1OUT; // Conecta C2OUT ao pino RD1
   }
}
*/

// TAREFA2

/*
Descrição: Exemplo de uso da EEPROM interna. Ler pag. 294 do manual MikroC.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC - Biblioteca Eeprom
Simulador: SimulIDE
*/

void main(){
   ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
   TRISB = 255;
   TRISD = 0;
   PORTD = 0;

   while(1){
      EEPROM_Write(0x02, PORTB);
      delay_ms(100);
      PORTD = EEPROM_Read(0x02);
      delay_ms(100);
   }
}

