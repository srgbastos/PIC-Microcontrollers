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

const char character[] = {0,0,10,0,0,17,14,0};

void CustomChar(char pos_row, char pos_char) {
  char i;
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    Lcd_Chr(pos_row, pos_char, 0);
}

//void CustomChar() {
//  char i;
//  Lcd_Cmd(64);
//  for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
//  Lcd_Cmd(_LCD_RETURN_HOME);
//}

void main()  {
  Lcd_Init(); // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR); // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off

  //Send Custom Charactors to CGRAM
  CustomChar(1,6);

  //Display Custom Characters
  //Lcd_Chr(1,1,0);
  Delay_ms(1000);
}



/*
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

const char character0[] = {0,0,10,31,31,14,4,0};
const char character1[] = {14,27,17,17,17,17,31,0};
const char character2[] = {14,27,17,17,17,31,31,0};
const char character3[] = {14,27,17,17,31,31,31,0};
const char character4[] = {14,27,17,31,31,31,31,0};
const char character5[] = {14,31,31,31,31,31,31,0};
const char character6[] = {0,4,2,31,2,4,0,0};
const char character7[] = {0,0,14,17,17,10,27,0};

void CustomChar0() {
  char i;
  Lcd_Cmd(64);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character0[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar1() {
  char i;
  Lcd_Cmd(72);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character1[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar2() {
  char i;
  Lcd_Cmd(80);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character2[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar3() {
  char i;
  Lcd_Cmd(88);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character3[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar4() {
  char i;
  Lcd_Cmd(96);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character4[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar5() {
  char i;
  Lcd_Cmd(104);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character5[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar6() {
  char i;
  Lcd_Cmd(112);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character6[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void CustomChar7() {
  char i;
  Lcd_Cmd(120);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character7[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
}

void main()  {
  Lcd_Init(); // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR); // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off

  //Send Custom Charactors to CGRAM
  CustomChar0();
  CustomChar1();
  CustomChar2();
  CustomChar3();
  CustomChar4();
  CustomChar5();
  CustomChar6();
  CustomChar7();
  //End

  //Display Custom Characters
  Lcd_Chr(1,1,0);
  Delay_ms(1000);
  Lcd_Chr(1,2,1);
  Delay_ms(1000);
  Lcd_Chr(1,3,2);
  Delay_ms(1000);
  Lcd_Chr(1,4,3);
  Delay_ms(1000);
  Lcd_Chr(1,5,4);
  Delay_ms(1000);
  Lcd_Chr(1,6,5);
  Delay_ms(1000);
  Lcd_Chr(1,7,6);
  Delay_ms(1000);
  Lcd_Chr(1,8,7);
  Delay_ms(1000);
}
*/