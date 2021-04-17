/*
Descri��o: Incrementa o PORTD a cada interrup��o externa
em RB0/INT0
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

// declara��o de vari�veis
unsigned contador = 0;

// rotina de interrup��o
void interrupt(){ // vetor de interrup��o
     contador++;
     PORTD = contador;
     delay_ms(500);
     INTCON.INTF = 0; // apaga flag sinalizador de interrup��o
     }

void main(){
     TRISB.RB0 = 1; // pino RB0 como entrada
     TRISD = 0; // PORTD como saida
     PORTD = 0; // Apaga LEDs

// Habilita interrup��o pelo pino externo RB0/INT0
   INTCON = 0b10010000;
   // bit 7: interrup��o geral
   // bit 6: interrup��o de perif�ricos
   // bit 5: interrup��o por overflow do TIMER0
   // bit 4: interrup��o externa INT0
   // bit 3: interrup��o por troca dos bits em PORTB
   // bit 2: flag da interrup��o do TIMER0
   // bit 1: flag da interrup��o externa
   // bit 0: flag da interrup��o em PORTB

   while(1){
   }; // loop infinito aguardando a interrupcao
}



