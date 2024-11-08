/******************************************************
 소스 프로그램 prac3_6.c
 컴파일 및 실행 방법
 $ gcc -o prac3_6 prac3_6.c
 $ ./prac3_6
*******************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(void) {
	pid_t pid;
	int status, i;

	pid = fork();
	if (pid > 0) { 
		sleep(1);
		return 0;
	}
	else if (pid == 0) { 
		sleep(2);
		printf("부모프로세스의 pid = %d", getppid());
		return -1;
 	}
}
