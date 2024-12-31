#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	pid_t pid;
	pid = fork();

	if( pid < 0){
		perror("fork error");
		return 1;
	}

	if(pid == 0){ //Child
		printf("Child process with id: %d waiting for signal...\n", getpid());
		pause();
	}

	if(pid > 0){ //Parent
		sleep(1);
		printf("Sending interupt signal to child with id: %d\n", pid);
		sleep(2);
		if(kill(pid, SIGINT) == -1){
			perror("kill error");
			return 1;
		}
		wait(NULL);
	}
	return 0;
}
