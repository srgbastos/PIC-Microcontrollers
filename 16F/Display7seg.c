/*
Descri��o: Escreve o n�mero 1234 no display de sete segmentos.
O kit possui 4 displays multiplexados com o barramento PORTD. Cada
display tem um pino de sele��o:
        RD0 Segmento A
        RD1 Segmento B
        RD2 Segmento C
        RD3 Segmento D
        RD4 Segmento E
        RD5 Segmento F
        RD6 Segmento G
        RD7 Segmento Ponto
        RA2 Sele��o do Display1 (Disp1 - MSB)
        RA3 Sele��o do Display2 (Disp2)
        RA4 Sele��o do Display3 (Disp3)
        RA5 Sele��o do Display4 (Disp4 - LSB)
Dispositivo: PIC16F877A, cristal 4 MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main(){ // fun��o principal do programa
         TRISA = 0; // porta como saida
         PORTA = 0; // zera todos os pinos do porta
         TRISD = 0; // portd como saida
         PORTD = 255; // zera todos os pinos do portd

         while(1) {
         PORTA.RA2= 1; //liga 1� display - MSB
         PORTD = 0b00000110; //escreve digito 1
         Delay_ms(1); //delay de 1ms
         PORTA.RA2= 0; //desliga 1� display - MSB

         PORTA.RA3= 1; //liga 2� display
         PORTD = 0b01011011; //escreve digito 2
         Delay_ms(1); //delay de 1ms
         PORTA.RA3= 0; //desliga 2� display

         PORTA.RA4= 1; //liga 3� display
         PORTD = 0b01001111; //escreve digito 3
         Delay_ms(1); //delay de 1ms
         PORTA.RA4= 0; //desliga 3� display

         PORTA.RA5= 1; //liga 4� display
         PORTD = 0b01100110; //escreve digito 4
         Delay_ms(1); //delay de 1ms
         PORTA.RA5= 0; //desliga 4� display
         }
}