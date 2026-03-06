#include <stdio.h>

int main(){
    double raio;
    double area;
    scanf("%lf", &raio);
    double raiocubo;
    raiocubo = raio * raio * raio;
    area = 3.14159 * raiocubo * (4.0/3);
    printf("VOLUME = %.3lf\n", area);

    return 0;
}
