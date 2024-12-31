#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pid_t pid;

	if(pipe(fd) == -1){
		perror("pipe error");
		return 1;
	}

	pid = fork();
	if(pid < 0){
		perror("fork error");
		return 1;
	}

	if(pid == 0){ //Child
		char buffer[100];
		close(fd[1]);
		read(fd[0],buffer,sizeof(buffer));
		printf("Child received this message: %s\n", buffer);
		close(fd[0]);
	}

	if(pid > 0){ //Paren
		char msg[] = "This is a test message for the child.";
		close(fd[0]);
		write(fd[1],msg,strlen(msg));
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}
