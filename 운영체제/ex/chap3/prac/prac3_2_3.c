#include <stdio.h>
#include <stdlib.h>

void f();

int a=10;
int main() {
	int b=20;
	int* p = (int*)malloc(100);
	f();
	printf("%d", b);
	return -1;
}
void f() {
	int c=30;
	printf("%d", c);
}
