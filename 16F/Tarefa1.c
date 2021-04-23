/*
//ENTRADAS
#define BOTAO1 portb.rb3
#define BOTAO2 portb.rb4
#define BOTAO3 portb.rb5

//SAIDAS
#define LED1 portd.rd0
#define LED2 portd.rd1
#define LED3 portd.rd2
#define LED4 portd.rd3

void main()
{
     TRISB = 0xFF;
     TRISD = 0x00;
     PORTD = 0x00;

     while(1)
     {
             if(!BOTAO1) LED1 = 1;
             else LED1 = 0;
             
             if(!BOTAO2) LED2 = 0;
             else LED2 = 1;
             
             if(!BOTAO3){
                LED3 = 1;
                LED4 = 1;
             }
             else{
                LED3 = 0;
                LED4 = 0;
             }
     }
}
*/

/* EXERCICIO2
void main(){ // função principal do programa
     TRISA = 0; // porta como saida
     PORTA.RA2 = 1; // seleciona Disp1
     TRISD = 0; // portd como saida
     PORTD = 0; // zera todos os pinos do PORTD

     while(1)
     {
             PORTD = 0b00111111; //0
             Delay_ms(1000);
             PORTD = 0b00000110; //1
             Delay_ms(1000);
             PORTD = 0b01011011; //2
             Delay_ms(1000);
             PORTD = 0b01001111; //3
             Delay_ms(1000);
             PORTD = 0b01100110; //4
             Delay_ms(1000);
             PORTD = 0b01101101; //5
             Delay_ms(1000);
             PORTD = 0b01111101; //6
             Delay_ms(1000);
             PORTD = 0b00000111; //7
             Delay_ms(1000);
             PORTD = 0b01111111; //8
             Delay_ms(1000);
             PORTD = 0b01101111; //9
             Delay_ms(1000);
             PORTD = 0b01110111; //A
             Delay_ms(1000);
             PORTD = 0b01111100; //B
             Delay_ms(1000);
             PORTD = 0b00111001; //C
             Delay_ms(1000);
             PORTD = 0b01011110; //D
             Delay_ms(1000);
             PORTD = 0b01111001; //E
             Delay_ms(1000);
             PORTD = 0b01110001; //F
             Delay_ms(1000);
     }
}
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

char nome[] = "Aluno";
char ra[] = "123456";

//ENTRADAS
#define BT1 portb.rb3
#define BT2 portb.rb4

void main(){
     TRISB=0b00011000;
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);

     while(1)
     {
     if(!BT1)
             {
             Lcd_Cmd(_LCD_CLEAR);
             Lcd_Out(1,1,nome);
             }

     if(!BT2)
             {
             Lcd_Cmd(_LCD_CLEAR);
             Lcd_Out(1,1,ra);
             }
     }
}




