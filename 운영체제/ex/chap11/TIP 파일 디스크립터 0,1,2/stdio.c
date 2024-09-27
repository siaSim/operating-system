#include <stdio.h>
int main() {
	char c;
	fscanf(stdin, "%c", &c);
	fprintf(stdout, "%c", c);
	fprintf(stderr, "hello\n");
}
