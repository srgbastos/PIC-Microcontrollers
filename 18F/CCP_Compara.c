/*
Descrição: Modo compara, initialize CCP2 pin low, set output
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

// pinagem do LCD
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

void Lcd_Hex(char lin, char col, char hex); // Função para mostrar no LCD valores em Hexa

void main() {
     TRISD = 0; // configura PORTD como saída
     TRISE = 0; // configura PORTE como saída
     TRISC = 0x01; // configura PORTC.RC0 como entrada (Encoder)
     PORTC.RC2 = 1; // liga a ventoinha

     Lcd_Init(); // Inicializa o Display
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1,1,"TMR1H: ");
     Lcd_Out(2,1,"TMR1L: ");

     T1CON = 0b00000011; // TIMER1 ligado, prescaler 1:1, clock externo
     TMR1H = 0x00; // carrega valor de contagem inicial do TIMER1
     TMR1L = 0x00;

     CCP2CON = 0b00001000; // Compare mode, initialize CCP2 pin low, set output
     CCPR2H = 0x01; // Valor de comparação
     CCPR2L = 0x2F;

     PWM1_Init(2000) ; // inicializa PWM, canal CCP1, com 2kHz
     PWM1_Set_Duty(55); // inicializa duty cycle
     PWM1_start(); // inicializa PWM

     while(1){
        if(CCP2IF_bit){ // Verifica se CCPR2 = TMR1
           CCP2IF_bit = 0; // Zera a flag de CCP2
           TMR1ON_bit = 0; // Desliga o Timer1
        }
        Lcd_Hex(1,7,TMR1H); // Mostra valor em hexa no LCD
        Lcd_Hex(2,7,TMR1L); // Mostra valor em hexa no LCD
        
     }
}

// Função para mostrar um valor em Hexa no LCD
void Lcd_Hex(char lin, char col, char hex){
   unsigned char temp_L; // armazena os 4 bits menos significativos
   unsigned char temp_H; // armazena os 4 bits mais significativos
 
   temp_H = hex & 0xF0; // calcula os 4 bits mais significativos
   temp_H = temp_H >> 4;
   if(temp_H > 9) temp_H += 0x37; // Converte número para ASCII
   else temp_H += 0x30; // Converte número para ASCII

   temp_L = hex & 0x0F; // calcula os 4 bits menos significativos
   if(temp_L >9) temp_L += 0x37;
   else temp_L += 0x30;
 
   Lcd_Chr(lin, col, temp_H); // evia ao LCD
   Lcd_Chr_Cp(temp_L);
}