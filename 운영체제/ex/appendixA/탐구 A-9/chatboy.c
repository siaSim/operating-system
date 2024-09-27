#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
  
int main() { 
    char user[80], other[80]; 
    int i, n;
    int fdw, fdr; 
    char *myfifoA = "./my-fifo-a";  // FIFO의 이름 경로명
    char *myfifoB = "./my-fifo-b";  // FIFO의 이름 경로명

    mkfifo(myfifoA, 0666); // ./my-fifo-a 이름의 FIFO 생성
    mkfifo(myfifoB, 0666); // ./my-fifo-b 이름의 FIFO 생성

    fdw = open(myfifoA, O_WRONLY); // myfifoA를 쓰기 모드로 열기
    fdr = open(myfifoB, O_RDONLY); // myfifoB를 읽기 모드로 열기

    while (1) { 
	printf(">>>");
        fgets(user, 80, stdin); // 키보드에서 문자열 입력, 최대 80개 문자
        write(fdw, user, strlen(user)+1); // user 배열의 문자열을 myfifo에 쓰기 
        if(strcmp(user, "exit\n") == 0) {
                printf("break 합니다\n");
                break;
        }  
	i=0;
	while((n=read(fdr, &other[i], 1)) > 0) { // myfifo에서 읽어 other 배열에  
		if(other[i] == '\0') break;
		if(i == 78) {
			other[++i] = '\0';
			break; // 널을 위한 공간만 남기고 리턴	
		}
		i++;
	}
        if(n <= 0) {
		printf("상대가 종료하였습니다.\n");
                break;
        }
 	printf("other: %s\n", other); 
	if(strcmp(other, "exit\n") == 0) {
		printf("exit이므로 break 합니다\n");
		break; // 루프 종료
	}
    } 
    close(fdw);
    close(fdr);
    return 0; 
}
