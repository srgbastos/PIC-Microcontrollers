/*
Descrição: Modo compara, evento especial
f=1,25Hz -> T=0,8s -> 0,4s em NL1 e 0,4s em NL0
T_match = CCPR1x(4/F_cristal)xPrescaler
0,4 = CCPR1 x 1us x 8 -> CCPR1 = 50000d = C350h
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main()
{
     T1CON = 0b00110001; // Prescale 1:8, TMR1 Enable
     TMR1H = 0x00; // Inicia TMR1 em zero
     TMR1L = 0x00;
     CCP1CON = 0b00001011; // Compare mode, trigger special event
     CCPR1H = 0xC3; // Valor de comparação
     CCPR1L = 0x50;
     TRISD = 0x00; // PORTD output

     while(1){
        if(CCP1IF_bit){ // Verifica se CCPR1 = TMR1
           CCP1IF_bit = 0; // Zera a flag de CCP1
           RD0_bit = ~RD0_bit; // Inverte led em RD0
        }
     }
}
