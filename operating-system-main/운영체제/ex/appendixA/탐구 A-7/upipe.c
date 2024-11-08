#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char buf[6] = "hello";

    if (pipe(fd) == -1) {
        perror("pipe() error");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) { // 자식 프로세스 : 파이프에서 읽음
        close(fd[1]); // 쓰기용fd[1]은 사용하지 않으므로 닫기
        read(fd[0], buf, 5); // fd[0]에 데이터가 없으면 생길 때까지 기다림
        write(1, buf, 5); // 수신 받은 문자열을 화면에 출력 
        write(1, "\n", 1); // 개행 문자 출력, 다음 라인으로 넘어가기

        close(fd[0]);
        return 0;
    } else {      // 부모 프로세스 : 파이프에 쓰기
        close(fd[0]);  // 읽기용 fd[0]는 사용하지 않으므로 닫기
        write(fd[1], buf, strlen(buf)); // 파이프에 buf에 들어 있는 "hello" 전송 
        close(fd[1]); // 파이프 닫기. 파이프를 읽는 프로세스는 EOF를 읽게 됨
        wait(NULL); // 자식 프로세스 종료 대기
        return 0;
    }
}
