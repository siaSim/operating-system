#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;

	for(int i=0;i<10;i++){ // 10개의 자식 좀비를 만들기 위해
		pid = fork(); // 자식 프로세스 생성
		if(pid < 0){ // fork 오류
			fprintf(stderr, "fork error");
			return 1;
		}
		else if(pid == 0) { //자식 프로세스
			exit(0); // 자식 프로세스는 생성되지 마자 종료
			// 부모가 자식의 종료를 기다리지 않기 때문에
			// 자식은 이때 좀비 프로세스가 됨
		}
		// 자식 생성 후 부모 프로세스는 자식의 종료를 기다리지 않고
		// 다음 자식 생성 
	}

	char c = getchar(); // 부모 프로세스를 종료시키지 않기 위해
}
