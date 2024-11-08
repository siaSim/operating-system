#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myhandler(int signum){
  printf("0으로 나누기\n");
}

int main(){
  int n =100;
  int m = 0;
  signal(SIGFPE, myhandler); // SIGINT 신호의 핸들러로 myhandler() 함수 등록
  n = n / m; // 이 나우기 연산은 0으로 나누기가 발생하여 SIGFPE 신호가 발생하고
	     // myhandler 함수가 실행된다. 하지만 이미 심각한 오류가 발생하였기
	     // 때문에 핸들러가 반복하여 실행되는 등 이상 현상을 보이므로
	     // Ctrl-C 키를 입력하여 프로그램을 종료해야 한다.
}
