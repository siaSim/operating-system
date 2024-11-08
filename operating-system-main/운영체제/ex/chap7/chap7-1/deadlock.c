#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int x = 0; // 공유 변수
int y = 0; // 공유 변수
pthread_mutex_t lock1;	// 뮤텍스 락 변수
pthread_mutex_t lock2;	// 뮤텍스 락 변수

void* worker1(void* arg) { // 스레드 코드
	pthread_mutex_lock(&lock1); // x를 독점 사용하기 위해 lock1 잠그기 
	printf("%s lock1 잠금\n", (char*)arg);
	x++;
	sleep(2); // 2초 잠자기

	pthread_mutex_lock(&lock2); // y를 독점 사용하기 위해 lock2 잠그기 
	printf("%s lock2 잠금\n", (char*)arg);
	y++;
	pthread_mutex_unlock(&lock2); // lock2 풀기 
	printf("%s lock2 해제\n", (char*)arg);

	pthread_mutex_unlock(&lock1); // lock1 풀기 
	printf("%s lock1 해제\n", (char*)arg);
}

void* worker2(void* arg) { // 스레드 코드
	pthread_mutex_lock(&lock2); // y를 독점 사용하기 위해 lock2 잠그기 
	printf("%s lock2 잠금\n", (char*)arg);
	y++;
	sleep(2); // 2초 잠자기

	pthread_mutex_lock(&lock1); // x를 독점 사용하기 위해 lock1 잠그기 
	printf("%s lock1 잠금\n", (char*)arg);
	x++;
	pthread_mutex_unlock(&lock1); // lock1 풀기 
	printf("%s lock1 해제\n", (char*)arg);

	pthread_mutex_unlock(&lock2); // lock2 풀기 
	printf("%s lock2 해제\n", (char*)arg);
}

int main() {
	char *name[] = {"황기태", "이찬수"};
	pthread_t tid[2];

	pthread_mutex_init(&lock1, NULL); // 뮤텍스 락 변수 lock1 초기화
	pthread_mutex_init(&lock2, NULL); // 뮤텍스 락 변수 lock2 초기화

	pthread_create(&tid[0], NULL, worker1, name[0]);  // worker1 스레드 생성
	pthread_create(&tid[1], NULL, worker2, name[1]); // worker2 스레드 생성

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_mutex_destroy(&lock2);
	pthread_mutex_destroy(&lock1);

	printf("x = %d, y = %d\n", x, y);

	return 0;
}
