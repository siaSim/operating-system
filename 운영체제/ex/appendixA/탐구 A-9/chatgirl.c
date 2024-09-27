#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
   char user[80], other[80];
    int i, n;
    int fdw, fdr;
    char * myfifoA = "./my-fifo-a";  // FIFO의 이름 경로명
    char * myfifoB = "./my-fifo-b";  // FIFO의 이름 경로명

    mkfifo(myfifoA, 0666); // ./my-fifo-a 이름의 FIFO 생성
    mkfifo(myfifoB, 0666); // ./my-fifo-b 이름의 FIFO 생성

    fdr = open(myfifoA, O_RDONLY); // myfifoA를 읽기 모드로 열기
    fdw = open(myfifoB, O_WRONLY); // myfifoB를 쓰기 모드로 열기

    while (1) { 
        i=0;
 	while((n = read(fdr, &other[i], 1)) > 0) {
                if(other[i] == '\0') break;
                if(i == 78) {
                        other[++i] = '\0';
                        break; // 널을저장할 공간만 남기고 리턴
                }
		i++;
        }
	if(n <= 0) {
        	printf("상대가 종료하였습니다.\n"); 
		break;
	}
        printf("other: %s\n", other); 
        if(strcmp(other, "exit\n") == 0) {
                printf("break 합니다\n");
                break; // 루프 종료
        }

	printf(">>>");
        fgets(user, 80, stdin); 
        write(fdw, user, strlen(user)+1); 
        if(strcmp(user, "exit\n") == 0) {
                printf("break 합니다\n");
		break;
	}
    } 
    close(fdw);
    close(fdr);
    return 0; 
} 
