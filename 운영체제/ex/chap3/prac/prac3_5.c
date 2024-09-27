/******************************************************
 소스 프로그램 prac3_5.c
 컴파일 및 실행 방법
 $ gcc -o prac3_5 prac3_5.c
 $ ./prac3-5
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
	if (pid > 0) { // (a) 부모/자식/오류처리
		sleep(2);
		wait(&status);
		printf("%d\n", WEXITSTATUS(status));
		return 0;
	}
	else if (pid == 0) { // (b) 부모/자식/오류처리
		sleep(1);
		return -1;
 	}
	else { // (c) 부모/자식/오류처리
		sleep(3);
		return 1;
	}
}
