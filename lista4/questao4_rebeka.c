#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na fila do BFS
typedef struct {
    int r;    // linha (row)
    int c;    // coluna (col)
    int dist; // distância percorrida até aqui
} Node;

int main() {
    int linhas, colunas;
    
    // Lê as dimensões no formato específico "linhasxcolunas" (ex: 3x4)
    if (scanf("%dx%d", &linhas, &colunas) != 2) return 0;

    // Aloca dinamicamente o mapa e a matriz de células visitadas
    char **mapa = (char **)malloc(linhas * sizeof(char *));
    int **visitado = (int **)malloc(linhas * sizeof(int *));
    
    int start_r = -1, start_c = -1;

    // Leitura do mapa e localização da origem 'o'
    for (int i = 0; i < linhas; i++) {
        mapa[i] = (char *)malloc((colunas + 1) * sizeof(char));
        visitado[i] = (int *)calloc(colunas, sizeof(int)); // calloc já zera tudo
        scanf("%s", mapa[i]);
        
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 'o') {
                start_r = i;
                start_c = j;
            }
        }
    }

    // Criação da fila para o BFS 
    // O tamanho máximo possível é o número total de células (linhas * colunas)
    Node *fila = (Node *)malloc(linhas * colunas * sizeof(Node));
    int inicio_fila = 0, fim_fila = 0;

    // Adiciona a posição inicial na fila com distância 0
    fila[fim_fila++] = (Node){start_r, start_c, 0};
    visitado[start_r][start_c] = 1;

    // Vetores de direção: Cima, Baixo, Esquerda, Direita
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int distancia_minima = -1;

    // Loop principal do algoritmo BFS
    while (inicio_fila < fim_fila) {
        Node atual = fila[inicio_fila++]; // Remove o primeiro elemento da fila

        // Verifica se chegamos ao destino
        if (mapa[atual.r][atual.c] == 'd') {
            distancia_minima = atual.dist;
            break; // Como é BFS, o primeiro caminho encontrado até o destino é o menor
        }

        // Explora os 4 vizinhos (cima, baixo, esquerda, direita)
        for (int i = 0; i < 4; i++) {
            int nr = atual.r + dr[i];
            int nc = atual.c + dc[i];

            // Condições para andar: 
            // 1. Estar dentro dos limites da matriz
            // 2. Não ser uma parede ('#')
            // 3. Ainda não ter sido visitado
            if (nr >= 0 && nr < linhas && nc >= 0 && nc < colunas && 
                mapa[nr][nc] != '#' && !visitado[nr][nc]) {
                
                visitado[nr][nc] = 1; // Marca como visitado para não andar em círculos
                fila[fim_fila++] = (Node){nr, nc, atual.dist + 1}; // Adiciona na fila
            }
        }
    }

    // Verifica o resultado e imprime no formato exato solicitado
    if (distancia_minima != -1) {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", distancia_minima);
    } else {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }

    return 0;
}
