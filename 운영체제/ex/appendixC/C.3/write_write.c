#include <stdio.h>
#include <string.h>
#include <fcntl.h>      // O_WRDONLY와 O_CREAT 상수 정의
#include <unistd.h>    

int main() {
        char* file = "textWW.txt";

        int fd1 = open(file, O_WRONLY | O_CREAT, 0644); // 쓰기 모드 열기
        if (fd1 < 0) {
                printf("파일을 열 수 없다 1");
                return 0;
        }

        int fd2 = open(file, O_WRONLY | O_CREAT, 0644); // 쓰기 모드 열기
        if (fd2 < 0) {
                printf("파일을 열 수 없다 2");
                return 0;
        }

        write(fd1, "AAA", strlen("AAA")); // 옵셋 0부터 AAA 저장
        write(fd2, "BBB", strlen("BBB")); // 옵셋 0부터 AAA 위에 BBB로 덮어씀
        write(fd1, "aaa", strlen("aaa")); // 옵셋 3부터 aaa 저장
        write(fd2, "bbb", strlen("bbb")); // 옵셋 3부터 aaa 위에 bbb로 덮어씀

        close(fd1);
        close(fd2);
}
