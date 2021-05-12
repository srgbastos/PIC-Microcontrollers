void main() {
   ADCON1 = 0x0F; // Pinos de IO como digitais
   TRISA = 0xCF;
   CMCON=0x02;             // 'Two Common Reference Comparators with Outputs' Mode
   TRISD=0x00;
   
   while(1)
   {
   PORTD.RD0=1;
   delay_ms(500);
   PORTD.RD0=0;
   delay_ms(500);
   
    PORTD.F2 = CMCON.C2OUT; // Assigning output of comparator 2 to Rd2
    PORTD.F1 = CMCON.C1OUT; // Assigning output of comparator 2 to RD1
    Delay_ms(100);
   
   
   
   }
}