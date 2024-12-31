#include <stdio.h>
#include <stdlib.h>

int add(int *x, int *y, int *z){
	return *x + *y + *z;
}

int main(){
	int x,y,z;
	char buffer[100]; //buffer to handle invalid input from scanf
	printf("Type the 1st integer:");
	while(scanf("%d", &x) != 1){
		printf("Please type a valid integer:");
		scanf("%s", buffer); //if the user types a non numerical string i store it in the buffer so that it doesn't remain in the stdin buffer and cause problems.
	}
	printf("Type the 2nd integer:");
        while(scanf("%d", &y) != 1){
                printf("Please type a valid integer:");
		scanf("%s", buffer);
        }
	printf("Type the 3rd integer:");
        while(scanf("%d", &z) != 1){
                printf("Please type a valid integer:");
		scanf("%s", buffer);
        }
	printf("The sum of the integers is: %d+%d+%d = %d\n", x,y,z,add(&x,&y,&z));
	return 0;
}
