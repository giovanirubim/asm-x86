// Acesso a endereços

#include <stdio.h>
#include <stdlib.h>

#define asm_beg ".intel_syntax noprefix\n"
#define asm_end ".att_syntax   prefix  \n"

int inc(int* x) {
	asm(asm_beg

		" mov eax, [ebp+8] \n" // Copia para eax o valor do ponteiro x
		" inc dword ptr [eax] \n" // Incrementa a memória que eax aponta
		// tratando eax como um ponteiro para um inteiro de 32 bits (dword ptr)

	asm_end);
}

int troca(int* a, int* b) {
	asm(asm_beg

		// Coloca os endereços passados por parâmetro em esi e edi
		" mov esi, [ebp+8] \n"
		" mov edi, [ebp+12] \n"

		" mov eax, [esi] \n" // Copia o valor referenciado por 'a' para eax
		" mov ecx, [edi] \n" // Copia o valor referenciado por 'b' para ecx

		// Devolve os valores trocados para as referências
		" mov [esi], ecx \n"
		" mov [edi], eax \n"

	asm_end);
}

int main() {
	int i;
	for (i=1; i<=10; inc(&i)) {
		printf("Valor de i: %d\n", i);
	}
	printf("Insira dois valores ('a' e 'b'): ");
	int a, b;
	scanf("%d%d", &a, &b);
	troca(&a, &b);
	printf("a: %d\n", a);
	printf("b: %d\n", b);
}