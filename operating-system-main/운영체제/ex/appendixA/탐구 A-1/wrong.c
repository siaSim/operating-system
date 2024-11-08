#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(void) {
	pid_t pid;
	int i, sum, n;

	sum = 0; // 자식 프로세스가 합한 결과를 저장할  변수
	n=10; // 자식 프로세스에게 전달할 값

	pid = fork(); // 자식 프로세스 생성 
	if (pid > 0) { // 부모 프로세스 코드 
		wait(NULL); // 자식이 종료할 때까지  대기

		// 자식 프로세스가 계산한 sum 값 출력
		printf("부모 프로세스: sum = %d\n", sum);
	}
	else if (pid == 0) { //  자식 프로세스 코드
		for (i=1; i<=n; i++) // 1에서 n(10)까지 더하기
			sum += i;
		printf("자식 프로세스: sum = %d\n", sum);
	}
	else // fork() 오류 
		return 1; 
}

