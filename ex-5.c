// Operações com vetores

#include <stdio.h>
#include <stdlib.h>

#define asm_beg ".intel_syntax noprefix\n"
#define asm_end ".att_syntax   prefix  \n"

int soma(int* v, int n) {
	asm(asm_beg

		" mov esi, [ebp+8] \n" // esi fica para percorrer o vetor
		" mov ecx, [ebp+12] \n" // ecx fica como contador

		" xor eax, eax \n" // Zera eax para armazenar a soma

		" jecxz fim \n" // Pula para o fim se ecx for zero (jump if ecx == 0)
		" start: \n"

			" add eax, [esi] \n" // Soma em eax o inteiro apontado por esi
			" add esi, 4 \n" // Avança para o próximo inteiro (4 bytes)
			" dec ecx \n" // Diminui 1 no contador

			" jecxz fim \n" // Se o contador zerou sai do loop

		" jmp start \n" // Continua o loop

		" fim: \n"

	asm_end);
}

int prod(int* v, int n) {
	asm(asm_beg

		" mov esi, [ebp+8] \n" // usa esi como ponteiro para o vetor
		" mov ecx, [ebp+12] \n" // usa ecx como contador que começa em n

		" xor eax, eax \n" // Zera eax
		" jecxz fim_2 \n" // Se o vetor estiver vazio o retorno é 0

		" inc eax \n" // Inicia eax em 1 para multiplicar os elementos do vetor

		" start_2: \n"
			" dec ecx \n " // Diminui ecx (loop que vai do final pro começo do vetor)
			" mul dword ptr [esi + ecx*4] \n" // eax *= v[ecx]
			" or ecx, ecx \n" // Faz or em vez de "cmp 0" para verificar se ecx é diferente de zero
		" jnz start_2 \n" // jnz = jump if not zero -> se ecx não for zero, continua o loop

		" fim_2: \n"

	asm_end);
}

int main() {
	int v[100];
	int n;
	printf("Numero de elementos: ");
	scanf("%d", &n);
	int i;
	for (i=0; i<n; ++i) {
		printf("Valor de v[%d]: ", i);
		scanf("%d", &v[i]);
	}
	printf("Somatorio: %d\n", soma(v, n));
	printf("Produto: %d\n", prod(v, n));
}