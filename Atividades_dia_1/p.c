#include <stdio.h>

// Função para calcular a soma dos dígitos
int calcular_soma_dos_digitos(int numero) {
    int soma_total = 0;
    while (numero > 0) {
        soma_total += numero % 10;
        numero /= 10;
    }
    return soma_total;
}

int main() {
    int tamanho_matriz;
    scanf("%d", &tamanho_matriz);

    int matriz_codigos[20][20];
    
    // Leitura da matriz
    for (int linha = 0; linha < tamanho_matriz; linha++) {
        for (int coluna = 0; coluna < tamanho_matriz; coluna++) {
            scanf("%d", &matriz_codigos[linha][coluna]);
        }
    }

    // vetores para a espiral
    int valores_espiral[400];
    int linhas_espiral[400];
    int colunas_espiral[400];
    int elementos_visitados = 0;

    // Fronteiras
    int limite_superior = 0;
    int limite_inferior = tamanho_matriz - 1;
    int limite_esquerdo = 0;
    int limite_direito = tamanho_matriz - 1;

    //percurso espiral
    while (limite_superior <= limite_inferior && limite_esquerdo <= limite_direito) {
        
        // Percorrendo a borda superior (da esquerda para a direita)
        for (int coluna = limite_esquerdo; coluna <= limite_direito; coluna++) {
            linhas_espiral[elementos_visitados] = limite_superior;
            colunas_espiral[elementos_visitados] = coluna;
            valores_espiral[elementos_visitados] = matriz_codigos[limite_superior][coluna];
            elementos_visitados++;
        }
        limite_superior++;

        // Percorrendo a borda direita (de cima para baixo)
        for (int linha = limite_superior; linha <= limite_inferior; linha++) {
            linhas_espiral[elementos_visitados] = linha;
            colunas_espiral[elementos_visitados] = limite_direito;
            valores_espiral[elementos_visitados] = matriz_codigos[linha][limite_direito];
            elementos_visitados++;
        }
        limite_direito--;

        // Percorrendo a borda de baixo(da direita para a esquerda)
        if (limite_superior <= limite_inferior) {
            for (int coluna = limite_direito; coluna >= limite_esquerdo; coluna--) {
                linhas_espiral[elementos_visitados] = limite_inferior;
                colunas_espiral[elementos_visitados] = coluna;
                valores_espiral[elementos_visitados] = matriz_codigos[limite_inferior][coluna];
                elementos_visitados++;
            }
            limite_inferior--;
        }

        // Percorrendo a borda esquerda (de baixo para cima)
        if (limite_esquerdo <= limite_direito) {
            for (int linha = limite_inferior; linha >= limite_superior; linha--) {
                linhas_espiral[elementos_visitados] = linha;
                colunas_espiral[elementos_visitados] = limite_esquerdo;
                valores_espiral[elementos_visitados] = matriz_codigos[linha][limite_esquerdo];
                elementos_visitados++;
            }
            limite_esquerdo++;
        }
    }

    // Variáveis para rastrear a maior sequência válida
    int tamanho_maior_sequencia = 0;
    int indice_inicio_maior = 0;

    // Variáveis para rastrear a sequência atual
    int tamanho_sequencia_atual = 1;
    int indice_inicio_atual = 0;

    for (int i = 1; i < elementos_visitados; i++) {
        int numero_anterior = valores_espiral[i - 1];
        int numero_atual = valores_espiral[i];

        int soma_anterior = calcular_soma_dos_digitos(numero_anterior);
        int soma_atual = calcular_soma_dos_digitos(numero_atual);

        // mesma soma de dígitos E o anterior ser estritamente maior
        if ((soma_anterior == soma_atual) && (numero_anterior > numero_atual)) {
            tamanho_sequencia_atual++;
        } else {
            // A sequência quebrou, vamos verificar se a atual é a maior até agora
            if (tamanho_sequencia_atual > tamanho_maior_sequencia) {
                tamanho_maior_sequencia = tamanho_sequencia_atual;
                indice_inicio_maior = indice_inicio_atual;
            }
            // Reinicia a contagem a partir do elemento atual
            tamanho_sequencia_atual = 1;
            indice_inicio_atual = i;
        }
    }
    
    // Verificação extra caso a maior sequência vá até o último elemento da espiral
    if (tamanho_sequencia_atual > tamanho_maior_sequencia) {
        tamanho_maior_sequencia = tamanho_sequencia_atual;
        indice_inicio_maior = indice_inicio_atual;
    }

    if (tamanho_maior_sequencia >= 2) {
        printf("%d\n", tamanho_maior_sequencia);
        for (int k = 0; k < tamanho_maior_sequencia; k++) {
            printf("(%d,%d)\n", linhas_espiral[indice_inicio_maior + k], colunas_espiral[indice_inicio_maior + k]);
        }
    } else {
        printf("0\n");
    }

    return 0;
}
