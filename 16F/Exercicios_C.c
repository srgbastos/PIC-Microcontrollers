int varA = 5, varB = 10, varC = 12;
int i;

int xpto(int a);

void main( ){
while(1){
    do{
        varA = 3*varB + varC;
        varB = xpto(varA) + 20;
    }while(varB <= 205);

   if(varA < 440){
        for(i=0; i<4; i++){
            varC = varB + varC;
            varB++;
        }
    }
    else{
        for(i=0; i<4; i++){
            varC = varA + varC;
            varB--;
        }
    }
    while(1){ } // Fim do programa
  }
}

int xpto(int a){
   int x;
   x = 4*a - 10;
   return x;}
