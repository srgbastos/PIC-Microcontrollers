//http://apostilas.tecnologia.ws/2016/09/22/pratica-7-rttl-player-com-pic/
int pausa = 1;
char  timer0freq;
int loop;
int music_end = 0;

//TEST
//const int oitava_padrao = 4;
//const int tempo_padrao = 1;
//const char musica[] = "a,a,a,a,a,a,a,a,a,a";

//Mozart
//const int oitava_padrao = 5;
//const int tempo_padrao = 16;
//const beatsperminute = 125;
//const char musica[] = "16d#,c#,c,c#,8e,8p,f#,e,d#,e,8g#,8p,a,g#,g,g#,d#6,c#6,c6,c#6,d#6,c#6,c6,c#6,4e6,8c#6,8e6,32b,32c#6,d#6,8c#6,8b,8c#6,32b,32c#6,d#6,8c#6,8b,8c#6,32b,32c#6,d#6,8c#6,8b,8a#,4g#,d#,32c#,c,c#,8e,8p,f#,e,d#,e,8g#,8p,a,g#,g,g#,d#6,c#6,c6,c#6,d#6,c#6,c6,c#6,4e6,8c#6,8e6,32b,32c#6,d#6,8c#6,8b,8c#6,32b,32c#6,d#6,8c#6,8b,8c#6,32b,32c#6,d#6,8c#6,8b,8a#,4g#";

//Beethoven
//const int oitava_padrao = 5;
//const int tempo_padrao = 8;
//const beatsperminute = 125;
//const char musica[] = "32p,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,e,g#,b,4c.6,32p,e,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,d,c6,b,2a";

//Beethoven2
//const int oitava_padrao = 5;
//const int tempo_padrao = 8;
//const beatsperminute = 125;
//const char musica[] = "8f,8f,8f,1c#,8p,8d#,8d#,8d#,1c,8p,8f,8f,8f,8c#,8f#,8f#,8f#,8f,8c#6,8c#6,8c#6,2a#,8p,8f,8f,8f,8c,8f#,8f#,8f#,8f,8d#6,8d#6,8d#6,1c6,8f6,8f6,8d#6,8c#6,8c#,8c#,8d#,8f,8f6,8f6,8d#6,8c#6,8c#,8c#,8d#,8f,8f6,8f6,8d#6,c#6,p,a#,p,2f6";

//BACH
//const int oitava_padrao = 6;
//const int tempo_padrao = 32;
//const beatsperminute = 90;
//const char musica[] = "16d,d#.,f.,d.,d#.,f.,d.,d#.,f.,d.,16d#,16f,f#.,g#.,f.,f#.,g#.,f.,f#.,g#.,f.,16f#,16g#,a#.,b.,g#.,a#.,b.,g#.,a#.,b.,16g#,2a#,16a#,g#.,b.,f.,g#.,b.,f.,f#.,a#.,d#.,f#.,a#.,d#.,f.,g#.,d.,f.,g#.,d.,d#.,f#.,c.,d#.,16f#,16c,16c#,16f,16a#5,16c#,16f,16a#5,16c,16d#,16g#5,16c,16d#,16g#5,16a#5,16c#,16f#5,16a#5,16c#,16f#5,16g#5,16b5,16f5,16g#5,16b5,16f5,16f#5,16a#5,16d#5,16f#5,16a#5,16d#5,16f5,16g#5,16d5,16f5,16g#5,16d.5,4d#.5";

//BACH2
//const int oitava_padrao = 5;
//const int tempo_padrao = 8;
//const beatsperminute = 128;
//const char musica[] = "4d6,g,a,b,c6,4d6,4g,4g,4e6,c6,d6,e6,f6,4g6,4g,4g,4c6,d6,c6,b,a,4b,c6,b,a,g,4f#,g,a,b,g,4b,4a";

