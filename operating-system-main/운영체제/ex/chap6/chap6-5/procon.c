// #define _GNU_SOURCE
// #include <stdio.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>
// #include <stdlib.h>

// #define N_COUNTER 4 // 공유 버퍼의 크기. 정수 4개 저장
// #define MILLI 1000

// void mywrite(int n);
// int myread();

// pthread_mutex_t critical_section; // 뮤텍스
// sem_t semWrite, semRead;          // POSIX 세마포
// int queue[N_COUNTER];             // 4개의 정수를 저장하는 공유 버퍼
// int wIdx;                         // 생산자 스레드가 queue[]에 저장할 다음 인덱스
// int rIdx;                         // 소비자 스레드가 queue[]에서 읽을 다음 인덱스

// void *producer(void *arg)
// { // 생산자 스레드 함수
//   for (int i = 0; i < 10; i++)
//   {
//     mywrite(i); // 정수 i를 공유버퍼에 저장

//     // m 밀리초 동안 잠을 잔다.
//     int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
//     usleep(MILLI * m * 10); // m*10 밀리초동안 잠자기
//   }
//   return NULL;
// }

// void *consumer(void *arg)
// { // 소비자 스레드 함수
//   for (int i = 0; i < 10; i++)
//   {
//     int n = myread(); // 공유버퍼의 맨 앞에 있는 정수 읽어 리턴

//     // m 밀리초 동안 잠을 잔다.
//     int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
//     usleep(MILLI * m * 10); // m*10 밀리초 동안 잠자기
//   }
//   return NULL;
// }

// void mywrite(int n)
// {                      // 정수 n을 queue[]에 삽입
//   sem_wait(&semWrite); // queue[]에 저장할 수 있는지 확인하고 없다면 대기청

//   pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠그기
//   queue[wIdx] = n;                       // 버퍼에 정수 n을 삽입한다.
//   wIdx++;
//   wIdx %= N_COUNTER;
//   pthread_mutex_unlock(&critical_section); // 뮤텍스 락 열기
//   printf("producer %d : wrote %d\n", gettid(), n);
//   sem_post(&semRead); // consumer 스레드 깨우기
// }

// int myread()
// {                     // queue[]의 맨 앞에 있는 정수를 읽어 리턴
//   sem_wait(&semRead); // queue[]에서 읽을 수 있는지 확인하고 없다면 대기

//   pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠그기
//   int n = queue[rIdx];                   // 버퍼에서 정수를 읽는다.
//   rIdx++;
//   rIdx %= N_COUNTER;
//   pthread_mutex_unlock(&critical_section); // 뮤텍스 락 열기
//   printf("\tconsumer %d : read %d\n", gettid(), n);
//   sem_post(&semWrite); // producer 스레드 깨우기

//   return n;
// }

// int main()
// {
//   pthread_t t[4]; // 스레드구조체

//   srand(time(NULL));                           // 난수 발생 초기화(seed 랜덤 지정)
//   pthread_mutex_init(&critical_section, NULL); // 뮤텍스 락 초기화

//   int res = sem_open(&semWrite, 0, N_COUNTER); // 가용 버퍼의 개수를 N_COUNTER로 초기화
//   if (res == -1)
//   {
//     printf("semaphore is not supported\n");
//     return 0;
//   }
//   sem_init(&semRead, 0, 0); // 가용 버퍼의 개수를 0으로 초기화

//   // producer와 consumer 스레드 생성
//   pthread_create(&t[0], NULL, producer, NULL); // 생산자 스레드 생성
//   pthread_create(&t[1], NULL, consumer, NULL); // 소비자 스레드 생성
//   pthread_create(&t[2], NULL, producer, NULL); // 소비자 스레드 생성
//   pthread_create(&t[4], NULL, consumer, NULL); // 소비자 스레드 생성

//   for (int i = 0; i < 4; i++)
//     pthread_join(t[i], NULL); // 모든 스레드가 종료할 때까지 대기

//   sem_destroy(&semRead);  // 세마포 기능 소멸
//   sem_destroy(&semWrite); // 세마포 기능 소멸

//   pthread_mutex_destroy(&critical_section); // 뮤텍스 락 소멸

//   return 0;
// }

// #define _GNU_SOURCE
// #include <stdio.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>
// #include <stdlib.h>

// #define N_COUNTER 4 // 공유 버퍼의 크기. 정수 4개 저장
// #define MILLI 1000

