#include <iostream>
#include <stdio.h>

int main()
{
	int res1, x;

x_valid:
	std::cout << "from 1 to 10\n";
	std::cin >> x;
	if (x < 1 && x > 10)
	{
		goto x_valid;
	}
	__asm {
		mov  eax, x; // x
		mov	 ebx, 1; // i
		mov  ecx, 0; // res

	while_loop:
		cmp  ebx, eax;
		jg	 exit_loop;

		mov edx, ebx;

		add  edx, 2;	// i + 2
		imul edx, edx;	// i*i be like ^2
		sub  edx, ebx	// (i+2)^2 - i

		inc  ebx;
		add  ecx, edx;
		jmp  while_loop;

		jmp  exit_loop;
	exit_loop:
		mov  res1, ecx;
	}
	std::cout << "\nResult: " << res1 << std::endl;
}