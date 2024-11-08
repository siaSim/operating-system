// // #include <stdio.h>
// // #include <sys/types.h>
// // #include <sys/wait.h>
// // #include <unistd.h>

// // int main()
// // {
// //   pid_t pid;
// //   int i, sum = 0;

// //   pid = fork(); // 자식프로세스 생성
// //   if (pid > 0)
// //   { // 부모 프로세스에 의해 실행되는 코드
// //     printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
// //     printf("부모프로세스: pid = %d\n", getpid());
// //     wait(NULL); // 자식프로세스가 종료할 때까지 대기
// //     printf("부모프로세스종료\n");
// //     return 0;
// //   }
// //   else if (pid == 0)
// //   { // 자식 프로세스에 의해 실행되는 코드
// //     printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
// //     printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());
// //     sum = 0;
// //     for (i = 1; i <= 100; i++)
// //       sum += i;
// //     printf("자식프로세스: sum = %d\n", sum);
// //     return 0;
// //   }
// //   else
// //   { // fork() 오류
// //     printf("fork 오류");
// //     return 0;
// //   }
// // }

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main()
// {
//   pid_t pid;
//   int i, sum = 0;

//   for (int j = 0; j < 3; j++)
//   {
//     pid = fork(); // 자식 프로세스 생성

//     if (pid > 0)
//     { // 부모 프로세스에 의해 실행되는 코드
//       printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
//       printf("부모프로세스: pid = %d\n", getpid());
//       // wait(NULL); // 자식프로세스가 종료할 때까지 대기
//     }

//     else if (pid == 0)
//     { // 자식 프로세스에 의해 실행되는 코드
//       printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
//       printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());
//       sum = 0;
//       for (i = 1; i <= 100; i++)
//         sum += i;
//       printf("자식프로세스: sum = %d\n\n", sum);
//       getchar();
//       return 0;
//     }
//     else
//     { // fork() 오류
//       printf("fork 오류");
//       return 0;
//     }
//   }
//   printf("부모프로세스 종료\n");
//   char c = getchar();
//   return 0;
// }

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  int i, sum = 0;

  for (int j = 0; j < 3; j++)
  {
    pid = fork(); // Create child process

    if (pid > 0)
    { // Code executed by the parent process
      printf("부모프로세스: fork()의 리턴 값 = 자식프로세스 pid = %d\n", pid);
      printf("부모프로세스: pid = %d\n", getpid());
    }
    else if (pid == 0)
    { // Code executed by the child process
      printf("자식프로세스: fork()의 리턴 값 pid = %d\n", pid);
      printf("자식프로세스: pid = %d, 부모프로세스 pid = %d\n", getpid(), getppid());

      // Simulate some work in the child process
      sum = 0;
      for (i = 1; i <= 100; i++)
        sum += i;
      printf("자식프로세스: sum = %d\n\n", sum);

      // Sleep for a while to simulate a longer-running child process
      sleep(20);

      return 0; // Child process terminates here
    }
    else
    { // fork() error
      printf("fork 오류");
      return 0;
    }
  }

  // Parent process waits for all child processes to finish
  for (int j = 0; j < 3; j++)
  {
    wait(NULL); // Wait for each child process to terminate
  }

  printf("부모프로세스 종료\n");
  getchar(); // Wait for user input before exiting
  return 0;
}
