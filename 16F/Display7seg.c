/*
Descrição: Escreve o número 1234 no display de sete segmentos.
O kit possui 4 displays multiplexados com o barramento PORTD. Cada
display tem um pino de seleção:
        RD0 Segmento A
        RD1 Segmento B
        RD2 Segmento C
        RD3 Segmento D
        RD4 Segmento E
        RD5 Segmento F
        RD6 Segmento G
        RD7 Segmento Ponto
        RA2 Seleção do Display1 (Disp1 - MSB)
        RA3 Seleção do Display2 (Disp2)
        RA4 Seleção do Display3 (Disp3)
        RA5 Seleção do Display4 (Disp4 - LSB)
Dispositivo: PIC16F877A, cristal 4 MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main(){ // função principal do programa
         TRISA = 0; // porta como saida
         PORTA = 0; // zera todos os pinos do porta
         TRISD = 0; // portd como saida
         PORTD = 255; // zera todos os pinos do portd

         while(1) {
         PORTA.RA2= 1; //liga 1º display - MSB
         PORTD = 0b00000110; //escreve digito 1
         Delay_ms(1); //delay de 1ms
         PORTA.RA2= 0; //desliga 1º display - MSB

         PORTA.RA3= 1; //liga 2º display
         PORTD = 0b01011011; //escreve digito 2
         Delay_ms(1); //delay de 1ms
         PORTA.RA3= 0; //desliga 2º display

         PORTA.RA4= 1; //liga 3º display
         PORTD = 0b01001111; //escreve digito 3
         Delay_ms(1); //delay de 1ms
         PORTA.RA4= 0; //desliga 3º display

         PORTA.RA5= 1; //liga 4º display
         PORTD = 0b01100110; //escreve digito 4
         Delay_ms(1); //delay de 1ms
         PORTA.RA5= 0; //desliga 4º display
         }
}