// Passagens de parâmetro

#include <stdio.h>
#include <stdlib.h>

#define asm_beg ".intel_syntax noprefix\n"
#define asm_end ".att_syntax   prefix  \n"

int soma(int a, int b) {
	asm(asm_beg

		// [ebp+8] -> Valor do primeiro parâmetro
		// [ebp+12] -> Valor do segundo parâmetro
		" mov eax, [ebp+8] \n"
		" add eax, [ebp+12] \n"
		// o valor que ficar no eax é o retorno da função

	asm_end);
}

int mul(int a, int b) {
	asm(asm_beg

		" mov eax, [ebp+8] \n"
		" mul dword ptr [ebp+12] \n"
		// dword ptr -> indica que o acesso à memória de ebp+12 deve considerar 4 bytes

	asm_end);
}

int main() {
	int a, b;
	printf("Insira dois valores inteiros: ");
	scanf("%d%d", &a, &b);
	printf("a + b = %d\n", soma(a, b));
	printf("a * b = %d\n", mul(a, b));
}