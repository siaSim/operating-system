#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>

void child_wait(int sig) {
	int statloc;
	pid_t pid = wait(&statloc); // 자식의 종료 코드 읽기
	printf("자식의 종료 코드는 %d\n", WEXITSTATUS(statloc));
}

int main() {
	signal(SIGCHLD, child_wait); // 신호 SIGCHLD 신호 핸들러 등록
	switch(fork()) { // 자식 프로세스 생성
		case -1:
			printf("fork() 오류\n");
			return -1;
		case 0: // 자식 프로세스 코드
			printf("자식 프로세스 실행... 그리고 종료\n");
			exit(20); // 자식 프로세스 종료. 종료 코드는 20
		default: // 부모 프로세스 코드
			pause(); // 아무 신호나 수신할 때까지 대기
			printf("부모 프로세스 종료\n");
			return 0;
	}
}
