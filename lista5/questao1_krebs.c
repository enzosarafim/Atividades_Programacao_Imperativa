#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_strings;
    scanf("%d", &num_strings);
    
    char **strings = (char **)malloc(num_strings * sizeof(char *));
    if (!strings) {
        fprintf(stderr, "Erro ao alocar vetor de strings\n");
        return 1;
    }

    int *comprimentos = (int *)malloc(num_strings * sizeof(int));
    if (!comprimentos) {
        fprintf(stderr, "Erro ao alocar vetor de comprimentos\n");
        free(strings);
        return 1;
    }

    
    int comprimento_total = 0;
    int comprimento_maximo = 0;

    for (int i = 0; i < num_strings; i++) {
        char buffer[100000];
        scanf("%s", buffer);

        int tamanho = strlen(buffer);
        comprimentos[i] = tamanho;
        comprimento_total += tamanho;

        if (tamanho > comprimento_maximo)
            comprimento_maximo = tamanho;

        
        char *temp = (char *)malloc((tamanho + 1) * sizeof(char));
        if (!temp) {
            fprintf(stderr, "Erro ao alocar string %d\n", i);
            for (int j = 0; j < i; j++) free(strings[j]);
            free(strings);
            free(comprimentos);
            return 1;
        }
        strings[i] = temp;
        strcpy(strings[i], buffer);
    }
    
    char *string_mesclada = (char *)malloc((comprimento_total + 1) * sizeof(char));
    if (!string_mesclada) {
        fprintf(stderr, "Erro ao alocar string mesclada\n");
        for (int i = 0; i < num_strings; i++) free(strings[i]);
        free(strings);
        free(comprimentos);
        return 1;
    }

    int posicao_escrita = 0;
    for (int coluna = 0; coluna < comprimento_maximo; coluna++) {
        for (int linha = 0; linha < num_strings; linha++) {
            /* Só adiciona se a string ainda tem caractere nesta posição */
            if (coluna < comprimentos[linha]) {
                string_mesclada[posicao_escrita++] = strings[linha][coluna];
            }
        }
    }
    string_mesclada[posicao_escrita] = '\0';

    printf("%s\n", string_mesclada);

    int tamanho_fundido = comprimento_total;

  
    char *string_fundida = (char *)malloc((comprimento_total + 1) * sizeof(char));
    if (!string_fundida) {
        fprintf(stderr, "Erro ao alocar string fundida\n");
        free(string_mesclada);
        for (int i = 0; i < num_strings; i++) free(strings[i]);
        free(strings);
        free(comprimentos);
        return 1;
    }
    strcpy(string_fundida, string_mesclada);

    int i = 0;
    while (i < tamanho_fundido - 1) {
        if (string_fundida[i] == string_fundida[i + 1]) {
            string_fundida[i] = (string_fundida[i] == 'z') ? 'a' : string_fundida[i] + 1;

            
            memmove(&string_fundida[i + 1],
                    &string_fundida[i + 2],
                    tamanho_fundido - i - 1);
            tamanho_fundido--;
            string_fundida[tamanho_fundido] = '\0';

            
            if (i > 0)
                i--;
        } else {
            i++;
        }
    }

    printf("%s\n", string_fundida);

   
    return 0;
}
