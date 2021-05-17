
/*
Descrição: Timer0 (10ms), Timer1 (20 ms), Timer2 (30 ms) e Timer3 (40 ms)
vistos no osciloscópio.

Timer0
  Para 8 bits: T_overflow = (256 - TMR0L)x(4/F_cristal)xPrescaler
  Para 16 bits: T_overflow = (65536 - TMR0)x(4/F_cristal)xPrescaler
  0,01 = (65536 - TMR0) x 1us x 2 -> TMR0 = 60536d = EC78h

Timer1
  T_overflow = (65536 - TMR1)x(4/F_cristal)xPrescaler
  0,02 = (65536 - TMR1) x 1us x 1 -> TMR1 = 45536d = B1E0h

Timer2
  T_overflow = (PR2 + 1) x (4/F_cristal) x Prescale x Postscale
  0,03 = (PR2 + 1) x 1us x 16 x 16 -> PR2 = 116d

Timer3
  T_overflow = (65536 - TMR1)x(4/F_cristal)xPrescaler
  0,04 = (65536 - TMR1) x 1us x 1 -> TMR1 = 25536d = 63C0h

Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void interrupt(){ // interrupção de prioridade alta
   if(TMR0IF_bit){ // Verifica flag do Timer0
      TMR0H = 0xEC; // reinicia TMR0H
      TMR0L = 0x78; // reinicia TMR0L
      LATD.RD0 = ~LATD.RD0; // inverte estado dos LEDs
      TMR0IF_bit = 0; // limpa flag de interrupção do Timer0
   } // fim_if
   else if(TMR2IF_bit){ // Verifica flag do Timer2
      PR2 = 116; // reinicia PR2
      TMR2IF_bit = 0; // limpa flag de interrupção do Timer2
      LATD.RD2 = ~LATD.RD2; // inverte estado dos LEDs
   } // fim_if

}

void interrupt_low(){ // Interrupção de prioridade baixa
   if(TMR1IF_bit){ // Verifica flag do Timer1
      TMR1H = 0xB1; // reinicia TMR1H
      TMR1L = 0xE0; // reinicia TMR1L
      LATD.RD1 = ~LATD.RD1; // inverte estado dos LEDs
      TMR1IF_bit = 0; // limpa flag de interrupção do Timer1
   }
   else if(TMR3IF_bit){ // Verifica flag do Timer3
      TMR3H = 0x63; // reinicia TMR3H
      TMR3L = 0xC0; // reinicia TMR3L
      LATD.RD3 = ~LATD.RD3; // inverte estado dos LEDs
      TMR3IF_bit = 0; // limpa flag de interrupção do Timer1
   }
}

void main(){
ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
TRISD = 0; // Configura PORTD como saída
PORTD = 0; // Valor inicial de PORTD

// Configurações gerais
GIE_bit = 1; // Habilita interrupção global
PEIE_bit = 1; // Habilita interrupção de periféricos
IPEN_bit = 1; // Habilita prioridade de interrupção

// Configurações para o Timer0
T0CON = 0b10000000; // Timer0_ON, 16bits, Internal_clock, 1:2
TMR0H = 0xFF; // Inicia TMR0H
TMR0L = 0xD9; // Inicia TMR0L
TMR0IP_bit = 1; // Timer0 com prioridade alta
TMR0IE_bit = 1; // Timer0 habilitado

// Configurações para o Timer1
T1CON = 0b10001001; // 16bits, 1:1, Internal clock, Timer1_ON
TMR1H = 0xB1; // Inicia TMR1H
TMR1L = 0xE0; // Inicia TMR1L
TMR1IP_bit = 0; // Timer1 com prioridade baixa
TMR1IE_bit = 1; // Timer1 habilitado

// Configurações para o Timer2
T2CON = 0b01111111; // Postscale 1:16, TMR2_ON, Prescale 1:16
TMR2 = 0; // Inicia TMR2
PR2 = 116; // Inicia PR2
TMR2IP_bit = 1; // Timer2 com alta prioridade
TMR2IE_bit = 1; // Timer2 habilitado

// Configurações para o Timer3
T3CON = 0b10000001; // 16bits, 1:1, Internal clock, Timer3_ON
TMR3H = 0x63; // Inicia TMR3H
TMR3L = 0xC0; // Inicia TMR3L
TMR3IP_bit = 0; // Timer3 com prioridade baixa
TMR3IE_bit = 1; // Timer3 habilitado

while(1){ }; // loop infinito
} // fim do main