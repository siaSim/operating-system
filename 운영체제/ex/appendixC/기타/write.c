#include <stdio.h>
#include <string.h>
#include <fcntl.h>      // O_RDONLY, O_로 시작되는 상수들 정의
#include <unistd.h>	// 리눅스에서 실행할 때 write() 함수 등에 필요

int main() {
	char* file = "text.txt";

	int fd2 = open(file, O_WRONLY | O_CREAT, 0644); // 0644 -> rw-r--r--
	if (fd2 < 0) {
		printf("파일을 열 수 없다 2");
		return 0;
	}

	write(fd2, "BBB", strlen("BBB"));
	write(fd2, "bbb", strlen("bbb"));

	close(fd2);
}
