#include <stdio.h>
#include <stdlib.h>

void f();
void g();

int a[100];
int main() {
	int b=1;
	f(2);
	return 0;
}
void f(int c) {
	int d=3;
	g();
	printf("%d", c);
}
void g() {
	int* p = (int*)malloc(100);
}
