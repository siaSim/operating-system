#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void myhandler(int sig) {
    char s[] = "부모로부터 SIGUSR2 신호 수신\n";
    write(1, s, strlen(s));
}

int main() {
  signal(SIGUSR2, myhandler); // 사용자 정의 신호 핸들러 등록

  while(1) {
    printf("자식 프로세스 실행 중 ...\n");
    sleep(1);
  }
}
