#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    int quadrante1 = 0;
    if (c == 1){
        quadrante1 = 1
    }
    int quadrante2 = 0;
    if (c == 2){
        quadrante2 = 1
    }
    int quadrante3 = 0;
    if (c == 3){
        quadrante3 = 1
    }
    int quadrante4 = 0;
    if (c == 1){
        quadrante1 = 1
    }
    int quadrante_atual;
    if(x > 0 && y > 0){
        quadrante_atual = 1
    } else if(x < 0 && y > 0){
        quadrante_atual = 2
    } else if(x < 0 && y < 0){
        quadrante_atual = 3
    } else if(x > 0 && y < 0){
        quadrante_atual = 4
    }


int x_caminhado, y_caminhado;

// quadrante 1 negado
    if (quadrante1 == 1){
        puts("caminhada invalida");

//quadrante2 negado
    } else if (quadrante2 == 1){
        if (x < 0 && y > 0){
            puts("caminhada invalida");
        }else{
                x_caminhado = abs(x) - 1;
                y_caminhado = abs(y) - 1;
                if (quadrante_atual == 3){
                    printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                } else if(quadrante_atual == 4){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
                } else if (quadrante_atual == 1){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
                }
                
        }

// quadrante3 negado

    } else if (quadrante3 == 1){
        if (x < 0 && y < 0){
        puts("caminhada invalida");
        } else{
            x_caminhado = abs(x) - 1;
            y_caminhado = abs(y) - 1;
            if (quadrante_atual == 2){
                    if(x_caminhado > y_caminhado){
                        if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                        } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                        }
                } else if(quadrante_atual == 4){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
                    }
                } else if (quadrante_atual == 1){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
        }
    }
//quadrante 4 negado
    } else if (quadrante4 == 1){
        if (x < 0 && y > 0){
            puts("caminhada invalida");
        } else{
            x_caminhado = abs(x) - 1;
            y_caminhado = abs(y) - 1;
            if (quadrante_atual == 3){
                    printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                } else if(quadrante_atual == 2){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
                } else if (quadrante_atual == 1){
                    if(x_caminhado > y_caminhado){
                        printf("%d passos em x e %d passos em y", x_caminhado, y_caminhado);
                    } else{
                        printf("%d passos em y e %d passos em x", y_caminhado, x_caminhado);
                    }
                }
        }

    }
}
