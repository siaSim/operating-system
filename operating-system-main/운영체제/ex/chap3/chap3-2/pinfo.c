#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t pid, ppid;
  pid = getpid();   // 현재 프로세스의 PID 알아내기
  ppid = getppid(); // 부모 프로세스의 PID 알아내기
  printf("프로세스 PID = %d, 부모 프로세스 PID = %d\n", pid, ppid);
  sleep(30);
}
