#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
  
int main() { 
    char user[80]; 
    int i, n;
    int fdw; 
    char *myfifo = "./my-fifo";  // FIFO의 이름 경로명

    mkfifo(myfifo, 0666); // ./my-fifo 이름의 FIFO 생성
    fdw = open(myfifo, O_WRONLY); // myfifo를 쓰기 모드로 열기

    while (1) { 
	printf(">>>");
        fgets(user, 80, stdin); // 키보드에서 문자열 입력, 최대 80개 문자
	if(user[strlen(user)-1] == '\n') {
		user[strlen(user)-1] = '\0';
	}
        write(fdw, user, strlen(user)+1); // user 배열의 문자열을 myfifo에 쓰기 
        if(strcmp(user, "exit") == 0) {
                printf("break 합니다\n");
                break;
        }  
    } 
    close(fdw);
    return 0; 
}
