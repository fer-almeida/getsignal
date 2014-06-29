#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h> // Para as constantes de signal handler
#include <unistd.h>

#define MAJOR_VERSION	1
#DEFINE MINOR_VERSION 0

void sig_handler(int signo) {
	switch(signo) {
		case SIGINT :
			printf("SIGINT\nO usuario pressionou CTRL+C, entao sair!\n");
			exit(signo);
		case SIGSYS :
			printf("SIGSYS\nBad system call\n");
			break;
		case SIGHUP :
			printf("SIGHUP\nHangup (POSIX)\n");
			break;
		case SIGTERM :
			printf("SIGTERM\nTermination (ANSI)\nO usuario quer parar o processo. Mas nao vou parar!\n");
			break;
		case SIGUSR1 :
			printf("SIGUSR1\nUser-defined signal 1\n");
			break;
		case SIGUSR2 :
			printf("SIGUSR2\nUser-defined signal 2\n");
			break;
		default :
			printf("SIGNAL %d\n", signo);
		}
}

int main(void) {
	if(signal(SIGINT, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGINT\n");
	if(signal(SIGSYS, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGSYS\n");
	if(signal(SIGHUP, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGHUP\n");
	if(signal(SIGTERM, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGTERM\n");
	if(signal(SIGUSR1, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGUSR1\n");
	if(signal(SIGUSR2, sig_handler) == SIG_ERR) printf("\nImpossivel iniciar o handler SIGUSR2\n");
	
	printf("Programa principal rodando...\n");
	
	while(1)  {
		sleep(1); // Outras funções do programa
	}
	
	return 0;
}
