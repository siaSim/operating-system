#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    pid_t pid = fork(); //  자식 프로세스 생성
    if(pid == 0) { // 자식 프로세스 코드
        execl("./sigreceiver", "sigreceiver", NULL);
    }
    else if(pid > 0) { // 부모 프로세스 코드
       while(1) {
         char c = getchar(); // 키 입력
         switch(c) {
             case 'k' :  //'k' 키가 입력되면 자식 프로세스 종료
                kill(pid, SIGKILL);  // 자식 프로세스에게 SIGKILL 신호 전송
                exit(0);
             default : // 그 외 키의 경우 자식 프로세스에게 SIGUSR2 신호 전송
                kill(pid, SIGUSR2); 
         }
       }
    }
    else if(pid < 0) // fork() 오류
        return -1;
}
