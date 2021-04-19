/*
Descrição: Pisca os leds do PortB em intervalos de 5 segundos
utilizando o TIMER0.
TMR0 = 217 (10 ms)
contagem = 500
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

unsigned int contagem;

void interrupt(void){
     contagem++; // incrementa variável de contagem
     TMR0 = 217; // reinicia TMR0
     INTCON.TMR0IF = 0; // limpa flag de interrupção do Timer0

     if(contagem == 500){
     PORTB = ~PORTB ; // inverte estado dos LEDs
     contagem = 0; // reinicia contagem
     }
}

void main(){

     contagem = 0; // inicializa contador

     TRISB = 0; // configura PORTB como saida
     PORTB = 0xFF; // inicializa PORTB

     OPTION_REG = 0b10000111;
     // bit 7 RBPU: PORTB Pull-up Enable bit
     // bit 6 INTEDG: Interrupt Edge Select bit
     // bit 5 T0CS: TMR0 Clock Source Select bit
     // bit 4 T0SE: TMR0 Source Edge Select bit
     // bit 3 PSA: Prescaler Assignment bit
     // bit 2-0 PS2:PS0: Prescaler Rate Select bits

     TMR0 = 217; // Inicia TMR0

     INTCON = 0b10100000;
     // bit 7: interrupção geral
     // bit 6: interrupção de periféricos
     // bit 5: interrupção por overflow do TIMER0
     // bit 4: interrupção externa INT0
     // bit 3: interrupção por troca dos bits em PORTB
     // bit 2: flag da interrupção do TIMER0
     // bit 1: flag da interrupção externa
     // bit 0: flag da interrupção em PORTB

     while(1){}
}