//We wish you a merry christmas
//const int oitava_padrao = 5;
//const int tempo_padrao = 4;
//const beatsperminute = 200;
//const char musica[] = "d,g,8g,8a,8g,8f#,e,e,e,a,8a,8b,8a,8g,f#,d,d,b,8b,8c6,8b,8a,g,e,d,e,a,f#,2g,d,g,8g,8a,8g,8f#,e,e,e,a,8a,8b,8a,8g,f#,d,d,b,8b,8c6,8b,8a,g,e,d,e,a,f#,1g,d,g,g,g,2f#,f#,g,f#,e,2d,a,b,8a,8a,8g,8g,d6,d,d,e,a,f#,2g";

// Pink Panther
//const int oitava_padrao = 5;
//const int tempo_padrao = 4;
//const beatsperminute = 125;
//const char musica[] = "8d#,8e,2p,8f#,8g,2p,8d#,8e,16p,8f#,8g,16p,8c6,8b,16p,8d#,8e,16p,8b,2a#,2p,16a,16g,16e,16d,2e";

// Barbie Girl
//const int oitava_padrao = 5;
//const int tempo_padrao = 4;
//const beatsperminute = 125;
//const char musica[] = "8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f#";

// Take on me
//const int oitava_padrao = 4;
//const int tempo_padrao = 4;
//const beatsperminute = 160;
//const char musica[] = "8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";

// Mario
//const int oitava_padrao = 5;
//const int tempo_padrao = 4;
//const beatsperminute = 60;
//const char musica[] = "a,8f.,16c,16d,16f,16p,f,16d,16c,16p,16f,16p,16f,16p,8c6,8a.,g,16c,a,8f.,16c,16d,16f,16p,f,16d,16c,16p,16f,16p,16a#,16a,16g,2f,16p,8a.,8f.,8c,8a.,f,16g#,16f,16c,16p,8g#.,2g,8a.,8f.,8c,8a.,f,16g#,16f,8c,2c6";

//Simpsons
//const int oitava_padrao = 5;
//const int tempo_padrao = 4;
//const beatsperminute = 180;
//const char musica[] = "c.6,4e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";

//Star Wars
const int oitava_padrao = 6;
const int tempo_padrao = 8;
const beatsperminute = 180;
const char musica[] = "f5,f5,f5,2a#5.,2f.,d#,d,c,2a#.,4f.,d#,d,c,2a#.,4f.,d#,d,d#,2c,4p,f5,f5,f5,2a#5.,2f.,d#,d,c,2a#.,4f.,d#,d,c,2a#.,4f.,d#,d,d#,2c";

int posicao_musica = 0;
char codigo_nota[5] = "";

char nota = 'A';
int tempo_nota = tempo_padrao;
int sustenido_nota = 0;
int oitava_nota = oitava_padrao;

void interrupt()  {
  if (pausa == 0) {
    //porta.f0 = ~porta.f0;
    portc.f1 = ~portc.f1;
  } else portc.f1 = 0;

  TMR0 = timer0freq;
  INTCON.T0IF = 0;         // clear the flag
}

void decode_codigo_nota() {
     int pos = 0;

     tempo_nota = 0;
     sustenido_nota = 0;
     oitava_nota = oitava_padrao;

     //Pegar a duracao (tempo) da nota
     for (loop=0;loop<5;loop++) {
       if (isdigit(codigo_nota[loop])) {
          tempo_nota = tempo_nota*10 + (codigo_nota[loop] - 48);
       } else break;
     }

     if (tempo_nota == 0) tempo_nota = tempo_padrao;
     tempo_nota = (60000/(beatsperminute*tempo_nota))*2;

     pos = loop;

     nota = codigo_nota[pos];

     for (loop=pos+1;loop<5;loop++) {
       if (isdigit(codigo_nota[loop])) {
          oitava_nota = codigo_nota[loop] - 48;
       }
       if (codigo_nota[loop] == '.') tempo_nota = tempo_nota + tempo_nota*(1/2);
       if (codigo_nota[loop] == '#') sustenido_nota = 1;
     }
}

