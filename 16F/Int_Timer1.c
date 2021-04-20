/*
Descrição: Faz um LED piscar em 1Hz usando a interrupção do Timer1
1Hz = 1s = 0,5s em NL1 e 05s em NL0
Prescaler 1:8
TMR1 = 3036d = 0BDCh
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

//SAIDAS
#define LED PORTD.RD7

void interrupt(void){
     TMR1H = 0x0B; // recarrega TMR1
     TMR1L = 0XDC;
     PIR1.TMR1IF = 0; // limpa flag de interrupção do Timer1
     LED = ~LED;
}

void main(){
     TRISD.RD7 = 0; // configura LED como saída
     LED = 1; // inicializa LED

     PIE1 = 0b00000001; // habilita Timer1
     T1CON = 0b00111001; // Prescaler 1:8, T1OSCEN - Oscillator Enabled
                         // TMR1CS - Internal Clock, TMR1ON, Enable Timer1
     INTCON = 0b11000000; // Habilita GIE e PEIE
     TMR1H = 0x0B; // inicia TMR1
     TMR1L = 0xDC;

     while(1){}
}