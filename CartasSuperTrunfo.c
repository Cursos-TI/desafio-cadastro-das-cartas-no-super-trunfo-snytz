#include <stdio.h>
#include <string.h> //Incluí essa biblioteca pois desejava escrever os nomes compostos das cidades

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Aluno: Antonio Shansheel Colares Rodrigues
// Utilizei o VScode do meu computador para fazer o código, comecei a codar assim que vi o desafio, depois que vim ver os vídeos de instruções do professor informando que deveria utilizar o CodeSpace. 

int main() {

    char estado1, estado2;
    char code1[3], code2[3];
    char cid1[50], cid2[50];
    int pontos1, pontos2;
    float pib1, pib2, area1, area2, dens1, dens2, capita1, capita2;
    unsigned long int pop1, pop2;
    float superpoder1, superpoder2;
    
        printf("Bem vindo ao jogo Super Trunfo!\n");

            printf("\n"); //Utilizei essas quebras de linhas pois achei o texto muito "colado", assim a leitura dos dados fica mais clara e menos poluída. 
        
        printf("Por favor, informe a letra inicial (entre A e H) do primeiro estado desejado: "); //Conforme orientado no passo a passo aqui está a entrada de dados do usuário.
        scanf(" %c", &estado1);

        printf("Por favor, informe a letra inicial (entre A e H) do segundo estado desejado: ");
        scanf(" %c", &estado2);

            printf("\n");
        
        printf("Agora, informe o código (entre 01 e 04) do primeiro estado escolhido: ");
        scanf(" %s", code1);

        printf("Informe também o código (entre 01 e 04) do segundo, estado escolhido: ");
        scanf(" %s", &code2);

            printf("\n");

                 printf("O código da carta1 é %c%s\n", estado1, code1); //Gerei aqui um texto informando o código da carta que está sendo criada, era para ser apenas um teste para concatenar as informações digitadas.
                 printf("O código da carta2 é %c%s\n", estado2, code2);
            
                 getchar(); //Utilziei getchar para consumir o buffer de enter da ultima linha.

            printf("\n");

        printf("Informe o nome de uma cidade do primeiro estado selecionado: ");
        fgets(cid1, 50, stdin); //Aqui utilizei fgets para que seja possível a digitação de textos compostos, visto a limitação do scanf sobre espaçamentos, o stdin recebe informação do teclado. 
        cid1[strcspn(cid1, "\n")] = 0; //Essa linha evita uma quebra de linha indesejada quando o usuário foi escrever o dado no terminal.
        //scanf(" %s", cid1); Retirei o scanf para que seja possível nomes compostos

        printf("Agora informe o nome de uma cidade do segundo estado selecionado: ");
        fgets(cid2, 50, stdin);
        cid2[strcspn(cid2, "\n")] = 0;

            printf("\n");

        printf("Informe a população da cidade %s: ", cid1); //A fim de tornar o código menos confuso e evitar repetições nos textos, optei por trazer a informação da cidade informada pelo usuário nos textos. 
        scanf(" %d", &pop1);

        printf("Agora informe a população da cidade %s: ", cid2);
        scanf(" %d", &pop2);

            printf("\n");

        printf("Informe a área em km² da cidade %s: ", cid1);
        scanf(" %f", &area1);

        printf("Agora informe área em km² da cidade %s: ", cid2);
        scanf(" %f", &area2);

            printf("\n");

        printf("Informe o PIB da cidade %s: ", cid1);
        scanf(" %f", &pib1);

        printf("Agora informe o PIB da cidade %s: ", cid2);
        scanf(" %f", &pib2);

            printf("\n");

        printf("Informe o número de pontos turísticos da cidade %s: ", cid1);
        scanf(" %d", &pontos1);

        printf("E agora informe o número de pontos turísticos da cidade %s: ", cid2);
        scanf(" %d", &pontos2);

            printf("\n");

        dens1 = (float) pop1 / area1; //Realizando conversão de tipo de dados para evitar erros no resultado. 
        dens2 = (float) pop2 / area2; //Calculo da densidade demográfica da carta 1/2.

        capita1 = (float) (pib1 * 1000000000) / pop1;  //Multipliquei por 1B pois achei que seria mais prático para o usuário, seria difultoso sempre ter que digitar o número completo, várias cidades tem mais de 1B de pib.
        capita2 = (float) (pib2 * 1000000000) / pop2;  //Calculo do PIB per Capita da carta 1/2. 

        superpoder1 = (float) (pop1 + area1 + pib1 + capita1 + pontos1) + 1 / dens1; 
        superpoder2 = (float) (pop2 + area2 + pib2 + capita2 + pontos2) + 1 / dens2; //Calculo do Super Poder 1 e 2. 

        //Abaixo estão as informações das cartas junto aos resultados das comparações.
        printf("Sua carta 1 (%c%s) foi cadastrada com sucesso, segue abaixo as informações: \n", estado1, code1); //Aqui se inicia a saída dos dados cadastrados pelo usuário.
        printf("Estado: %c\n", estado1);
        printf("Código: %c%s\n", estado1, code1);
        printf("Nome da cidade: %s\n", cid1);
        printf("População: %u, carta 1 venceu: %d \n", pop1, pop1 > pop2); //Optei por fazer a comparação na própria linha de retorno das informações das cartas para evitar gerar mais uma linha só para as comparações.
        printf("Área: %.2f Km², carta 1 venceu: %d \n", area1, area1 > area2);
        printf("A densidade demográfica é de: %.3f, carta 1 venceu: %d\n", dens1, dens1 < dens2);
        printf("PIB: %.2f, carta 1 venceu: %d \n", pib1 * 1000000000, pib1 > pib2);
        printf("O PIB per Capita é de: %.3f Reais, carta 1 venceu: %d \n", capita1, capita1 > capita2);
        printf("Número de pontos turísticos: %d, carta 1 venceu: %d \n", pontos1, pontos1 > pontos2);
        printf("O Super Poder é %.3f, carta 1 venceu: %d \n", superpoder1, superpoder1 > superpoder2);

            printf("\n");

        printf("Sua carta 2 (%c%s) foi cadastrada com sucesso, segue abaixo as informações: \n", estado2, code2);
        printf("Estado: %c\n", estado2);
        printf("Código: %c%s\n", estado2, code2);
        printf("Nome da cidade: %s\n", cid2);
        printf("População: %u, carta 2 venceu: %d\n", pop2, pop2 > pop1);
        printf("Área : %.2f Km², carta 2 venceu: %d\n", area2, area2 > area1);
        printf("A densidade demográfica é de: %.3f, carta 2 venceu: %d \n", dens2, dens2 < dens1);
        printf("PIB: %.2f, carta 2 venceu: %d \n", pib2 * 1000000000, pib2 > pib1);
        printf("O PIB per Capita é de: %.3f Reais, carta 2 venceu: %d: \n", capita2, capita2 > capita1);
        printf("Número de pontos turísticos: %d, carta 2 venceu: %d \n", pontos2, pontos2 > pontos1);
        printf("O Super Poder é %.3f, carta 2 venceu: %d \n", superpoder2, superpoder2 > superpoder1);

    

    return 0;
}
