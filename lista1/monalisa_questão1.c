#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//O código ainda está incompleto
int main(){
    //calculo amor
    int dia1, mes1, ano1, dia2, mes2, ano2, soma_total;
    scanf("%d/%d/%d %d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
    soma_total= dia1+ mes1+ ano1+ dia2+ mes2+ ano2;
    int prob_amor;
    prob_amor = (soma_total*7)%101;
    if(prob_amor<20){
        printf("Amor: %d%% ",prob_amor);
        puts("Pessimo dia para se apaixonar.");
    } else if(prob_amor>=20 && prob_amor<=40){
        printf("Amor: %d%% ",prob_amor);
        puts("Melhor manter o coracao <3 longe de perigo.");
    } else if(prob_amor>=41 && prob_amor<=69){
        printf("Amor: %d%% ",prob_amor);
        puts("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    } else if(prob_amor>=70 && prob_amor<=80){
        printf("Amor: %d%% ",prob_amor);
        puts("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    } else{
        printf("Amor: %d%% ",prob_amor);
        puts("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");
    }
    //calculo sorte
    //foi utilizada a função abs() para conseguir o valor absoluto da subtração
    int soma_dias_meses;
    int diferenca_positiva_anos;
    soma_dias_meses= dia1+ mes1+ dia2+ mes2;
    diferenca_positiva_anos= abs(ano1 - ano2);
    int prob_sorte;
    prob_sorte= ((soma_dias_meses*9) + diferenca_positiva_anos)%101;
    if(prob_sorte < 30){
        printf("Sorte: %d%% ", prob_sorte);
        puts("Nem jogue moedas pra cima hoje.");
    } else if(prob_sorte >= 30 && prob_sorte <=50){
        printf("Sorte: %d%% ", prob_sorte);
        puts("Melhor nao arriscar.");
    } else if(prob_sorte >= 51 && prob_sorte <=79){
        printf("Sorte: %d%% ", prob_sorte);
        puts("Por sua conta em risco.");
    } else if(prob_sorte >= 80 && prob_sorte <=90){
        printf("Sorte: %d%% ", prob_sorte);
        puts("Hoje vale a pena arriscar.");
    } else{
        printf("Sorte: %d%% ", prob_sorte);
        printf("Nao tenha medo de virar cartas hoje.");
        puts(" Sem tigrinho nem jogos de azar, por favor!");
    }
    //calculo Trabalho
    return 0;
}
