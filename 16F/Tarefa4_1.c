/*
Descrição: Gera onda quadrada de 100 Hz em RD0.
TMR0 = 217 e Prescaler = 128 -> (5 ms)
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

void interrupt(void){
     TMR0 = 217; // reinicia TMR0
     INTCON.TMR0IF = 0; // limpa flag de interrupção do Timer0
     PORTD.RD0 = ~PORTD.RD0 ; // inverte estado de RD0
}

void main(){
     TRISD = 0; // configura PORTD como saida
     PORTD.RD0 = 1; // inicializa PORTD
     OPTION_REG = 0b10000110;
     TMR0 = 217; // Inicia TMR0
     INTCON = 0b10100000;
     while(1){}
}
