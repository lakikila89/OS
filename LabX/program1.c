#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	pid_t  parent_pid = getpid();
	printf("This is the parent with process id: %d\n", parent_pid);
	fork();
	if(getpid() == parent_pid){ //Ώστε να κάνει fork() μόνο ο parent και να έχω 4 processes και όχι 8.(Αυτό κατάλαβα από την εκφώνηση)
		fork();
	}
	if(getpid() == parent_pid){
		fork();
	}
	if(getpid() != parent_pid){
		printf("This is a child with process id is: %d\n", getpid());
	}
}
