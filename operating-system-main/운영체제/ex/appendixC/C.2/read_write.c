#include <stdio.h>
#include <string.h>
#include <fcntl.h>      // O_RDONLY와 O_RDWR 상수 정의
#include <unistd.h>

int main() {
	char* file = "textRW.txt"; // textRW.txt 파일에 Hwang Suyeon이 저장되어 있음
	char buf[100] = { 0 }; // 배열을 모두 0으로 초기화

	int fd1 = open(file, O_RDONLY); // 읽기 모드로 열기
	if (fd1 < 0) {
		printf("파일을 열 수 없다 1");
		return 0;
	}

	int fd2 = open(file, O_RDWR); // 읽기와 쓰기가 모두 가능한 모드로 열기
	if (fd2 < 0) {
		printf("파일을 열 수 없다 2");
		return 0;
	}

	write(fd2, "Hello", strlen("Hello"));  // 파일의 처음부터 Hello를 기록함
				// write()의 실행 결과 Hwang이 Hello로 바뀌었음
        
	read(fd1, buf, 12); // 파일에서 12바이트 읽기
	printf("%s\n", buf); // Hello Suyeon 출력

	close(fd1);
	close(fd2);
}
