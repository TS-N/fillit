#include <stdio.h>

int main()
{
	unsigned long long  int ar[19] = {0x8000c0004,
0x8000800080008,
0x2000e,
0xf,
0xe0002,
0xc00080008,
0xc00040004,
0xe0008,
0x8000e,
0xc0006,
0x6000c,
0xc000c,
0x4000c0008,
0x40004000c,
0x80008000c,
0x4000e,
0xe0004,
0x8000c0008,
0x4000c0004};
int i = 0;
while (i < 19)
{
	printf("%llx\n", ar[i] << 12);
	++i;
}
return 0;
}
