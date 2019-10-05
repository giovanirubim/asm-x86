// Repetição

#include <stdio.h>
#include <stdlib.h>

#define asm_beg ".intel_syntax noprefix\n"
#define asm_end ".att_syntax   prefix  \n"

int conta_1(int x) {
	asm(asm_beg

		" xor eax, eax \n" // Zera eax
		" mov edx, [ebp+8] \n" // Copia x para edx

		" start_1: \n"
			" shr edx \n" // Desloca o edx 1 bit para a direita (esse bit vai para o carry)
			" adc eax, 0 \n" // Faz eax += 0 + carry, ou seja, soma o carry em eax
			" cmp edx, 0 \n" // Compara edx com 0
		" jne start_1 \n" // JNE = jump if not equal (pula se não for igual) = volta para start se edx não for == 0

	asm_end);
}

int isPrimo(int x) {
	asm(asm_beg

		// Deixa uma cópia de x em ecx e uma em esi
		" mov ecx, [ebp+8] \n"
		" mov esi, ecx \n"

		" xor edi, edi \n" // Zera edi, edi vai contar quantos divizores x tem

		" start_2: \n"

			// Se esi for zero sai do loop
			" cmp esi, 0 \n"
			" je fim_loop \n"
			
			" mov eax, ecx \n" // Copia ecx (que tem o valor x) para eax para poder dividir por esi
			" xor edx, edx \n" // div faz a divizão de edx:eax por um reg32, deve-se zerar edx pois é a parte alta da divizão
			" div esi \n" // divide eax por esi, o resultado da visião fica em eax, o mod da divisão fica em edx
			
			// Se sobrar zero, então x é múltiplo de esi
			" cmp edx, 0 \n"
			" jne nao_conta \n" 
			" inc edi \n" // Se o mod deu zero, conta mais um divizor em edi
			" nao_conta: \n"

			" dec esi \n"

		" jmp start_2 \n"

		" fim_loop: \n"

		" xor eax, eax \n"
		" cmp edi, 2 \n" // Vê se o total de divizores é 2
		" jne fim \n" // Se não for 2 pula para o fim retornando 0 (que está no eax)

		" inc eax \n" // Se possui 2 divizores retorna 1
		" fim: \n"

	asm_end);
}

int main() {
	int x;
	printf("Insira um valor inteiro: ");
	scanf("%d", &x);
	printf("Tem %d bits 1\n", conta_1(x));
	if (isPrimo(x)) {
		printf("Primo\n");
	} else {
		printf("Nao primo\n");
	}
}