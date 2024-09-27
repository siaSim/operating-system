#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/kitae_shm"	// 공유 메모리 이름

int main() {
	const int SIZE  = 10*sizeof(int); 
	const char *name = SHM_NAME; // 공유 메모리
	int shm_fd, i, sum=0;
	int *data;

	shm_fd = shm_open(name, O_RDWR, 0600); // 공유 메모리 열기
	if(shm_fd == -1) {
		printf("%s 이름의 공유메모리 열기실패\n", name);
		return 0;
	}
	data = (int*)mmap(0, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);

	for(i=0; i<10; i++)
		sum += data[i];
	printf("공유 메모리 읽은 후, 합은 %d\n", sum);
	munmap(data, SIZE);
	close(shm_fd);
	shm_unlink(SHM_NAME);

	return 0;
}

