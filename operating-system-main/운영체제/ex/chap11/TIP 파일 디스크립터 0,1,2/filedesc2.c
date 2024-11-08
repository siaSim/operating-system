#include <unistd.h>
int main() {
	char c;
	read(STDIN_FILENO, &c, 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDERR_FILENO, "hello\n", 6);
}
