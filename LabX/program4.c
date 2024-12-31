#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	FILE *fp = fopen("output.txt", "w");
	if(fp == NULL){
		perror("Error opening file");
		return 1;
	}

	pid_t pid = fork();
	if(pid < 0){
		perror("Fork error");
		return 1;
	}
	if(pid == 0){ //Child
		fprintf(fp,"This is a message from the child. My pid is: %d\n", getpid());
	}
	if(pid > 0){ //Parent
		fprintf(fp,"This is a message from the parent. My pid is: %d\n", getpid());
	}

	if(fclose(fp) != 0){
		perror("Error closing file");
		return 1;
	}

	return 0;
}
