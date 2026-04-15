#include <stdio.h>
#include <stdlib.h>
// comentado com IA
/* ── Protótipos ── */
double calcular_media(double *notas, int total);
void   encontrar_maior(double *notas, int total, double *maior, int *aluno);
void   encontrar_menor(double *notas, int total, double *menor, int *aluno);
int    contar_acima_media(double *notas, int total, double media);
double calcular_mediana(double *notas, int total);
void   calcular_moda(double *notas, int total);
void   imprimir_relatorio(double *notas, int total);
int    comparar_doubles(const void *a, const void *b);

/* ─────────────────────────────────────────────
   Comparador para qsort (exigido pela função)
   Retorna negativo, zero ou positivo
───────────────────────────────────────────── */
int comparar_doubles(const void *a, const void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    if (da < db) return -1;
    if (da > db) return  1;
    return 0;
}

/* ─────────────────────────────────────────────
   MÉDIA: soma todos e divide pelo total
───────────────────────────────────────────── */
double calcular_media(double *notas, int total) {
    double soma = 0;
    for (int i = 0; i < total; i++)
        soma += notas[i];
    return soma / total;
}

/* ─────────────────────────────────────────────
   MAIOR NOTA: percorre o vetor, atualiza só
   se estritamente maior (primeiro encontrado
   vence em caso de empate)
───────────────────────────────────────────── */
void encontrar_maior(double *notas, int total, double *maior, int *aluno) {
    *maior = notas[0];
    *aluno = 1;
    for (int i = 1; i < total; i++) {
        if (notas[i] > *maior) {
            *maior = notas[i];
            *aluno = i + 1;   /* alunos começam em 1 */
        }
    }
}

/* ─────────────────────────────────────────────
   MENOR NOTA: mesma lógica, mas busca o menor
───────────────────────────────────────────── */
void encontrar_menor(double *notas, int total, double *menor, int *aluno) {
    *menor = notas[0];
    *aluno = 1;
    for (int i = 1; i < total; i++) {
        if (notas[i] < *menor) {
            *menor = notas[i];
            *aluno = i + 1;
        }
    }
}

/* ─────────────────────────────────────────────
   ACIMA DA MÉDIA: conta quantos são > média
───────────────────────────────────────────── */
int contar_acima_media(double *notas, int total, double media) {
    int contador = 0;
    for (int i = 0; i < total; i++)
        if (notas[i] > media)
            contador++;
    return contador;
}

/* ─────────────────────────────────────────────
   MEDIANA:
   - Copia o vetor (não queremos alterar a ordem
     original, pois os alunos têm posição fixa)
   - Ordena a cópia com qsort
   - Se ímpar: elemento do meio
   - Se par:   média dos dois do meio
───────────────────────────────────────────── */
double calcular_mediana(double *notas, int total) {
    /* Ponteiro temporário para a cópia ordenada */
    double *copia = (double *)malloc(total * sizeof(double));
    if (!copia) {
        fprintf(stderr, "Erro ao alocar cópia para mediana\n");
        exit(1);
    }

    for (int i = 0; i < total; i++)
        copia[i] = notas[i];

    /* qsort usa o comparador que definimos acima */
    qsort(copia, total, sizeof(double), comparar_doubles);

    double mediana;
    if (total % 2 == 1)
        mediana = copia[total / 2];
    else
        mediana = (copia[total / 2 - 1] + copia[total / 2]) / 2.0;

    free(copia);
    return mediana;
}

/* ─────────────────────────────────────────────
   MODA:
   Para cada valor único, conta sua frequência.
   Rastreamos quantos valores distintos atingem
   a frequência máxima (num_modas).
   - num_modas > 1 → não há moda única
   - max_freq == 1 → todos aparecem uma vez,
                     também não há moda única
───────────────────────────────────────────── */
void calcular_moda(double *notas, int total) {
    int    max_freq  = 0;
    int    num_modas = 0;
    double moda      = 0;

    for (int i = 0; i < total; i++) {

        /* Pula valores que já foram processados antes */
        int ja_processado = 0;
        for (int j = 0; j < i; j++) {
            if (notas[i] == notas[j]) {
                ja_processado = 1;
                break;
            }
        }
        if (ja_processado) continue;

        /* Conta quantas vezes notas[i] aparece */
        int frequencia = 0;
        for (int j = 0; j < total; j++)
            if (notas[j] == notas[i])
                frequencia++;

        if (frequencia > max_freq) {
            max_freq  = frequencia;
            moda      = notas[i];
            num_modas = 1;          /* novo máximo, reinicia a contagem */
        } else if (frequencia == max_freq) {
            num_modas++;            /* empate: mais um candidato */
        }
    }

    if (max_freq <= 1 || num_modas > 1)
        printf("Moda: Nao ha moda unica\n");
    else
        printf("Moda: %.2f\n", moda);
}

/* ─────────────────────────────────────────────
   RELATÓRIO: chama todas as funções e imprime
───────────────────────────────────────────── */
void imprimir_relatorio(double *notas, int total) {
    double media = calcular_media(notas, total);

    double maior_nota, menor_nota;
    int    aluno_maior, aluno_menor;
    encontrar_maior(notas, total, &maior_nota, &aluno_maior);
    encontrar_menor(notas, total, &menor_nota, &aluno_menor);

    int    acima   = contar_acima_media(notas, total, media);
    double mediana = calcular_mediana(notas, total);

    printf("Media: %.2f\n",              media);
    printf("Maior nota: %.2f (aluno %d)\n", maior_nota, aluno_maior);
    printf("Menor nota: %.2f (aluno %d)\n", menor_nota, aluno_menor);
    printf("Acima da media: %d\n",       acima);
    printf("Mediana: %.2f\n",            mediana);
    calcular_moda(notas, total);
}

/* ─────────────────────────────────────────────
   MAIN
───────────────────────────────────────────── */
int main() {
    /* ── Leitura inicial ── */
    int n;
    scanf("%d", &n);

    double *notas = (double *)malloc(n * sizeof(double));
    if (!notas) {
        fprintf(stderr, "Erro ao alocar notas iniciais\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        scanf("%lf", &notas[i]);

    /* ── Relatório inicial ── */
    printf("Relatorio inicial\n");
    imprimir_relatorio(notas, n);

    /* ── Novas notas com realloc ── */
    int k;
    scanf("%d", &k);

    if (k > 0) {
        /* Ponteiro temporário: seguro contra falha de realloc */
        double *temp = (double *)realloc(notas, (n + k) * sizeof(double));
        if (!temp) {
            fprintf(stderr, "Erro ao realocar para novas notas\n");
            free(notas);
            return 1;
        }
        notas = temp;   /* só atualiza se realloc teve sucesso */

        for (int i = 0; i < k; i++)
            scanf("%lf", &notas[n + i]);

        n += k;
    }

    /* ── Relatório atualizado ── */
    printf("\nRelatorio atualizado\n");
    imprimir_relatorio(notas, n);

    free(notas);
    return 0;
}
