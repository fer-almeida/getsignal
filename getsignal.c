#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h> // Para as constantes de signal handler
#include <unistd.h>

#define MAJOR_VERSION	1
#define MINOR_VERSION	1

#define LOGERROR	1 //Exibe as informações de erro

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
	char* sigtable[31] = {
		"SIGHUP",
		"SIGINT",
		"SIGQUIT",
		"SIGILL",
		"SIGTRAP/SIGABRT",
		"SIGIOT",
		"SIGBUS",
		"SIGFPE",
		"SIGKILL",
		"SIGUSR1",
		"SIGEVG",
		"SIGUSR2",
		"SIGPIPE",
		"SIGALRM",
		"SIGTERM",
		"SIGKFLT/SIGCHLD",
		"SIGCLT",
		"SIGCONT",
		"SIGSTOP",
		"SIGTSTP",
		"SIGTTIN",
		"SIGTTOUT",
		"SIGURG",
		"SIGXCPU",
		"SIGXFSZ",
		"SIGVTALRM",
		"SIGPROF",
		"SIGWINCH/SIGIO",
		"SIGPOLL",
		"SIGPWR",
		"SIGSYS"
	};
	
	int i;
	
	if(LOGERROR) printf("Iniciando handlers:\n");
	
	for(i = 1; i <= 31; i++) {
		if(signal(i, sig_handler) == SIGERR) if(LOGERROR) printf("Erro ao iniciar handler %s\n", sigtable[i - 1]);
	}
	
	printf("Programa principal rodando...\n");
	
	while(1)  {
		sleep(1); // Outras funções do programa
	}
	
	return 0;
}
