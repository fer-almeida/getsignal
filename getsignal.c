#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // Para as constantes de signal handler
#include <unistd.h>

#define MAJOR_VERSION	1
#define MINOR_VERSION	1

#define LOGERROR	1 //Exibe as informações de erro

char* sigtable[31] = {
	"01 SIGHUP",
	"02 SIGINT",
	"03 SIGQUIT",
	"04 SIGILL",
	"05 SIGTRAP/SIGABRT",
	"06 SIGIOT",
	"07 SIGBUS",
	"08 SIGFPE",
	"09 SIGKILL",
	"10 SIGUSR1",
	"11 SIGEVG",
	"12 SIGUSR2",
	"13 SIGPIPE",
	"14 SIGALRM",
	"15 SIGTERM",
	"16 SIGKFLT/SIGCHLD",
	"17 SIGCLT",
	"18 SIGCONT",
	"19 SIGSTOP",
	"20 SIGTSTP",
	"21 SIGTTIN",
	"22 SIGTTOUT",
	"23 SIGURG",
	"24 SIGXCPU",
	"25 SIGXFSZ",
	"26 SIGVTALRM",
	"27 SIGPROF",
	"28 SIGWINCH/SIGIO",
	"29 SIGPOLL",
	"30 SIGPWR",
	"31 SIGSYS"
};

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
			printf("SIGNAL [%s]\n", sigtable[signo]);
		}
}

int main(void) {
	int i;
	
	if(LOGERROR) printf("\nErros ao iniciar Handlers:\n");
	
	for(i = 1; i <= 31; i++) {
		if(signal(i, sig_handler) == SIG_ERR) if(LOGERROR) printf("\t[%s]\n", sigtable[i - 1]);
	}
	
	printf("\nPrograma principal rodando...\n");
	
	while(1)  {
		sleep(1); // Outras funções do programa
	}
	
	return 0;
}
