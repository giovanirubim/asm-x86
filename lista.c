#include <stdio.h>
#include <stdlib.h>

#define asm_ini asm(".intel_syntax noprefix\n"
#define asm_end ".att_syntax prefix");

int prod_vet(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"                                          \n"
	"       xor eax, eax                       \n"
	"       jecxz 2f                           \n"
	"       inc eax                            \n"
	"                                          \n"
	"    1: imul dword ptr [esi + ecx*4 - 4]   \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2:                                    \n"
	"                                          \n"
	asm_end
}

int tamanho_str(char s[]) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       xor eax, eax                       \n"
	"                                          \n"
	"    1: mov cl, [esi + eax]                \n"
	"       inc eax                            \n"
	"       or cl, cl                          \n"
	"       jnz 1b                             \n"
	"                                          \n"
	"       dec eax                            \n"
	"                                          \n"
	asm_end
}

int soma_vet_int32(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"                                          \n"
	"       xor eax, eax                       \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: add eax, [esi + ecx*4 - 4]         \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2:                                    \n"
	"                                          \n"
	asm_end
}

long long soma_vet_int64(long long v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"                                          \n"
	"       xor eax, eax                       \n"
	"       xor edx, edx                       \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: add eax, [esi + ecx*8 - 8]         \n"
	"       adc edx, [esi + ecx*8 - 4]         \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2:                                    \n"
	"                                          \n"
	asm_end
}

int soma_quad(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: mov eax, [esi + ecx*4 - 4]         \n"
	"       imul eax                           \n"
	"       add ebx, eax                       \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2: mov eax, ebx                       \n"
	"                                          \n"
	asm_end
}

int conta_par(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"       mov eax, ecx                       \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: mov edx, [esi + ecx*4 - 4]         \n"
	"       shr edx                            \n"
	"       adc ebx, 0                         \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2: sub eax, ebx                       \n"
	"                                          \n"
	asm_end
}

int conta_neg(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"       xor eax, eax                       \n"
	"                                          \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: mov edx, [esi + ecx*4 - 4]         \n"
	"       shl edx                            \n"
	"       adc eax, 0                         \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2:                                    \n"
	"                                          \n"
	asm_end
}

int* busca_end(int v[], int n, int x) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"       mov edx, [ebp + 16]                \n"
	"                                          \n"
	"       lea edi, [esi + ecx*4]             \n"
	"       xor eax, eax                       \n"
	"       jecxz 3f                           \n"
	"                                          \n"
	"    1: mov ebx, [esi]                     \n"
	"       add esi, 4                         \n"
	"       cmp ebx, edx                       \n"
	"       je 2f                              \n"
	"       cmp esi, edi                       \n"
	"       jne 1b                             \n"
	"       jmp 3f                             \n"
	"                                          \n"
	"    2: lea eax, [esi - 4]                 \n"
	"                                          \n"
	"    3:                                    \n"
	"                                          \n"
	asm_end
}

