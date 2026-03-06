#include <stdio.h>
#include <math.h>

int main(){

    double xp1;
    double yp1;
    double xp2;
    double yp2;
    double calculo;

    scanf("%lf %lf", &xp1, &yp1);
    scanf("%lf %lf", xp2, yp2);

    calculo = sqrt(pow(xp2 - xp1, 2.0) + pow(yp2 - yp1, 2.0));
    printf("%.4lf\n", calculo);

    return 0;
}
