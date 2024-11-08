// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main() {
// 	pid_t pid;

// 	pid = fork(); // 자식 프로세스 생성

// 	if (pid > 0) { // 부모 프로세스 코드
// 		printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
// 		printf("부모프로세스: 프로세스 pid = %d\n", getpid());
// 		wait(NULL); // 자식프로세스가 종료할 때까지 대기
// 		return 0;
// 	}
// 	else if (pid == 0) { // 자식 프로세스 코드
// 		printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
// 		printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());
// 		execlp("/bin/ls", "ls", "-l", NULL); // /bin/ls를 현재프로세스에 오버레이하여 실행
// 	}
// 	else { // fork() 오류
// 		printf("fork 오류");
// 		return 0;
// 	}
// }

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main()
// {
//   pid_t pid;

//   pid = fork(); // 자식 프로세스 생성

//   if (pid > 0)
//   { // 부모 프로세스 코드
//     printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
//     printf("부모프로세스: 프로세스 pid = %d\n", getpid());
//     wait(NULL); // 자식프로세스가 종료할 때까지 대기
//     sleep(10);
//     return 0;
//   }
//   else if (pid == 0)
//   { // 자식 프로세스 코드
//     printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
//     printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());

//     sleep(10); // 10초 동안 대기
//   }
//   else
//   { // fork() 오류
//     printf("fork 오류");
//     return 0;
//   }
// }

#include <stdio.h>
#include <stdlib.h> // system() 함수를 사용하기 위해 추가
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  pid = fork(); // 자식 프로세스 생성

  if (pid > 0)
  { // 부모 프로세스 코드
    printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
    printf("부모프로세스: 프로세스 pid = %d\n", getpid());

    // 부모가 자식 프로세스가 종료되기 전에 ps 명령어 실행
    char command[256];
    sprintf(command, "ps -p %d,%d -o user,pid,%%cpu,%%mem,vsz,rss,tty,stat,start,time,command", getpid(), pid);
    system(command);

    wait(NULL); // 자식 프로세스가 종료할 때까지 대기
  }
  else if (pid == 0)
  { // 자식 프로세스 코드
    printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
    printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());

    // 자식 프로세스에서 5초 대기
    sleep(15);
  }
  else
  { // fork() 오류
    printf("fork 오류");
    return 0;
  }

  return 0;
}
