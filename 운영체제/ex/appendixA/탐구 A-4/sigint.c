#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myhandler(int sig){
  write(1, "Ctrl-C typed\n", 13); // 1은 표준출력장치, 13은 출력할 글자 수
}

int main(){
  signal(SIGINT, myhandler); // SIGINT 신호 핸들러로 myhandler() 함수 등록

  while(1) { // 무한루프
    sleep(10); // 초 동안 잠자기
    printf("신호 때문에 잠 깼어요\n");
  }
}
