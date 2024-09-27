#include <stdio.h>
#include <string.h>
#include <fcntl.h>      // O_RDONLY, O_로 시작되는 상수들 정의
#include <unistd.h>	// 리눅스에서 실행할 때 write() 함수 등에 필요

int main() {
	char* file = "text.txt"; // 현재 파일에 Suyeon Hwang가 저장된 상태
	char buf1[1024] = { 0 };
	int fd1 = open(file, O_RDONLY);
	if (fd1 < 0) {
		printf("파일을 열 수 없다 1");
		return 0;
	}

	getchar();

	read(fd1, buf1, 5);
	printf("%s\n", buf1);

	close(fd1);
}
