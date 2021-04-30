/*
Descrição: FSM da Máquina de Lavar.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

// Conexões do módulo LCD
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

// Entradas
#define INICIO PORTD.RD0
#define CHEIO PORTD.RD1
#define TEMPO PORTD.RD2
#define SECAR PORTD.RD3

// Saídas
#define VALVULA_AGUA PORTB.RB0
#define MODO_AGITAR PORTB.RB1
#define MODO_GIRAR PORTB.RB2

// Estados da FSM
#define ESPERA 0
#define ENCHER 1
#define AGITAR 2
#define GIRAR 3

int estado = 0; // Variável para armazenar o estado atual

void main(){
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISB = 0x00; // PORTB como saída
   PORTB = 0x00; // inicialização do PORTD
   TRISD = 0x0F; // Configura PORTD como saída e entrada
   TRISE = 0; // Configura PORTE como saída

   Lcd_Init(); // Inicializa LCD
   Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
   Lcd_Cmd(_LCD_CURSOR_OFF); // Comando para desligar o cursor
   Lcd_Out(1,1,"Estado: "); // Escreve a mensagem na 1º linha, 1º coluna
   delay_ms(100);

while(1){
   switch(estado){
      case ESPERA:
         // Parte combinacional. Controla a saída (depende só dos Estados - máq Moore)
         Lcd_Out(1,9,"Espera");
         VALVULA_AGUA = 0;
         MODO_AGITAR = 0;
         MODO_GIRAR = 0;
         // Parte sequencial. Lógica de controle do próximo estado
         if(INICIO) estado = ENCHER;
         else estado = ESPERA;
         break;

      case ENCHER:
         Lcd_Out(1,9,"Encher");
         VALVULA_AGUA = 1;
         MODO_AGITAR = 0;
         MODO_GIRAR = 0;
         if(CHEIO) estado = AGITAR;
         else estado = ENCHER;
         break;

      case AGITAR:
         Lcd_Out(1,9,"Agitar");
         VALVULA_AGUA = 0;
         MODO_AGITAR = 1;
         MODO_GIRAR = 0;
         if(TEMPO) estado = GIRAR;
         else estado = AGITAR;
         break;

      case GIRAR:
         Lcd_Out(1,9,"Girar ");
         VALVULA_AGUA = 0;
         MODO_AGITAR = 0;
         MODO_GIRAR = 1;
         if(SECAR) estado = GIRAR;
         else estado = ESPERA;
         break;

      default:
         estado = ESPERA;
   } // fim do switch-case
   delay_ms(1000); // Executa a FSM a cada 1 segundo
   PORTB.RB7= ~PORTB.RB7; // Para visualizar o clock de 1 segundo da FSM
} // fim do loop infinito
} // fim do main







/*
Descrição: Contador crescente/decrescente em FSM e LCD.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab


// Conexões do módulo LCD
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;


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
   TRISB = 0x00; // PORTB como saída
   PORTB = 0x00; // inicialização do PORTD
   TRISD = 0x01; // Configura PORTD como saída
   TRISE = 0; // Configura PORTE como saída

   Lcd_Init(); // Inicializa LCD
   Lcd_Cmd(_LCD_CLEAR); // Comando para limpar o display
   Lcd_Cmd(_LCD_CURSOR_OFF); // Comando para desligar o cursor
   Lcd_Out(1,1,"Estado: "); // Escreve a mensagem na 1º linha, 1º coluna
   delay_ms(100);

     //TRISD = 255; // Configura PORTD como entrada


while(1){
   switch(estado){
      case S0:
         // Parte combinacional. Controla a saída (depende só dos Estados - máq Moore)
         Lcd_Out(1,9,"S0");
         LED0 = 0;
         LED1 = 0;
         LED2 = 0;
         // Parte sequencial. Lógica de controle do próximo estado
         if(SENTIDO) estado = S1;
         else estado = S7;
         break;

      case S1:
         Lcd_Out(1,9,"S1");
         LED0 = 1;
         LED1 = 0;
         LED2 = 0;
         if(SENTIDO) estado = S2;
         else estado = S0;
         break;

      case S2:
         Lcd_Out(1,9,"S2");
         LED0 = 0;
         LED1 = 1;
         LED2 = 0;
         if(SENTIDO) estado = S3;
         else estado = S1;
         break;

      case S3:
         Lcd_Out(1,9,"S3");
         LED0 = 1;
         LED1 = 1;
         LED2 = 0;
         if(SENTIDO) estado = S4;
         else estado = S2;
         break;

      case S4:
         Lcd_Out(1,9,"S4");
         LED0 = 0;
         LED1 = 0;
         LED2 = 1;
         if(SENTIDO) estado = S5;
         else estado = S3;
         break;

      case S5:
         Lcd_Out(1,9,"S5");
         LED0 = 1;
         LED1 = 0;
         LED2 = 1;
         if(SENTIDO) estado = S6;
         else estado = S4;
         break;

      case S6:
         Lcd_Out(1,9,"S6");
         LED0 = 0;
         LED1 = 1;
         LED2 = 1;
         if(SENTIDO) estado = S7;
         else estado = S5;
         break;

      case S7:
         Lcd_Out(1,9,"S7");
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

*/