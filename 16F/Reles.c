/*
Descrição: Aciona e desaciona os relés em intervalo de 1 segundo. O kit
 PICGenios tem dois relés NA/NF, acionados através dos pinos
RC0 e RE0 repectivamente.
Dispositivo: PIC16F877A, cristal 4 MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main( ) {
     TRISC.RC0 = 0; //configura pino RC0 como saida
     TRISE.RE0 = 0; //configura pino RE0 como saida

     while(1){
               PORTE.RE0 = 1;
               PORTC.RC0 = 0;
               delay_ms(1000); //atraso de 1000 milisegundos (1 segundo)
               PORTE.RE0 = 0;
               PORTC.RC0 = 1;
               delay_ms(1000); //atraso de 1000 milisegundos (1 segundo)
     }
}