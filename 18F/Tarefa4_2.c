// TAREFA2

/*
Descrição: Exemplo de uso da EEPROM interna. Ler pag. 294 do manual MikroC.
Dispositivo: PIC18F4550, 4MHz
Compilador: mikroC - Biblioteca Eeprom
Simulador: SimulIDE
*/

void main(){
   ADCON1 = 0x0F; // Configura todos os pinos como I/O digital
   TRISB = 255;
   TRISD = 0;
   PORTD = 0;

   while(1){
      EEPROM_Write(0x1FF, PORTB);
      delay_ms(100);
      PORTD = EEPROM_Read(0x02);
      delay_ms(100);
   }
}

