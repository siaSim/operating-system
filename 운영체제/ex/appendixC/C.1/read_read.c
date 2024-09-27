#include <stdio.h>
#include <string.h>
#include <fcntl.h>      // O_RDONLY 상수 정의
#include <unistd.h>

int main() {
	char* file = "textRR.txt"; // textRR.txt 파일에 Suyeon Hwang이 저장되어 있음
	char buf1[100] = { 0 }; // 배열 전체를 0으로 초기화
	char buf2[100] = { 0 }; // 배열 전체를 0으로 초기화

	int fd1 = open(file, O_RDONLY); // 읽기 모드로 파일 열기
	if (fd1 < 0) {
		printf("파일을 열 수 없다 1");
	return 0;
	}

	int fd2 = open(file, O_RDONLY); // 읽기 모드로 파일 열기
	if (fd2 < 0) {
		printf("파일을 열 수 없다 2");
		return 0;
	}

	read(fd1, buf1, 5); // fd1로 옵셋 0부터 5바이트 읽기
	printf("%s\n", buf1);

	read(fd2, buf2, 5); // fd1로 옵셋 0부터 5바이트 읽기
	printf("%s\n", buf2);

	close(fd1);
	close(fd2);
}
