#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//  Divida a população da cidade pela sua área Densidade Populacional
//  Divida o PIB da cidade pela sua população   PIB per Capita


// Double para maior precisão
double Calculo_Densidade_Populacional(int populacao, float area){
    return (double)(populacao/area);
}

double Calculo_PIB_Per_Capita(float pib, int populacao){
    // Multiplicação por 1 bilhão por conta do pib ser em Bilhoões de Reais
    return (double)((pib*1000000000)/populacao);
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    char primeiro_estado[5], segundo_estado[5];

    char primeiro_codigo_da_carta[10],segundo_codigo_da_carta[10];

    char primeira_nome_da_cidade[20],segunda_nome_da_cidade[20];

    int primeira_populacao,segunda_populacao;

    float primeira_area,segunda_area;

    float primeiro_pib,segundo_pib;

    int primeiro_numero_de_pontos_turisticos,segundo_numero_de_pontos_turisticos;

    double primeira_densidade_populacional,segunda_densidade_populacional;

    double primeiro_pib_per_capita,segundo_pib_per_capita;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Primeira carta
    printf("Proxima Carta -> 1° Carta - : \n");

    printf("1° Carta - Digite o Nome da Cidade: \n");
    fgets(primeira_nome_da_cidade, 20, stdin);
    primeira_nome_da_cidade[strcspn(primeira_nome_da_cidade, "\n")] = '\0';
    
    printf("1° Carta - Digite uma Letra de 'A' a 'H' correspondente ao Estado: \n");
    fgets(primeiro_estado, 5, stdin);
    primeiro_estado[strcspn(primeiro_estado, "\n")] = '\0';
    
    printf("1° Carta - Digite um Codigo para a Carta (01 a 03): \n");
    fgets(primeiro_codigo_da_carta, 10, stdin);
    primeiro_codigo_da_carta[strcspn(primeiro_codigo_da_carta, "\n")] = '\0';
    
    printf("1° Carta - Digite a quantidade de habitantes (População): \n");
    scanf("%d", &primeira_populacao);
    
    printf("1° Carta - Digite a Área da Cidade em Km²: \n");
    scanf("%f", &primeira_area);
    
    printf("1° Carta - Digite o Produto Interno Bruto (PIB) da Cidade: \n");
    scanf("%f", &primeiro_pib);
    
    printf("1° Carta - Digite a quantidade de Pontos Turísticos da Cidade: \n");
    scanf("%d", &primeiro_numero_de_pontos_turisticos);
    
    printf("1° Carta - Concluída \n");
    
    // Limpar dados do buffer Para não vazar o input do anterior para o proximo
    __fpurge(stdin);
    
    // Segunda Carta
    printf("\nProxima Carta -> 2° Carta - : \n");
    segunda_nome_da_cidade[strcspn(segunda_nome_da_cidade, "\n")] = '\0';
    
    printf("2° Carta - Digite o Nome da Cidade: \n");
    fgets(segunda_nome_da_cidade, 20, stdin);
    segunda_nome_da_cidade[strcspn(segunda_nome_da_cidade, "\n")] = '\0';
    
    printf("2° Carta - Digite uma Letra de 'A' a 'H' correspondente ao Estado: \n");
    fgets(segundo_estado, 5, stdin);
    segundo_estado[strcspn(segundo_estado, "\n")] = '\0';
    
    printf("2° Carta - Digite um Codigo para a Carta (01 a 03): \n");
    fgets(segundo_codigo_da_carta, 10, stdin);
    segundo_codigo_da_carta[strcspn(segundo_codigo_da_carta, "\n")] = '\0';
    
    printf("2° Carta - Digite a quantidade de habitantes (População): \n");
    scanf("%d", &segunda_populacao);
    
    printf("2° Carta - Digite a Área da Cidade em Km²: \n");
    scanf("%f", &segunda_area);
    
    printf("2° Carta - Digite o Produto Interno Bruto (PIB) da Cidade: \n");
    scanf("%f", &segundo_pib);
    
    printf("2° Carta - Digite a quantidade de Pontos Turísticos da Cidade: \n");
    scanf("%d", &segundo_numero_de_pontos_turisticos);

    printf("2° Carta - Concluída \n");
    
    __fpurge(stdin);

    // Calculo de Densidade Populacional e PIB per Capita

    primeiro_pib_per_capita = Calculo_PIB_Per_Capita(primeiro_pib, primeira_populacao);
    segundo_pib_per_capita = Calculo_PIB_Per_Capita(segundo_pib, segunda_populacao);

    primeira_densidade_populacional = Calculo_Densidade_Populacional(primeira_populacao, primeira_area);
    segunda_densidade_populacional = Calculo_Densidade_Populacional(segunda_populacao, segunda_area);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    
    printf("\nCarta 1: ");
    printf("\nEstado: %s", primeiro_estado);
    printf("\nCódigo: %s%s", primeiro_estado, primeiro_codigo_da_carta);
    printf("\nNome da Cidade: %s", primeira_nome_da_cidade);
    printf("\nPopulação: %d", primeira_populacao);
    printf("\nÁrea: %.2f km²", primeira_area);
    printf("\nPIB: %.2f bilhões de reais", primeiro_pib);
    printf("\nNúmero de Pontos Turísticos: %d", primeiro_numero_de_pontos_turisticos);
    printf("\nDensidade Populacional: %.2f hab/km²", primeira_densidade_populacional);
    printf("\nPIB per Capita: %.2f reais\n", primeiro_pib_per_capita);

    printf("\nCarta 2: ");
    printf("\nEstado: %s", segundo_estado);
    printf("\nCódigo: %s%s", segundo_estado, segundo_codigo_da_carta);
    printf("\nNome da Cidade: %s", segunda_nome_da_cidade);
    printf("\nPopulação: %d", segunda_populacao);
    printf("\nÁrea: %.2f km²", segunda_area);
    printf("\nPIB: %.2f bilhões de reais", segundo_pib);
    printf("\nNúmero de Pontos Turísticos: %d", segundo_numero_de_pontos_turisticos);
    printf("\nDensidade Populacional: %.2f hab/km²", segunda_densidade_populacional);
    printf("\nPIB per Capita: %.2f reais\n", segundo_pib_per_capita);
    
    return 0;
}



/*
            Exemplo de Saída: Nível Aventureiro

            Inputs -- Copie e cole no terminal como 14 linhas de texto
São Paulo
A
01
12325000
1521.11
699.28
50
Rio de Janeiro
B
02
6748000
1200.25
300.50
30


Carta 1:
Estado: A
Código: A01
Nome da Cidade: São Paulo
População: 12325000
Área: 1521.11 km²
PIB: 699.28 bilhões de reais
Número de Pontos Turísticos: 50
Densidade Populacional: 8102.47 hab/km²
PIB per Capita: 56724.32 reais

Carta 2:
Estado: B
Código: B02
Nome da Cidade: Rio de Janeiro
População: 6748000
Área: 1200.25 km²
PIB: 300.50 bilhões de reais
Número de Pontos Turísticos: 30
Densidade Populacional: 5622.24 hab/km²
PIB per Capita: 44532.91 reais

*/