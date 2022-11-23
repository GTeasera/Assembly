#include <iostream>
#include <stdio.h>

int main() {
	int x, result, ddd = 25;
	std::cin >> x;
	__asm {
		mov eax, x;
		cmp eax,0;
		jg bigger;
		cmp eax, 0;
		jl smaller;
		cmp eax, 0;
		je equal;

	bigger:
		// 5 * x − (2 + x)^2
		mov ecx, 2; // ecx = 2
		add ecx, eax; // ecx + eax
		imul ecx, ecx; // ecx * ecx its like ^2
		imul eax, 5; // eax(x) * 5
		sub eax, ecx; // eax - ecx its like x - ecx
		jmp exit_if;

	smaller:
		// 6 + x * 125,
		imul eax, 125; // x * 125
		add eax, 6; // x + 6
		jmp exit_if;
	equal:
		// ((x+15)^2)/25
		add eax, 15; // x + 15
		imul eax, eax; // x*x its like ^2
		cdq; 
		idiv ddd; // x/25
		jmp exit_if;
	exit_if:
		mov result, eax;
	} // End of the method “main”
	std::cout << "\nResult: " << result << std::endl;
} 