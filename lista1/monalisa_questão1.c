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
    //foi utilizada a função abs() para conseguir o valor absoluto da subtração, para isso, foi incluida a biblioteca <stdlib.h>
    int soma_dias_meses;
    int diferenca_positiva_anos;
    soma_dias_meses= dia1+ mes1+ dia2+ mes2;
    diferenca_positiva_anos= abs(ano1 - ano2);
    int prob_sorte;
    prob_sorte= ((soma_dias_meses*9) + diferenca_positiva_anos)%101;
    if(prob_sorte < 30){
        printf("Sorte: %d%% ", prob_sorte);
        printf("Nem jogue moedas pra cima hoje.");
    } else if(prob_sorte >= 30 && prob_sorte <=50){
        printf("Sorte: %d%% ", prob_sorte);
        printf("Melhor nao arriscar.");
    } else if(prob_sorte >= 51 && prob_sorte <=79){
        printf("Sorte: %d%% ", prob_sorte);
        printf("Por sua conta em risco.");
    } else if(prob_sorte >= 80 && prob_sorte <=90){
        printf("Sorte: %d%% ", prob_sorte);
        printf("Hoje vale a pena arriscar.");
    } else{
        printf("Sorte: %d%% ", prob_sorte);
        printf("Nao tenha medo de virar cartas hoje.");
    }
    puts(" Sem tigrinho nem jogos de azar, por favor!");

    //calculo Trabalho
    int soma_anos;
    int prob_trabalho;
    soma_anos = ano1 +ano2;
    prob_trabalho= ((soma_anos) - (soma_dias_meses * 8)) % 101;
    if(prob_trabalho < 40){
        printf("Trabalho: %d%% ", prob_trabalho);
        puts("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    } else if(prob_trabalho >= 40 && prob_trabalho <= 50){
        printf("Trabalho: %d%% ", prob_trabalho);
        puts("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    } else if(prob_trabalho >= 51 && prob_trabalho <= 69){
        printf("Trabalho: %d%% ", prob_trabalho);
        puts("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    } else if(prob_trabalho >= 70 && prob_trabalho <= 84){
        printf("Trabalho: %d%% ", prob_trabalho);
        puts("Boas vibracoes hoje, chances podem estar ao seu redor.");
    } else{
        printf("Trabalho: %d%% ", prob_trabalho);
        puts("Use do maximo de networking possível hoje, dia bom para negocios.");
    }

//calculo da cor
// foi utilizado switch ao invés de if
    int tipo_cor;
    tipo_cor = ((dia1 * dia1)+ (dia2 * dia2)+ (mes1 * mes1)+ (mes2 * mes2)+ (ano1 * ano1)+ (ano2 * ano2)) % 11;
    switch(tipo_cor){
        case 0:
        puts("Cor: Cinza");
        break;
        case 1:
        puts("Cor: Vermelho");
        break;
        case 2:
        puts("Cor: Laranja");
        break;
        case 3:
        puts("Cor: Amarelo");
        break;
        case 4:
        puts("Cor: Verde");
        break;
        case 5:
        puts("Cor: Azul");
        break;
        case 6:
        puts("Cor: Roxo");
        break;
        case 7:
        puts("Cor: Marrom");
        break;
        case 8:
        puts("Cor: Rosa");
        break;
        case 9:
        puts("Cor: Preto");
        break;
        case 10:
        puts("Cor: Branco");
        break;
    }
    return 0;
}
