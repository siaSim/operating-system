#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/kitae_shm"	// 공유 메모리 이름

int main() {
	const int SIZE = 10*sizeof(int); // 10개의 int 크기
	const char *name = SHM_NAME; // 공유 메모리 이름
	int shm_fd; // 공유 메모리체에 대한 파일 디스크립터
	int i, *data; // data는 공유 메모리에 대한 주소

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0600); // 공유 메모리 열기

	ftruncate(shm_fd, SIZE); // 10개의 정수 크기로 설정(40바이트)
	data = (int*)mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	for(i=0; i<10; i++)
		data[i] = i+1; // 공유 메모리에 1에서 10까지 저장 
	printf("공유 메모리에 1에서 10까지 저장\n");
	munmap(data, SIZE);
	close(shm_fd);

	return 0;
}
