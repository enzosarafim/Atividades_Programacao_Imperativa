#include <stdio.h>
#include <math.h>

int main(){
    //calculo amor
    int dia1, mes1, ano1, dia2, mes2, ano2, soma_amor;
    scanf("%d/%d/%d %d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
    soma_amor= dia1+ mes1+ ano1+ dia2+ mes2+ ano2;
    int prob_amor;
    prob_amor = (soma_amor*7)%101;
    if(prob_amor<20){
        puts("Pessimo dia para se apaixonar.");
    } else if(prob_amor>=20 && prob_amor<=40){
        puts("Melhor manter o coracao <3 longe de perigo.");
    } else if(prob_amor>=41 && prob_amor<=69){
        puts("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    } else if(prob_amor>=70 && prob_amor<=80){
        puts("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    } else{
        puts("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");
    }
    printf("Amor: %d",prob_amor);
    //calculo sorte



    return 0;
}
