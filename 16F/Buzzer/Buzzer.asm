
_main:

;Buzzer.c,16 :: 		void main()
;Buzzer.c,18 :: 		TRISB=0b00000001; // Bits 7...1 como saida e Bit 0 como entrada (PORTB)
	MOVLW      1
	MOVWF      TRISB+0
;Buzzer.c,19 :: 		TRISC=0; // Todos os pinos configurados como saída do PORTC
	CLRF       TRISC+0
;Buzzer.c,20 :: 		PORTC=0X00; // inicialização do PORTC
	CLRF       PORTC+0
;Buzzer.c,22 :: 		while(1) // Loop infinito
L_main0:
;Buzzer.c,24 :: 		if(!BOTAO) BUZZER = 0; //Ao pressionar o botão, o buzzer aciona
	BTFSC      PORTB+0, 0
	GOTO       L_main2
	BCF        PORTC+0, 1
	GOTO       L_main3
L_main2:
;Buzzer.c,25 :: 		else BUZZER = 1;
	BSF        PORTC+0, 1
L_main3:
;Buzzer.c,26 :: 		}
	GOTO       L_main0
;Buzzer.c,27 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