int get_frequency(char nota) {
    nota = toupper(nota);

    // Notas                                        A                B                C                D                E         F             G
    // frequencia das notas (Hz)                440                  494                262            294              330       349           392
    // 1/2 periodo          (Hz)                880                  988                524            588              660       698           784

    // Notas                                        A#                B#                C#             D#               E#         F#           G#
    // frequencia das notas (Hz)                466                  494                277            311              330        370          415
    // 1/2 periodo               (Hz)           932                  988                554            622              660        740          830

    //if (oitava_nota == 4) OPTION_REG=0b00000010;  //Pre-scaler = x8;
    //if (oitava_nota == 5) OPTION_REG=0b00000001;  //Pre-scaler = x4;
    //if (oitava_nota == 6) OPTION_REG=0b00000000;  //Pre-scaler = x2;
    //if (oitava_nota == 7) OPTION_REG=0b00001000;  //Pre-scaler = x1;

    if (oitava_nota == 4) OPTION_REG=0b00000011;  //Pre-scaler = x16;
    if (oitava_nota == 5) OPTION_REG=0b00000010;  //Pre-scaler = x8;
    if (oitava_nota == 6) OPTION_REG=0b00000001;  //Pre-scaler = x4;
    if (oitava_nota == 7) OPTION_REG=0b00000000;  //Pre-scaler = x2;


    if (nota == 'P') {
       pausa = 1;
    } else pausa = 0;

    if (nota == 'A') { if (sustenido_nota == 0) return 116; else return  124; };
    if (nota == 'B') return 131;
    if (nota == 'C') { if (sustenido_nota == 0) return  20; else return  32; };
    if (nota == 'D') { if (sustenido_nota == 0) return  46; else return  58; };
    if (nota == 'E') return  70;
    if (nota == 'F') { if (sustenido_nota == 0) return  78; else return 89; };
    if (nota == 'G') { if (sustenido_nota == 0) return 98; else return 107; };

    return 0;
}

void timer_set() {
     //TIMER0
     INTCON = 0;           // clear the interrpt control register
     INTCON.T0IE = 1;        // bit5 TMR0 Overflow Interrupt Enable bit...1 = Enables the TMR0 interrupt
     INTCON.T0IF = 0;        // bit2 clear timer 0 interrupt flag
     INTCON.GIE = 1;           // bit7 global interrupt enable
     TMR0=timer0freq;
}

void carrega_proxima_nota(int pos) {
    int pos_ret = 0;

    if (music_end == 1) {
      codigo_nota[0] = 'p';
      codigo_nota[1] = '.';
      codigo_nota[2] = '.';
      codigo_nota[3] = '.';
      codigo_nota[4] = '.';
      music_end = 0;
      return;
    }

    codigo_nota[0] = ' ';
    codigo_nota[1] = ' ';
    codigo_nota[2] = ' ';
    codigo_nota[3] = ' ';
    codigo_nota[4] = ' ';

    for (loop=pos;loop<sizeof(musica)-1;loop++) {
        if (musica[loop] == ',') {
            break;
        }
        codigo_nota[pos_ret] = musica[loop];
        pos_ret++;
    }

    posicao_musica = loop+1;

    //FIM DA MUSICA!
    if (posicao_musica >= sizeof(musica)) {
       posicao_musica = 0;
       music_end = 1;
    }
}

void main() {
     //CONFIGURAÇÃO DOS REGISTROS
     CMCON = 0x07;
     TRISB=0x00;
     TRISA=0x00;

     TRISC=0x00;

     posicao_musica = 0;

     timer0freq = get_frequency(nota);

     timer_set();

     while(1) {
        carrega_proxima_nota(posicao_musica);
        decode_codigo_nota();
        timer0freq = get_frequency(nota);
        Vdelay_ms(tempo_nota);
        pausa = 1;
        Vdelay_ms(tempo_nota/10);
     }
}