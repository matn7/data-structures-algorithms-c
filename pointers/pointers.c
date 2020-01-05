#include <stdio.h>

struct {
	int ***ippp;
	int **ipp;
	int *ip;
	int i;
} p;

int main(int ac, char **av) {
	p.ippp = &p.ipp;
	p.ipp = &p.ip;
	p.ip = &p.i;
	p.i = 0x55555555;

	return 0;
}
