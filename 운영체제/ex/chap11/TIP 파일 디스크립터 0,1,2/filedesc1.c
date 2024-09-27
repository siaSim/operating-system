#include <unistd.h>
int main() {
	char c;
	read(0, &c, 1); // 0번 파일 디스크립터(키보드)에서 문자를 읽어 변수 c에 저장
	write(1, &c, 1); // 1번 파일 디스크립터(디스플레이)에 변수 c의 문자 출력
	write(2, "hello\n", 6); // 2번 파일 디스크립터(디스플레이)에 "hello\n" 출력
}
