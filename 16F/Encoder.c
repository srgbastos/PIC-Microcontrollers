/*
Descrição: Aciona a ventoinha (RC2) e faz a contagem das voltas
através do encoder (RC0)
Dispositivo: PIC16F877A
Compilador: mikroC
Simulador: PICSimLab
*/

void main() {

char contador = 0;
TRISD = 0; // configura porta D como saida
PORTD = 0; // apaga todos os LEDs da porta D
TRISC = 1; // Entrada em RC0
PORTC.RC2 = 1; // liga a ventoinha

while(1){
         while(PORTC.RC0 == 0)
         delay_ms(1);
         
         while(PORTC.RC0 == 1){
         delay_ms(1000);
         contador = contador + 1;
         PORTD = contador;
         }
         }
}