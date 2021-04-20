
//ENTRADAS
#define BT1 PORTB.RB0
#define BT2 PORTB.RB6

//SAIDAS
unsigned short shifter;

void main()
{
     TRISD = 0b11000000; // Bits 5...0 como saida e Bits 7...6 como entradas (PORTD)
     TRISB = 0b11111111;
//TRISC = 0; // Todos os pinos configurados como saída do PORTC
//PORTC = 0b00000011; // inicialização do PORTD
//PORTB = 0B00010000; // inicialização do PORTB
//Shifter = 0b00000011; // inicialização da variável shifter
          PORTD = 0;


while(1) // Loop infinito
{
         if(!BT1){
         PORTD = 0b00001000;
         delay_ms(500);
         PORTD = 0b00000100;
         delay_ms(500);
         PORTD = 0b00000010;
         delay_ms(500);
         PORTD = 0b00000001;
         delay_ms(500);
         }
         else{
         PORTD = 0b00000001;
         delay_ms(1500);
         PORTD = 0b00000010;
         delay_ms(1500);
         PORTD = 0b00000100;
         delay_ms(1500);
         PORTD = 0b00001000;
         delay_ms(1500);
         }
} //fim do loop infinito
}
