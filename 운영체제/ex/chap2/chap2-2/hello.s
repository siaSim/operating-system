# 화면에 "Hello World"를 출력하는 어셈블리 프로그램으로 hello.s에 저장
# 64-bit 리눅스에서 실행
#
# 프로그램 시작 
    .global _start
    .text
_start:
    # write(1, message, 12) 시스템 호출, 화면 출력 
    mov     $1, %rax       	# 1은 write 시스템 호출 번호, rax 레지스터에 저장
    mov     $1, %rdi       	# 1은 표준출력장치(디스플레이)의 파일디스크립터번호, rdi에 저장
    mov     $msg, %rsi     	# msg는 출력할 문자열의 주소, rsi 레지스터에 저장
    mov     $12, %rdx      	# 12는 출력할 바이트 수, rdx 레지스터에 저장
    syscall                  	# 시스템 호출 기계 명령 실행
                                # 화면에 Hello world를 출력하는 write 시스템 호출 실행

    # exit(0) 시스템 호출,  프로그램 종료
    mov     $60, %rax      	# 60은 exit 시스템 호출 번호, rax 레지스터에 저장
    xor     %rdi, %rdi       	# xor 명령 후 rdi 레지스터 값은 0이 됨. 0은 종료코드
    syscall                  	# 시스템 호출 기계 명령 실행
                                # 프로그램을 종료시키는 exit 시스템 호출 실행. 프로그램 종료
msg:
    .ascii  "22017118시아\n"    # 12개의 문자로 구성된 문자열
