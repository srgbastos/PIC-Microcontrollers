/*
Descrição: Blink
Dispositivo: PIC18F4550, 16MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main()
{
 ADCON1 = 0x0F;          // Pinos de IO como digitais
 TRISB = 0b01111110;     // RB0 e RB7 como saídas
 PORTB = 0;              // Inicializar PORTB

 while(1)
    {
     LATB0_bit = 1;      // RB0 em NL1, usando LATB, ao invés de PORTB
     LATB7_bit = 0;      // RB7 em NL0
     delay_ms(500);
     LATB0_bit = 0;
     LATB7_bit = 1;
     delay_ms(500);
    }
}