// void mywrite(int n);
// int myread();

// pthread_mutex_t critical_section; // 뮤텍스
// sem_t semWrite, semRead;          // POSIX 세마포
// #define SEM_NAME "/toi1"
// int queue[N_COUNTER]; // 4개의 정수를 저장하는 공유 버퍼
// int wIdx;             // 생산자 스레드가 queue[]에 저장할 다음 인덱스
// int rIdx;             // 소비자 스레드가 queue[]에서 읽을 다음 인덱스

// void *producer(void *arg)
// { // 생산자 스레드 함수
//   for (int i = 0; i < 10; i++)
//   {
//     mywrite(i); // 정수 i를 공유버퍼에 저장

//     // m 밀리초 동안 잠을 잔다.
//     int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
//     usleep(MILLI * m * 10); // m*10 밀리초동안 잠자기
//   }
//   return NULL;
// }

// void *consumer(void *arg)
// { // 소비자 스레드 함수
//   for (int i = 0; i < 10; i++)
//   {
//     int n = myread(); // 공유버퍼의 맨 앞에 있는 정수 읽어 리턴

//     // m 밀리초 동안 잠을 잔다.
//     int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
//     usleep(MILLI * m * 10); // m*10 밀리초 동안 잠자기
//   }
//   return NULL;
// }

// void mywrite(int n)
// {                      // 정수 n을 queue[]에 삽입
//   sem_wait(&semWrite); // queue[]에 저장할 수 있는지 확인하고 없다면 대기청

//   pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠그기
//   queue[wIdx] = n;                       // 버퍼에 정수 n을 삽입한다.
//   wIdx++;
//   wIdx %= N_COUNTER;
//   pthread_mutex_unlock(&critical_section); // 뮤텍스 락 열기
//   // printf("producer %d : wrote %d\n", gettid(), n);
//   printf("producer %lu : wrote %d\n", (unsigned long)pthread_self(), n);
//   sem_post(&semRead); // consumer 스레드 깨우기
// }

// int myread()
// {                     // queue[]의 맨 앞에 있는 정수를 읽어 리턴
//   sem_wait(&semRead); // queue[]에서 읽을 수 있는지 확인하고 없다면 대기

//   pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠그기
//   int n = queue[rIdx];                   // 버퍼에서 정수를 읽는다.
//   rIdx++;
//   rIdx %= N_COUNTER;
//   pthread_mutex_unlock(&critical_section); // 뮤텍스 락 열기
//   // printf("\tconsumer %d : read %d\n", gettid(), n);
//   printf("\tconsumer %lu : read %d\n", (unsigned long)pthread_self(), n);
//   sem_post(&semWrite); // producer 스레드 깨우기
//   return n;
// }

// int main()
// {
//   pthread_t t[4]; // 스레드구조체

//   srand(time(NULL));                           // 난수 발생 초기화(seed 랜덤 지정)
//   pthread_mutex_init(&critical_section, NULL); // 뮤텍스 락 초기화

//   int res = sem_open(&semWrite, 0, N_COUNTER); // 가용 버퍼의 개수를 N_COUNTER로 초기화
//   if (res == -1)
//   {
//     printf("semaphore is not supported\n");
//     return 0;
//   }
//   sem_open(&semRead, 0, 0); // 가용 버퍼의 개수를 0으로 초기화

//   // producer와 consumer 스레드 생성
//   pthread_create(&t[0], NULL, producer, NULL); // 생산자 스레드 생성
//   pthread_create(&t[1], NULL, consumer, NULL); // 소비자 스레드 생성
//   pthread_create(&t[2], NULL, producer, NULL); // 소비자 스레드 생성
//   pthread_create(&t[3], NULL, consumer, NULL); // 소비자 스레드 생성

//   for (int i = 0; i < 4; i++)
//     pthread_join(t[i], NULL); // 모든 스레드가 종료할 때까지 대기

//   sem_destroy(&semRead);  // 세마포 기능 소멸
//   sem_destroy(&semWrite); // 세마포 기능 소멸

//   pthread_mutex_destroy(&critical_section); // 뮤텍스 락 소멸

//   return 0;
// }

#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>    // O_CREAT 정의를 위해 추가
#include <sys/stat.h> // S_IRUSR, S_IWUSR 정의를 위해 추가

#define N_COUNTER 4 // 공유 버퍼의 크기. 정수 4개 저장
#define MILLI 1000
#define SEM_NAME "/toi1" // 세마포어 이름 정의

