#include <stdio.h>
#include <stdlib.h>

// foi utilizada IA para comentar o código

int main(){
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);

    // Determinar quadrante atual
    int quadrante_atual = 0;
    if (x > 0 && y > 0){
        quadrante_atual = 1;
    } else if (x < 0 && y > 0){
        quadrante_atual = 2;
    } else if (x < 0 && y < 0){
        quadrante_atual = 3;
    } else if (x > 0 && y < 0){
        quadrante_atual = 4;
    }

    // Determinar quadrante destino (diagonal)
    int destino = 0;
    if (quadrante_atual == 1){
        destino = 3;
    } else if (quadrante_atual == 2){
        destino = 4;
    } else if (quadrante_atual == 3){
        destino = 1;
    } else if (quadrante_atual == 4){
        destino = 2;
    }

    // Passos necessários em cada eixo
    int x_dest = 0;
    int y_dest = 0;
    if (destino == 1){
        x_dest = 1;
        y_dest = 1;
    } else if (destino == 2){
        x_dest = -1;
        y_dest = 1;
    } else if (destino == 3){
        x_dest = -1;
        y_dest = -1;
    } else if (destino == 4){
        x_dest = 1;
        y_dest = -1;
    }

    int px = abs(x - x_dest);
    int py = abs(y - y_dest);

    // Caminhada inválida: evitar o próprio quadrante ou o destino
    if (c == quadrante_atual || c == destino){
        puts("caminhada invalida");

    // Q1 → Q3, evitando Q2 (lado esquerdo): vai y primeiro (desce antes de ir pra esquerda)
    } else if (quadrante_atual == 1 && destino == 3 && c == 2){
        printf("%d passos em y e %d passos em x\n", py, px);

    // Q1 → Q3, evitando Q4 (lado direito): vai x primeiro (vai pra esquerda antes de descer)
    } else if (quadrante_atual == 1 && destino == 3 && c == 4){
        printf("%d passos em x e %d passos em y\n", px, py);

    // Q2 → Q4, evitando Q1 (lado direito em cima): vai y primeiro (desce antes de ir pra direita)
    } else if (quadrante_atual == 2 && destino == 4 && c == 1){
        printf("%d passos em y e %d passos em x\n", py, px);

    // Q2 → Q4, evitando Q3 (lado esquerdo embaixo): vai x primeiro (vai pra direita antes de descer)
    } else if (quadrante_atual == 2 && destino == 4 && c == 3){
        printf("%d passos em x e %d passos em y\n", px, py);

    // Q3 → Q1, evitando Q2 (lado esquerdo em cima): vai x primeiro (vai pra direita antes de subir)
    } else if (quadrante_atual == 3 && destino == 1 && c == 2){
        printf("%d passos em x e %d passos em y\n", px, py);

    // Q3 → Q1, evitando Q4 (lado direito embaixo): vai y primeiro (sobe antes de ir pra direita)
    } else if (quadrante_atual == 3 && destino == 1 && c == 4){
        printf("%d passos em y e %d passos em x\n", py, px);

    // Q4 → Q2, evitando Q1 (lado direito em cima): vai x primeiro (vai pra esquerda antes de subir)
    } else if (quadrante_atual == 4 && destino == 2 && c == 1){
        printf("%d passos em x e %d passos em y\n", px, py);

    // Q4 → Q2, evitando Q3 (lado esquerdo embaixo): vai y primeiro (sobe antes de ir pra esquerda)
    } else if (quadrante_atual == 4 && destino == 2 && c == 3){
        printf("%d passos em y e %d passos em x\n", py, px);

    } else {
        puts("caminhada invalida");
    }

    return 0;
}
