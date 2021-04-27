/*
Descrição:
Prescaler = 32
  100Hz => 10ms. Logo Timer = 5ms => TMR0=100
  200Hz => 5ms. Logo Timer = 2,5ms => TMR0=178
  300Hz => 3,33ms. Logo Timer = 1,66ms => TMR0=204
  400Hz => 2,5ms. Logo Timer = 1,25ms => TMR0=217
  500Hz => 2ms. Logo Timer = 1ms => TMR0=225
  600Hz => 1,66ms. Logo Timer = 0,83ms => TMR0=230
  700Hz => 1,43ms. Logo Timer = 0,715ms => TMR0=234
  800Hz => 1,25ms. Logo Timer = 0,625ms => TMR0=236
  900Hz => 1,11ms. Logo Timer = 0,555ms => TMR0=239
  
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

char freq;

void interrupt(void){
     TMR0 = freq; // reinicia TMR0
     INTCON.TMR0IF = 0; // limpa flag de interrupção do Timer0
     PORTC.RC0 = ~PORTC.RC0 ; // inverte estado de RC0
}

void main(){
     char var; //define variável
     TRISD = 255; // Configura PORTD como entrada
     TRISB = 0; // Configura PORTB como saída
     PORTB = 255; // Inicializa PORTB
     TRISC = 0; // Configura PORTC como saída
  
     OPTION_REG = 0b10000100; // Prescaler = 32
     TMR0 = 100; // Inicia TMR0
     INTCON = 0b10100000;
     
     while(1){
              PORTB.RB1 = 0; //habilita primeira coluna do teclado
              var = PORTD;
              if (var.f0 == 0) freq=100; //lcdr("*");
              else if (var.f1 == 0) freq=234; //lcdr("7");
              else if (var.f2 == 0) freq=217;//lcdr("4");
              else if (var.f3 == 0) freq=100;//lcdr("1");
              PORTB.RB1 = 1; //desabilita primeira coluna do teclado

              PORTB.RB2 = 0; //habilita segunda coluna do teclado
              var = PORTD;
              if (var.f0 == 0) freq=100;//lcdr("0");
              else if (var.f1 == 0) freq=236;//lcdr("8");
              else if (var.f2 == 0) freq=225;//lcdr("5");
              else if (var.f3 == 0) freq=178;//lcdr("2");
              PORTB.RB2 = 1; //desabilita segunda coluna do teclado

              PORTB.RB0 = 0; //habilita terceira coluna do teclado
              var = PORTD;
              if (var.f0 == 0) freq=100;//lcdr("#");
              else if (var.f1 == 0) freq=239;//lcdr("9");
              else if (var.f2 == 0) freq=230;//lcdr("6");
              else if (var.f3 == 0) freq=204;//lcdr("3");
              PORTB.RB0 = 1; //desabilita terceira coluna do teclado
     }

}