void mywrite(int n);
int myread();

pthread_mutex_t critical_section; // 뮤텍스
sem_t *semWrite;                  // POSIX 세마포 포인터
sem_t *semRead;                   // POSIX 세마포 포인터
int queue[N_COUNTER];             // 4개의 정수를 저장하는 공유 버퍼
int wIdx = 0;                     // 생산자 스레드가 queue[]에 저장할 다음 인덱스
int rIdx = 0;                     // 소비자 스레드가 queue[]에서 읽을 다음 인덱스

void *producer(void *arg)
{ // 생산자 스레드 함수
  for (int i = 0; i < 10; i++)
  {
    mywrite(i); // 정수 i를 공유버퍼에 저장

    // m 밀리초 동안 잠을 잔다.
    int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
    usleep(MILLI * m * 10); // m*10 밀리초동안 잠자기
  }
  return NULL;
}

void *consumer(void *arg)
{ // 소비자 스레드 함수
  for (int i = 0; i < 10; i++)
  {
    int n = myread(); // 공유버퍼의 맨 앞에 있는 정수 읽어 리턴

    // m 밀리초 동안 잠을 잔다.
    int m = rand() % 10;    // 0~9 사이의 랜덤한 정수
    usleep(MILLI * m * 10); // m*10 밀리초 동안 잠자기
  }
  return NULL;
}

void mywrite(int n)
{                     // 정수 n을 queue[]에 삽입
  sem_wait(semWrite); // queue[]에 저장할 수 있는지 확인하고 없다면 대기

  pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠금
  queue[wIdx] = n;                       // 버퍼에 정수 n을 삽입
  wIdx++;
  wIdx %= N_COUNTER;
  pthread_mutex_unlock(&critical_section); // 뮤텍스 락 해제
  printf("producer %lu : wrote %d\n", (unsigned long)pthread_self(), n);
  sem_post(semRead); // consumer 스레드 깨우기
}

int myread()
{                    // queue[]의 맨 앞에 있는 정수를 읽어 리턴
  sem_wait(semRead); // queue[]에서 읽을 수 있는지 확인하고 없다면 대기

  pthread_mutex_lock(&critical_section); // 뮤텍스 락 잠금
  int n = queue[rIdx];                   // 버퍼에서 정수를 읽음
  rIdx++;
  rIdx %= N_COUNTER;
  pthread_mutex_unlock(&critical_section); // 뮤텍스 락 해제
  printf("\tconsumer %lu : read %d\n", (unsigned long)pthread_self(), n);
  sem_post(semWrite); // producer 스레드 깨우기
  return n;
}

int main()
{
  pthread_t t[4]; // 스레드 구조체

  srand(time(NULL));                           // 난수 발생 초기화(seed 랜덤 지정)
  pthread_mutex_init(&critical_section, NULL); // 뮤텍스 락 초기화

  // 세마포 초기화
  semWrite = sem_open(SEM_NAME, O_CREAT, S_IRUSR | S_IWUSR, N_COUNTER); // 가용 버퍼의 개수를 N_COUNTER로 초기화
  if (semWrite == SEM_FAILED)
  {
    printf("semaphore is not supported\n");
    return 0;
  }

  semRead = sem_open("/semRead", O_CREAT, S_IRUSR | S_IWUSR, 0); // 가용 버퍼의 개수를 0으로 초기화
  if (semRead == SEM_FAILED)
  {
    printf("semaphore is not supported\n");
    return 0;
  }

  // producer와 consumer 스레드 생성
  pthread_create(&t[0], NULL, producer, NULL); // 생산자 스레드 생성
  pthread_create(&t[1], NULL, consumer, NULL); // 소비자 스레드 생성
  pthread_create(&t[2], NULL, producer, NULL); // 생산자 스레드 생성
  pthread_create(&t[3], NULL, consumer, NULL); // 소비자 스레드 생성

  for (int i = 0; i < 4; i++)
    pthread_join(t[i], NULL); // 모든 스레드가 종료할 때까지 대기

  sem_close(semRead);  // 세마포어 종료
  sem_close(semWrite); // 세마포어 종료

  sem_unlink("/semRead"); // 세마포어 해제
  sem_unlink(SEM_NAME);   // 세마포어 해제

  pthread_mutex_destroy(&critical_section); // 뮤텍스 락 소멸

  return 0;
}
