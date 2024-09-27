#include <stdio.h>
#include <signal.h>

void myhandler(int sig){
  printf("안녕하세요\n");
}

int main(){
  signal(SIGUSR1, myhandler); // SIGUSR1 신호 핸들러로 myhandler() 함수 등록
  raise(SIGUSR1); // 프로세스 자신에게 SIGUSR1 신호 전송
}
