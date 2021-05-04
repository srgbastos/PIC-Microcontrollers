/*
Descri��o: Interrup��o externa com prioridade. Cada interrup��o faz piscar um
led com frequ�ncia diferente.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

int i, j;

void interrupt(){ // Interrup��o de prioridade alta ao apertar INT1
   if(INT1IF_bit){ // Verifica flag da INT1
      //INT1IF_bit = 0; // Limpa flag da INT1
      for(i=0; i<20; i++){
         RD1_bit = ~RD1_bit; // Led em RD1 pisca 20 vezes com frequ�ncia 2Hz
         delay_ms(250);
      }
      INT1IF_bit = 0; // Limpa flag da INT1. Qual a diferen�a de limpar a
   }                  // flag no in�cio ou no fim da rotina de interrup��o?
}

void interrupt_low(){ // Interrup��o de prioridade baixa ao apertar INT2
   if(INT2IF_bit){ // Verifica flag da INT2
      //INT2IF_bit = 0; // Limpa flag da INT2
      for(j=0; j<20; j++){
         RD2_bit = ~RD2_bit; // Led em RD2 pisca 20 vezes com frequ�ncia 1Hz
         delay_ms(500);
      }
      INT2IF_bit = 0; // Limpa flag da INT2. Qual a diferen�a de limpar a
   }                  // flag no in�cio ou no fim da rotina de interrup��o?
}

void main(){
   ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
   TRISB = 0xFF; // Configura PORTB como entrada
   TRISD = 0x00; // Configura PORTD como sa�da
   PORTD = 0x00; // Inicializa PORTD em NL0


   RBPU_bit = 0; // Ativa os pull-ups internos do PORTB
   IPEN_bit = 1; // Habilita prioridade de interrup��o
   GIE_bit = 1; // Habilita interrup��o global
   PEIE_bit = 1; // Habilita interrup��o de perif�ricos

   INT1IE_bit = 1; // Habilita interrup��o externa INT1
   INT2IE_bit = 1; // Habilita interrup��o externa INT2

   INT1IP_bit = 1; // Configura prioridade alta para INT1
   INT2IP_bit = 0; // Configura prioridade baixa para INT2
   
   INTEDG1_bit = 0; // Ativa INT1 na borda de descida
   INTEDG2_bit = 0; // Ativa INT2 na borda de descida

while(1){}; // loop infinito

} // fim do main