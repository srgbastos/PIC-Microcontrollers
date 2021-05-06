/*
Descrição: CCP1 em modo captura para verificar o tempo em NL1
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
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

char flag = 0x00; // flags
unsigned captura1, captura2; // Armazenar o tempo da captura
char texto[16]; // Para o display LCD

void interrupt(){
    if(CCP1IF_bit){ // Modo de captura do CCP1
       if(!flag.B0){ // Verifica Flag.B0
          captura1 = (CCPR1H << 8) + CCPR1L; // Armazena a Captura1
          flag.B0 = 1; // Seta Flag.B0 indicando fim da captura 1
       }
       else{
          captura2 = (CCPR1H << 8) + CCPR1L; // Armazena a Captura2
          flag.B0 = 0; // Limpa Flag.B0
          flag.B1 = 1; // Seta a Flag.B1 indicando fim da captura 1 e 2
       }
       CCP1IE_bit = 0; // Desabilita interrupção do CCP1
       CCP1CON.B0 = ~CCP1CON.B0; // Muda a detecção de borda de subida para descida
       CCP1IE_bit = 1; // Habilita interrupção do CCP1 novamente
       CCP1IF_bit = 0; // Limpa flag de CCP1
    }
}

void main(){
   ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
   TRISD = 0x00; // LCD
   TRISC = 0xFF;
   
   T1CON = 0b00000001; // Timer1 com prescale 1:1
   CCP1CON = 0b00000101; //Configura modo de captura em borda de subida
   CCP1IE_bit = 1; // Habilita interrupção do módulo CCP1
   IPEN_bit = 1; // Habilita níveis de prioridade nas interrupções
   CCP1IP_bit = 1; // CCP1 com priopridade alta

   GIE_bit = 1; // Global Interrupt Enable
   PEIE_bit = 1; // Interrupção de periféricos

   Lcd_Init();                                 //Inicializa o LCD
   Lcd_Cmd(_LCD_CURSOR_OFF);                   //Desliga o cursor
   Lcd_Cmd(_LCD_CLEAR);                        //Limpa o display
   Lcd_Out(1,1,"Tempo em NL1:");

   while(1){
      if(flag.B1){
      captura2 = captura2 - captura1; // Faz o cálculo do tempo em NL1
      IntToStr(captura2,texto); // Conversão para o display LCD
      Lcd_Out(2,1,texto); // Mostra no display LCD
      flag.B1 = 0; // Limpa flag.B1 para nova conversão
      }
   }
}