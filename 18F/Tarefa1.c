/* Tarefa 1
void interrupt(){ // Interrupção de prioridade alta ao apertar INT0
   if(INT0IF_bit){ // Verifica flag da INT0
      INT1IE_bit = ~INT1IE_bit;
      INT2IE_bit = ~INT2IE_bit;
      INT1IF_bit = 0;
      INT2IF_bit = 0;
      INT0IF_bit = 0; // Limpa flag da INT0.
   }
}

void interrupt_low(){ // Interrupção de prioridade baixa ao apertar INT2
   if(INT1IF_bit){ // Verifica flag da INT1
      PORTC.RC0 = 1; // Aciona relé1
      delay_ms(1000);
      PORTC.RC0 = 0;
      INT1IF_bit = 0; // Limpa flag da INT1.
   }

   else if(INT2IF_bit){ // Verifica flag da INT2
      //INT2IF_bit = 0; // Limpa flag da INT2
      PORTE.RE0 = 1; // Aciona relé2
      delay_ms(2000);
      PORTE.RE0 = 0;
      INT2IF_bit = 0; // Limpa flag da INT2.
   }
}

void main(){
ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
TRISB = 0xFF; // Configura PORTB como entrada
TRISC.RC0 = 0; // Configura RC0 como saída
TRISE.RE0 = 0; // Configura RE0 como saída
RBPU_bit = 0; // Ativa os pull-ups internos do PORTB
IPEN_bit = 1; // Habilita prioridade de interrupção
GIE_bit = 1; // Habilita interrupção global
PEIE_bit = 1; // Habilita interrupção de periféricos
INT0IE_bit = 1; // Habilita interrupção externa INT0
INT1IE_bit = 0; // Desabilita interrupção externa INT1
INT2IE_bit = 0; // Desabilita interrupção externa INT2
INT1IP_bit = 0; // Configura prioridade baixa para INT1
INT2IP_bit = 0; // Configura prioridade baixa para INT2
INTEDG0_bit = 0; // Ativa INT0 na borda de descida
INTEDG1_bit = 0; // Ativa INT1 na borda de descida
INTEDG2_bit = 0; // Ativa INT2 na borda de descida

while(1){ }; // loop infinito
} // fim do main
*/

// Tarefa 2

/*
Descrição: Configura Interrupção externa, Timer0 e Timer1
Timer0 (16bits - 1:256 - 5s) -> TMR0=46005d = B3B5h
Timer1 (16bits - 1:8 - 0,5s) -> TMR1=3036d ou 0BDCh
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void interrupt(){ // Interrupção de prioridade alta ao apertar INT0
   if(INT0IF_bit){ // Verifica flag da INT0
      TMR0IE_bit = ~TMR0IE_bit;
      TMR1IE_bit = ~TMR1IE_bit;
      
      TMR0IF_bit = 0;
      TMR1IF_bit = 0;
      
      INT0IF_bit = 0; // Limpa flag da INT0.
   }
   else if(TMR0IF_bit){
      TMR0H = 0xB3; // reinicia TMR0H
      TMR0L = 0xB5; // reinicia TMR0L
      LATB.RB7 = ~LATB.RB7; // inverte estado dos LEDs
      TMR0IF_bit = 0; // limpa flag de interrupção do Timer0
   } // fim_if
}

void interrupt_low(){ // Interrupção de prioridade baixa
   if(TMR1IF_bit){ // Verifica flag do Timer1
      TMR1H = 0x0B; // reinicia TMR1H
      TMR1L = 0xDC; // reinicia TMR1L
      LATB.RB6 = ~LATB.RB6; // inverte estado dos LEDs
      TMR1IF_bit = 0; // limpa flag de interrupção do Timer1
   }
}

void main(){
ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
TRISB = 0b00000001; // Configura PORTB
// Configurações gerais
GIE_bit = 1; // Habilita interrupção global
PEIE_bit = 1; // Habilita interrupção de periféricos
IPEN_bit = 1; // Habilita prioridade de interrupção

// Configurações para INT0
RBPU_bit = 0; // Ativa os pull-ups internos do PORTB
INT0IE_bit = 1; // Habilita interrupção externa INT0
INTEDG0_bit = 0; // Ativa INT0 na borda de descida

// Configurações para o Timer0
T0CON = 0b10000111; // Timer0_ON, 16bits, Internal_clock, 1:256
TMR0H = 0xB3; // Inicia TMR0H
TMR0L = 0xB5; // Inicia TMR0L
TMR0IP_bit = 1; // Timer0 com prioridade alta
TMR0IE_bit = 0; // Timer0 desabilitado

// Configurações para o Timer1
T1CON = 0b10111001; // 16bits, 1:8, Internal clock, Timer1_ON
TMR1H = 0x0B; // Inicia TMR1H
TMR1L = 0xDC; // Inicia TMR1L
TMR1IP_bit = 0; // Timer1 com prioridade baixa
TMR1IE_bit = 0; // Timer1 desabilitado

while(1){ }; // loop infinito
} // fim do main