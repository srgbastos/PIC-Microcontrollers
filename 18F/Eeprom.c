/*
Descrição: Exemplo de uso da EEPROM interna. Ler pag. 294 do manual MikroC.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC - Biblioteca Eeprom
Simulador: SimulIDE
*/

char ii;
void main(){
   ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
   TRISB = 0;
   TRISD = 0;
   PORTB = 0;
   PORTD = 0;

   for(ii = 0; ii < 32; ii++) // Fill data buffer
      EEPROM_Write(0x80+ii, ii); // Write data to address 0x80+ii

   EEPROM_Write(0x02, 0x3A); // Write some data at address 2
   Delay_ms(1000); // Blink PORTB and PORTD
   PORTB = 0xFF; // to indicate reading start
   PORTD = 0xFF;
   Delay_ms(1000);
   PORTB = 0x00;
   PORTD = 0x00;
   Delay_ms(1000);
   
   PORTB = EEPROM_Read(0x02); // Read data from address 2 and display it on PORTB
   Delay_ms(1000);
   for(ii = 0; ii < 32; ii++) { // Read 32 bytes block from address 0x80
      PORTD = EEPROM_Read(0x80+ii); // and display data on PORTD
      delay_ms(500);
   }

   while(1){}
}

