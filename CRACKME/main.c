#include <stdio.h>
#include <stdlib.h>
#include <Debugapi.h>
#include <Windows.h>

//@Keowu(GITHUB)
//JOÃO FERREIRA APRENDIZADO
typedef unsigned long long ticks;

//LÊ O TEMPO EM MS QUE LEVAM ENTRE AS EXECUÇÕES DE UM PROGRAMA
static __inline__ ticks getticks(void)
{
     unsigned a, d;
     asm("cpuid");
     asm volatile("rdtsc" : "=a" (a), "=d" (d));

     return (((ticks)a) | (((ticks)d) << 32));
}


//VERIFICA SE TEM UM DEBBUG ANEXADO AO BINÁRIO DO SOFTWARE, SE TIVER ELE USA O SHELL E NAVEGA ATÉ UM MEME
void eDEBBUG(){
	if(IsDebuggerPresent() == 1){
		MessageBeep(10);
		MessageBoxA(NULL, "I GOT YOU", "I GOT", MB_OK);
		ShellExecute(NULL, "open", "https://youtu.be/-15VC4Yxzys", "", "", 1);
		exit(1);
	}else{
		return 0;
	}
}

//SIMPLES FUNÇÃO QUE FAZ A MESMA COISAS ACIMA, ABRE E .... '='
void iGotYou(){
	MessageBoxA(NULL, "I GOT YOU", "I GOT", MB_OK);
	ShellExecute(NULL, "open", "https://youtu.be/-15VC4Yxzys", "", "", 1);
	exit(1);
}

//CALCULA ALGO .... '='
int calcula(pass){
	int a = ((2000000 << 9) + 100); //CALCULO = MOVE 9 PARA ESQUERDA OS SIGNIFICATIVOS DE 2000000 E SOMA 100
	if (a == pass){
		printf("Ops, acertou, valor: %d \n", pass);
		return 0;
	}else{
		printf("Ops, errou, valor: %d \n", pass);
		return 1;	
	}
}

//MAIN .... '='
int main(int argc, char *argv[]) {
	int r = 0;
    ticks tick,tick1,tickh;
    unsigned time =0;
    tick = getticks();
    //sleep(1);
    tick1 = getticks();
    time = (unsigned)((tick1-tick)/1662543);
    
    if(time != 0){
    	printf("\nTentando usar um debbuger ein ??%u\n ",time);
    	iGotYou();
	}
	
	eDEBBUG();
	printf("------------------------------> %x", calcula(1024000100));
	return 0;
}
