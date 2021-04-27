/*
Descrição:
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/
//ENTRADAS
#define C PORTD.RD0
#define R PORTD.RD1
#define I PORTD.RD2

//SAIDAS
#define S PORTC.RC1 // Buzzer aciona com NL0

void main()
{
 TRISD=0xFF;
 TRISC=0X00;

 while(1) // Loop infinito
 {
  if((C&&!R)||(C&&I)) S = 0;
  else S = 1;
 }
}
