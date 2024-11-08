#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() { 
    char in[80];
    int i, n;
    int fdr;
    char *myfifo = "./my-fifo";  // FIFO의 이름 경로명

    mkfifo(myfifo, 0666); // ./my-fifo 이름의 FIFO 생성
    fdr = open(myfifo, O_RDONLY); // myfifo를 쓰기 모드로 열기

    while (1) { 
        i=0;
 	while((n = read(fdr, &in[i], 1)) > 0) {
                if(in[i] == '\0') break;
                if(i == 78) {
                        in[++i] = '\0';
                        break; // 널을저장할 공간만 남기고 리턴
                }
		i++;
        }
	if(n <= 0) {
        	printf("서버가 종료하였습니다.\n"); 
		break;
	}
        else if(strcmp(in, "exit") == 0) {
                printf("서버로부터 종료 문자열 exit을 받고 종료합니다.\n");
                break;
        }
        printf("%s\n", in);  // 서버로부터 받은 텍스트 출력
    } 
    close(fdr);
    return 0; 
} 
