// Jump condicionais

#include <stdio.h>
#include <stdlib.h>

#define asm_beg ".intel_syntax noprefix\n"
#define asm_end ".att_syntax   prefix  \n"

int negativo(int x) {
	asm(asm_beg

		" mov eax, 0 \n" // Deixa no eax (retorno) 0 (falso)
		" mov ecx, [ebp+8] \n" // Copia o valor do parâmetro para ecx
		" cmp ecx, 0 \n" // Compara ecx com 0
		" jge fim_1 \n" // JGE = (jump if greater or equal) se ecx for >= 0 pula para o fim
		
		" mov eax, 1 \n" // Se não pulou pro fim quer dizer que ecx não é >= 0, portanto é negativo
		// e o retorno deve ser 1 (verdadeiro)
		
		" fim_1: \n"

	asm_end);
}

// Testa se o bit mais baixo (mais à esquerda) é 1, ou seja, se é ímpar
int impar(int x) {
	asm(asm_beg

		" mov eax, 1 \n" // Considera o número "por padrão" ímpar
		" mov edx, [ebp+8] \n"
		" shr edx, 1 \n " // Desloca 1 bit para direita de edx, esse bit vai pra flag "carry"
		" jc fim_2 \n" // JC = (jump if carry == 1) Se o carry é 1 então o número é mesmo ímpar, pula pro fim

		" mov eax, 0 \n" // Se não pulou pro fim o número é par

		" fim_2: \n"

	asm_end);
}

int main() {
	int x;
	printf("Insira um valor inteiro: ");
	scanf("%d", &x);

	if (negativo(x)) {
		printf("Negativo\n");
	} else {
		printf("Nao negativo\n");
	}

	if (impar(x)) {
		printf("Impar\n");
	} else {
		printf("Par\n");
	}
}