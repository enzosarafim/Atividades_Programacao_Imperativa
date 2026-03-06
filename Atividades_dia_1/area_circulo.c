#include <stdio.h>

int main(){
    double raio;
    double area;
    scanf("%lf", &raio);
    double raioquadrado;
    raioquadrado = raio * raio;
    area = 3.14159 * raioquadrado;
    printf("A=%.4lf\n", area);

    return 0;
}
