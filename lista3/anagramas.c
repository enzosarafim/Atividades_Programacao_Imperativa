#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARACTERES  101
#define MAX_PALAVRAS     50
#define MAX_TAM_PALAVRA 101

int main() {
    char entrada[MAX_CARACTERES];
    fgets(entrada, MAX_CARACTERES, stdin);

    // Buffer linear com palavras originais
    char palavras_orig[MAX_TAM_PALAVRA * MAX_PALAVRAS];

    // Buffer linear com palavras em minúsculo
    char palavras_min[MAX_TAM_PALAVRA * MAX_PALAVRAS];

    int posicao_inicio[MAX_PALAVRAS];
    int total_palavras = 0;
    int posicao_atual = 0;

    // Extrai as palavras da entrada
    int caractere_atual = 0;
    while (entrada[caractere_atual] != '\0' && entrada[caractere_atual] != '\n') {
        if (!isalpha((unsigned char)entrada[caractere_atual])) {
            caractere_atual++;
            continue;
        }

        posicao_inicio[total_palavras] = posicao_atual;

        while (isalpha((unsigned char)entrada[caractere_atual])) {
            palavras_orig[posicao_atual] = entrada[caractere_atual];
            palavras_min[posicao_atual] = tolower((unsigned char)entrada[caractere_atual]);

            posicao_atual++;
            caractere_atual++;
        }

        palavras_orig[posicao_atual] = '\0';
        palavras_min[posicao_atual] = '\0';
        posicao_atual++;

        total_palavras++;
    }

    int indice_par_esquerdo[MAX_PALAVRAS * MAX_PALAVRAS];
    int indice_par_direito[MAX_PALAVRAS * MAX_PALAVRAS];
    int total_pares = 0;

    for (int palavra_a = 0; palavra_a < total_palavras; palavra_a++) {
        for (int palavra_b = palavra_a + 1; palavra_b < total_palavras; palavra_b++) {
            char *p1 = &palavras_min[posicao_inicio[palavra_a]];
            char *p2 = &palavras_min[posicao_inicio[palavra_b]];

            if (strlen(p1) != strlen(p2))
                continue;

            int frequencia_letras[26] = {0};

            for (int letra = 0; p1[letra] != '\0'; letra++)
                frequencia_letras[p1[letra] - 'a']++;

            for (int letra = 0; p2[letra] != '\0'; letra++)
                frequencia_letras[p2[letra] - 'a']--;

            int eh_anagrama = 1;
            for (int letra = 0; letra < 26; letra++) {
                if (frequencia_letras[letra] != 0) {
                    eh_anagrama = 0;
                    break;
                }
            }

            if (eh_anagrama) {
                indice_par_esquerdo[total_pares] = palavra_a;
                indice_par_direito[total_pares] = palavra_b;
                total_pares++;
            }
        }
    }

    if (total_pares == 0) {
        printf("Nao existem anagramas na frase.\n");
    } else {
        printf("Pares de anagramas encontrados:\n");
        for (int par = 0; par < total_pares; par++) {
            printf("%s e %s\n",
                   &palavras_orig[posicao_inicio[indice_par_esquerdo[par]]],
                   &palavras_orig[posicao_inicio[indice_par_direito[par]]]);
        }
        printf("\nTotal de pares: %d\n", total_pares);
    }

    return 0;
}