int* busca_end_maior(int v[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov ecx, [ebp + 12]                \n"
	"                                          \n"
	"       xor eax, eax                       \n"
	"       jecxz 3f                           \n"
	"                                          \n"
	"       lea eax, [esi + ecx*4 - 4]         \n"
	"       mov edi, [eax]                     \n"
	"       dec ecx                            \n"
	"       jecxz 3f                           \n"
	"                                          \n"
	"    1: mov edx, [esi + ecx*4 - 4]         \n"
	"       cmp edx, edi                       \n"
	"       jg 2f                              \n"
	"       loop 1b                            \n"
	"       jmp 3f                             \n"
	"                                          \n"
	"    2: lea eax, [esi + ecx*4 - 4]         \n"
	"       mov edi, edx                       \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    3:                                    \n"
	"                                          \n"
	asm_end
}

int soma_prod(int a[], int b[], int n) {
	asm_ini
	"                                          \n"
	"       mov esi, [ebp + 8]                 \n"
	"       mov edi, [ebp + 12]                \n"
	"       mov ecx, [ebp + 16]                \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       jecxz 2f                           \n"
	"                                          \n"
	"    1: mov eax, [esi + ecx*4 - 4]         \n"
	"       imul dword ptr [edi + ecx*4 - 4]   \n"
	"       add ebx, eax                       \n"
	"       loop 1b                            \n"
	"                                          \n"
	"    2: mov eax, ebx                       \n"
	"                                          \n"
	asm_end
}

int conta_uns(int x) {
	asm_ini
	"                                          \n"
	"       mov edx, [ebp + 8]                 \n"
	"       xor eax, eax                       \n"
	"       jmp 2f                             \n"
	"                                          \n"
	"    1: inc eax                            \n"
	"       inc cl                             \n"
	"       shr edx, cl                        \n"
	"                                          \n"
	"    2: bsf ecx, edx                       \n"
	"       jnz 1b                             \n"
	"                                          \n"
	asm_end
}

int conta_dig(int x) {
	asm_ini
	"                                          \n"
	"       mov eax, [ebp + 8]                 \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       or eax, eax                        \n"
	"       jz 2f                              \n"
	"                                          \n"
	"       mov edi, 10                        \n"
	"    1: cdq                                \n"
	"       idiv edi                           \n"
	"       inc ebx                            \n"
	"       or eax, eax                        \n"
	"       jnz 1b                             \n"
	"                                          \n"
	"    2: mov eax, ebx                       \n"
	"                                          \n"
	asm_end
}

int soma_dig(int x) {
	asm_ini
	"                                          \n"
	"       mov eax, [ebp + 8]                 \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       or eax, eax                        \n"
	"       jz 2f                              \n"
	"                                          \n"
	"       mov edi, 10                        \n"
	"    1: cdq                                \n"
	"       idiv edi                           \n"
	"       add ebx, edx                       \n"
	"       or eax, eax                        \n"
	"       jnz 1b                             \n"
	"                                          \n"
	"    2: mov eax, ebx                       \n"
	"                                          \n"
	asm_end
}

int soma_dig_quad(int x) {
	asm_ini
	"                                          \n"
	"       mov eax, [ebp + 8]                 \n"
	"                                          \n"
	"       xor ebx, ebx                       \n"
	"       or eax, eax                        \n"
	"       jz 2f                              \n"
	"                                          \n"
	"       mov edi, 10                        \n"
	"    1: cdq                                \n"
	"       idiv edi                           \n"
	"       mov ecx, eax                       \n"
	"       mov eax, edx                       \n"
	"       imul eax                           \n"
	"       add ebx, eax                       \n"
	"       mov eax, ecx                       \n"
	"       or eax, eax                        \n"
	"       jnz 1b                             \n"
	"                                          \n"
	"    2: mov eax, ebx                       \n"
	"                                          \n"
	asm_end
}

char* copia_str(char dst[], char src[]) {
	asm_ini
	"                                          \n"
	"       mov edi, [ebp + 8]                 \n"
	"       mov esi, [ebp + 12]                \n"
	"       mov eax, edi                       \n"
	"       xor ecx, ecx                       \n"
	"                                          \n"
	"    1: mov bl, [esi + ecx]                \n"
	"       mov [edi + ecx], bl                \n"
	"       inc ecx                            \n"
	"       or bl, bl                          \n"
	"       jnz 1b                             \n"
	"                                          \n"
	asm_end
}

int palindromo(char const str[]) {
	asm_ini
	"                                          \n"
	"       mov edi, [ebp + 8]                 \n"
	"       mov esi, edi                       \n"
	"       mov eax, 1                         \n"
	"                                          \n"
	"    1: inc edi                            \n"
	"       cmp byte ptr [edi - 1], 0          \n"
	"       jne 1b                             \n"
	"                                          \n"
	"       sub edi, 2                         \n"
	"       jmp 1f                             \n"
	"                                          \n"
	"    2: inc esi                            \n"
	"       dec edi                            \n"
	"                                          \n"
	"    1: cmp esi, edi                       \n"
	"       jae 3f                             \n"
	"       mov cl, [esi]                      \n"
	"       cmp cl, [edi]                      \n"
	"       je 2b                              \n"
	"       dec eax                            \n"
	"                                          \n"
	"    3:                                    \n"
	"                                          \n"
	asm_end
}

int main() {
	printf("%d\n", palindromo("abbaxabba"));
}