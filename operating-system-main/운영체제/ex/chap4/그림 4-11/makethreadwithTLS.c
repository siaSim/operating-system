#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void printsum(); // 모든 스레드에 의해 호출되는 함수 
void* calcThread(void *param); // 스레드 코드로 사용되는 함수 

static __thread int tsum = 5; // 스레드 로컬 스토리지(TLS) tsum 변수 선언 
			      // 스레드가 생길 때마다 스레드 로컬 스토리지에 tsum 변수 생성
int total = 0; // 프로세스의 전역 변수, 모든 스레드에 의해 공유  

int main() {
	char *p[2] = {"100", "200"};
	int i;
	pthread_t tid[2]; // 스레드의 id를 저장할 정수 배열 
	pthread_attr_t attr[2]; // 스레드 정보를 담을 구조체 

	// 2개의 스레드 생성 
	for(i=0; i<2; i++) {
		pthread_attr_init(&attr[i]);  // 구조체 초기화 
		pthread_create(&tid[i], &attr[i], calcThread, p[i]); // 스레드 생성 
		printf("calcThread 스레드가 생성되었습니다.\n");
	}

	// 2개 스레드의 종료를 기다린 후에 total 값 출력 
	for(i=0; i<2; i++) {
		pthread_join(tid[i], NULL); // 스레드 tid[i]의 종료대기 
		printf("calcThread 스레드가 종료하였습니다.\n");
	}
	printf("total = %d\n", total); // 2개 스레드의 합이 누적된 total 출력 
	return 0;
}

void* calcThread(void *param) { // 스레드 코드
	printf("스레드 생성 초기 tsum = %d\n", tsum); // TLS 변수 tsum의 초기값 출력 

	int i, sum = 0; // 지역 변수 
	for(i=1; i<= atoi(param); i++) sum += i; // 1~param까지 더하기  

	tsum = sum; // TLS 변수tsum에 합 저장 
	printsum();
	total+=sum; // 전역 변수 total에 합 누적 
}

void printsum() { // 모든 스레드가 호출할 수 있는 공유 함수
	printf("계산 후 tsum = %d\n", tsum);
}
