/*
Descrição: Incrementa o PORTD a cada interrupção externa
em RB0/INT0
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

// declaração de variáveis
unsigned contador = 0;

// rotina de interrupção
void interrupt(){ // vetor de interrupção
     contador++;
     PORTD = contador;
     delay_ms(500);
     INTCON.INTF = 0; // apaga flag sinalizador de interrupção
     }

void main(){
     TRISB.RB0 = 1; // pino RB0 como entrada
     TRISD = 0; // PORTD como saida
     PORTD = 0; // Apaga LEDs

// Habilita interrupção pelo pino externo RB0/INT0
   INTCON = 0b10010000;
   // bit 7: interrupção geral
   // bit 6: interrupção de periféricos
   // bit 5: interrupção por overflow do TIMER0
   // bit 4: interrupção externa INT0
   // bit 3: interrupção por troca dos bits em PORTB
   // bit 2: flag da interrupção do TIMER0
   // bit 1: flag da interrupção externa
   // bit 0: flag da interrupção em PORTB

   while(1){
   }; // loop infinito aguardando a interrupcao
}



