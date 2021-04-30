/*
Descrição: Contador crescente/decrescente em FSM.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

// Entradas
#define SENTIDO PORTD.RD0

// Saídas
#define LED0 PORTB.RB0
#define LED1 PORTB.RB1
#define LED2 PORTB.RB2

// Estados da FSM
#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7

int estado = 0; // Variável para armazenar o estado atual

void main(){
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISD = 0xFF; // PORTB como entrada
   TRISB = 0x00; // PORTD como saída
   PORTB = 0x00; // inicialização do PORTD

while(1){
   switch(estado){
      case S0:
         // Parte combinacional. Controla a saída (depende só dos Estados - máq Moore)
         LED0 = 0;
         LED1 = 0;
         LED2 = 0;
         // Parte sequencial. Lógica de controle do próximo estado
         if(SENTIDO) estado = S1;
         else estado = S7;
         break;

      case S1:
         LED0 = 1;
         LED1 = 0;
         LED2 = 0;
         if(SENTIDO) estado = S2;
         else estado = S0;
         break;

      case S2:
         LED0 = 0;
         LED1 = 1;
         LED2 = 0;
         if(SENTIDO) estado = S3;
         else estado = S1;
         break;

      case S3:
         LED0 = 1;
         LED1 = 1;
         LED2 = 0;
         if(SENTIDO) estado = S4;
         else estado = S2;
         break;

      case S4:
         LED0 = 0;
         LED1 = 0;
         LED2 = 1;
         if(SENTIDO) estado = S5;
         else estado = S3;
         break;

      case S5:
         LED0 = 1;
         LED1 = 0;
         LED2 = 1;
         if(SENTIDO) estado = S6;
         else estado = S4;
         break;

      case S6:
         LED0 = 0;
         LED1 = 1;
         LED2 = 1;
         if(SENTIDO) estado = S7;
         else estado = S5;
         break;

      case S7:
         LED0 = 1;
         LED1 = 1;
         LED2 = 1;
         if(SENTIDO) estado = S0;
         else estado = S6;
         break;

      default:
         estado = S0;
   } // fim do switch-case
   delay_ms(1000); // Executa a FSM a cada 1 segundo
   PORTB.RB7= ~PORTB.RB7; // Para visualizar o clock de 1 segundo da FSM
} // fim do loop infinito
} // fim do main