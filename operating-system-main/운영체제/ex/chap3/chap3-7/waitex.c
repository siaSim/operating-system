﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int status;

	pid = fork(); // 자식 프로세스 생성  

	if (pid > 0) { // 부모 프로세스 코드  
		printf("부모프로세스: 자식의 종료를 기다림\n");
		wait(&status); // 자식프로세스 종료 대기. status에 종료 코드 받음
                printf("부모프로세스: child의 종료 코드=%d\n", WEXITSTATUS(status));
		return 0;
	}
	else if (pid == 0) { // 자식 프로세스 코드  
		execlp("./child", "child", NULL); // child를 자식 프로세스로 실행 
	}
	else { // fork() 오류 
		printf("fork 오류");
		return 0;
	}
}
