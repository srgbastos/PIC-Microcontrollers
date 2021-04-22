/*
Descrição: Faz o controle de velocidade PWM da ventoinha por meio do
 potenciômetro no canal AN0 do microcontrolador.
Library Manager: Selecionar as bibliotecas ADC e PWM.
Datasheet indica que CCP1 está no pino RC2.
A ventoinha do simulador está no pino RC2.
Dispositivo: PIC16F877A, cristal 4 MHz
Compilador: mikroC
Simulador: PICSimLab
*/

void main () {
int p;
TRISA.RA0 = 1; // programa pino RA0 como entrada - AN0
PWM1_Init(2000) ; // inicializa PWM, canal CCP1, com 2kHz
PWM1_Set_Duty(0); // inicializa duty - cicle com 0
PWM1_start(); // inicializa PWM

   while(1){
      p = ADC_Read(0); // le o canal AN0 e salva em P
      p = p>>2; // converte o valor do AN0 em byte
      PWM1_Set_Duty(p); // atribui o valor de p ao dutycicle do PWM
      Delay_ms(100) ; // aguarda delay de 100 ms
   }

PWM1_Stop();
}