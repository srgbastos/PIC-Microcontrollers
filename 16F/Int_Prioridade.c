/*
Descrição: Mostra valores de Timer0 e Timer1 no LCD
Timer0 incrementa a cada 2s (TMR0=217d e contagem = 200d)
Timer1 incrementa a cada 0,5s (TMR1=3036d, TMR1H=0Bh e TMR1L=DCh)
Interrupção externa zera tudo
Dispositivo: PIC16F877A
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

// declaração de variáveis
char texto_TMR0[16], texto_TMR1[16];
unsigned int var_TMR0 = 0;
unsigned int var_TMR1 = 0;
unsigned int contagem = 0; // contador para o Timer0

void interrupt(void){
  if(INTCON.INTF){ // verifica interrupção externa
    TMR0 = 217; // recarrega TMR0
    contagem = 0;
    var_TMR0 = 0;
    TMR1H = 0x0B; // recarrega TMR1
    TMR1L = 0XDC;
    var_TMR1 = 0;
    INTCON.INTF = 0; // limpa flag de interrupção externa
  }
  else if(INTCON.TMR0IF){ // verifica interrupção do Timer0
    contagem++; // incrementa variável de contagem
    TMR0 = 217; // recarrega TMR0
    if(contagem == 200){
      var_TMR0 = var_TMR0++;
      contagem = 0; // reinicia contagem
    }
    INTCON.TMR0IF = 0; // limpa flag de interrupção do Timer0
  }
  else if(PIR1.TMR1IF){ // verifica interrupção do Timer1
     TMR1H = 0x0B; // recarrega TMR1
     TMR1L = 0XDC;
     var_TMR1 = var_TMR1++;
     PIR1.TMR1IF = 0; // limpa flag de interrupção do Timer1
  }
}

void main(){
  TRISD = 0; // configura PORTD como saída (LCD)
  TRISE = 0; // configura PORTE como saída (LCD)
  TRISB.RB0 = 1; // pino RB0 como entrada para a interrupção externa

  Lcd_Init(); // Inicializa o Display
  delay_ms(100) ;
  Lcd_Cmd(_LCD_CLEAR);
  delay_ms(100) ;
  Lcd_Cmd(_LCD_CURSOR_OFF);
  delay_ms(100) ;
  Lcd_Out(1,1,"Timer0: ");
  delay_ms(100) ;
  Lcd_Out(2,1,"Timer1: ");
  delay_ms(100) ;

  // Configurações da Interrupção Externa
  OPTION_REG.INTEDG = 0; // Interrupt Edge Select bit (falling edge)
  INTCON.INTE = 1; // RB0/INT External Interrupt Enable bit

  // Configurações do Timer0
  OPTION_REG.T0CS = 0; // TMR0 Clock Source Select (Internal Clock)
  OPTION_REG.PSA = 0; // Prescaler Assignment bit
  OPTION_REG.PS2 = 1; // Prescaler Rate Select bits (1:256)
  OPTION_REG.PS1 = 1;
  OPTION_REG.PS0 = 1;
  INTCON.TMR0IE = 1; // TMR0 Overflow Interrupt Enable bit
  TMR0 = 217; // Inicia TMR0

  // Configurações do Timer1
  PIE1.TMR1IE = 1; // TMR1 Overflow Interrupt Enable bit
  T1CON.T1CKPS1 = 1; // Timer1 Input Clock Prescale Select bits (1:8)
  T1CON.T1CKPS0 = 1; // Timer1 Input Clock Prescale Select bits (1:8)
  T1CON.T1OSCEN = 1; // Timer1 Oscillator Enable Control bit
  T1CON.TMR1CS = 0; // Timer1 Clock Source Select bit (Internal Clock)
  T1CON.TMR1ON = 1; // Timer1 On bit
  TMR1H = 0x0B; // inicia TMR1
  TMR1L = 0xDC;

  // Habilita todas as interrupções
  INTCON.PEIE = 1; // Peripheral Interrupt Enable bit
  INTCON.GIE = 1; // Global Interrupt Enable bit

  while(1){
    WordToStr(var_TMR0, texto_TMR0); // converte para string
    Lcd_Out(1,8,texto_TMR0); // escreve variável texto e faz ajuste de posição
    WordToStr(var_TMR1, texto_TMR1); // converte para string
    Lcd_Out(2,8,texto_TMR1); // escreve variável texto e faz ajuste de posição
  }
}
