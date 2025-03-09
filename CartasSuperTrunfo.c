#include <stdio.h>
#include <string.h>
// Desafio Super Trunfo - Países

void Menu_Escolhas(int atributo_numero, int *atributo_excluido, int *atributo_selecionado) {
    int opcao;
    printf("\nEscolha o %d° Atributo \n", atributo_numero);
    printf(atributo_excluido != 1 ?"1. População\n":"x. População\n" );
    printf(atributo_excluido != 2 ?"2. Área\n":"x. Área\n" );
    printf(atributo_excluido != 3 ?"3. PIB\n":"x. PIB\n" );
    printf(atributo_excluido != 4 ?"4. Pontos Turísticos\n":"x. Pontos Turísticos\n" );
    printf(atributo_excluido != 5 ?"5. Densidade Demografica\n":"x. Densidade Demografica\n" );
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            atributo_excluido!=1 ?*atributo_selecionado = 1:Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            printf(atributo_excluido!= 1 ?"\nPopulação Adicionada\n":"\n População Já Selecionada" );
            break;
        case 2:
            atributo_excluido !=2 ?*atributo_selecionado =2:Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            printf(atributo_excluido != 2 ?"\nÁrea Adicionada\n":"\nÁrea Já Selecionada" );
            break;
        case 3:
            atributo_excluido !=3 ?*atributo_selecionado =3:Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            printf(atributo_excluido != 3 ?"\nPIB Adicionada\n":"\nPIB Já Selecionada" );
            break;
        case 4:
            atributo_excluido !=4 ?*atributo_selecionado =4:Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            printf(atributo_excluido != 4 ?"\nPontos Turísticos Adicionada\n":"\nPontos Turísticos Já Selecionada" );
            break;
        case 5:
            atributo_excluido !=5 ?*atributo_selecionado =5:Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            printf(atributo_excluido != 5 ?"\nDensidade Demografica Adicionada\n":"\nDensidade Demografica Já Selecionada" );
            break;
        default:
            printf("Opção Inválida\n");
            Menu_Escolhas(atributo_numero, atributo_excluido, atributo_selecionado);
            break;
    }
}


int Definir_Vencedor(char atributo[20], int primeiro_parametro, int segundo_parametro) {
    int resultado;
    
    if (primeiro_parametro > segundo_parametro) {
        resultado = 1; // Primeiro valor é maior
    } else if (primeiro_parametro < segundo_parametro) {
        resultado = 0; // Segundo valor é maior
    } else {
        return 2; // Valores são iguais
    }
    
    // Para o atributo "Densidade", invertemos o resultado
    if (strcmp(atributo, "Densidade") == 0) {
        resultado = !resultado;
    }
    
    return resultado;
}

// Double para maior precisão
double Calculo_Densidade_Populacional(int populacao, float area){
    return (double)(populacao/area);
}

double Calculo_PIB_Per_Capita(float pib, int populacao){
    // Multiplicação por 1 bilhão por conta do pib ser em Bilhoões de Reais
    return (double)((pib*1000000000)/populacao);
}

float Calculo_Super_Poder(unsigned long int populacao, float area, float pib, int pontos_turisticos, double densidade_populacional, double pib_per_capita){
    return (float)(populacao + area + pib + (float)pontos_turisticos + pib_per_capita - densidade_populacional);
};

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
  
    


    char primeiro_estado[5], segundo_estado[5];

    char primeiro_codigo_da_carta[10], segundo_codigo_da_carta[10];

    char primeiro_nome_da_cidade[20], segundo_nome_da_cidade[20];

    unsigned long int primeira_populacao, segunda_populacao;

    float primeira_area, segunda_area;

    float primeiro_pib, segundo_pib;

    int primeiro_numero_de_pontos_turisticos, segundo_numero_de_pontos_turisticos;

    double primeira_densidade_populacional, segunda_densidade_populacional;

    double primeiro_pib_per_capita, segundo_pib_per_capita;

    float primeiro_super_poder, segundo_super_poder;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Primeira carta
    int menu_opcao;
    printf("\n\n1- Cadastrar Carta 1-2");
    printf("\n2- Comparar Cartas Já Selecionadas\n");
    scanf("%d", &menu_opcao);
    switch(menu_opcao){
        case 1:
            printf("Cadastrando Carta\n");
            __fpurge(stdin);
            break;
        case 2:
            printf("Comparando Carta\n");
            // Valores da primeira carta
            strcpy(primeiro_nome_da_cidade, "São Paulo");
            strcpy(primeiro_estado, "A");
            strcpy(primeiro_codigo_da_carta, "01");
            primeira_populacao = 12325000;
            primeira_area = 1521.11;
            primeiro_pib = 699.28;
            primeiro_numero_de_pontos_turisticos = 50;

            // Valores da segunda carta
            strcpy(segundo_nome_da_cidade, "Rio de Janeiro");
            strcpy(segundo_estado, "B");
            strcpy(segundo_codigo_da_carta, "02");
            segunda_populacao = 6748000;
            segunda_area = 1200.25;
            segundo_pib = 300.50;
            segundo_numero_de_pontos_turisticos = 30;
            break;
        default:
            printf("Opção Invalida");
            break;
    }

    if (menu_opcao ==1){
        printf("Proxima Carta -> 1° Carta - : \n");

        printf("1° Carta - Digite o Nome da Cidade: \n");
        fgets(primeiro_nome_da_cidade, 20, stdin);
        primeiro_nome_da_cidade[strcspn(primeiro_nome_da_cidade, "\n")] = '\0';
        
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
        segundo_nome_da_cidade[strcspn(segundo_nome_da_cidade, "\n")] = '\0';
        
        printf("2° Carta - Digite o Nome da Cidade: \n");
        fgets(segundo_nome_da_cidade, 20, stdin);
        segundo_nome_da_cidade[strcspn(segundo_nome_da_cidade, "\n")] = '\0';
        
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
    }
    // Calculo de Densidade Populacional e PIB per Capita

    primeiro_pib_per_capita = Calculo_PIB_Per_Capita(primeiro_pib, primeira_populacao);
    segundo_pib_per_capita = Calculo_PIB_Per_Capita(segundo_pib, segunda_populacao);

    primeira_densidade_populacional = Calculo_Densidade_Populacional(primeira_populacao, primeira_area);
    segunda_densidade_populacional = Calculo_Densidade_Populacional(segunda_populacao, segunda_area);


    // Calculo de Super Poder
    primeiro_super_poder = Calculo_Super_Poder(primeira_populacao, primeira_area, primeiro_pib, primeiro_numero_de_pontos_turisticos, primeira_densidade_populacional, primeiro_pib_per_capita);
    segundo_super_poder = Calculo_Super_Poder(segunda_populacao, segunda_area, segundo_pib, segundo_numero_de_pontos_turisticos, segunda_densidade_populacional, segundo_pib_per_capita);


    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    
    printf("\nCarta 1: ");
    printf("\nEstado: %s", primeiro_estado);
    printf("\nCódigo: %s%s", primeiro_estado, primeiro_codigo_da_carta);
    printf("\nNome da Cidade: %s", primeiro_nome_da_cidade);
    printf("\nPopulação: %d", primeira_populacao);
    printf("\nÁrea: %.2f km²", primeira_area);
    printf("\nPIB: %.2f bilhões de reais", primeiro_pib);
    printf("\nNúmero de Pontos Turísticos: %d", primeiro_numero_de_pontos_turisticos);
    printf("\nDensidade Populacional: %.2f hab/km²", primeira_densidade_populacional);
    printf("\nPIB per Capita: %.2f reais", primeiro_pib_per_capita);
    printf("\nSuper Poder: %.2f Poder\n", primeiro_super_poder);

    printf("\nCarta 2: ");
    printf("\nEstado: %s", segundo_estado);
    printf("\nCódigo: %s%s", segundo_estado, segundo_codigo_da_carta);
    printf("\nNome da Cidade: %s", segundo_nome_da_cidade);
    printf("\nPopulação: %d", segunda_populacao);
    printf("\nÁrea: %.2f km²", segunda_area);
    printf("\nPIB: %.2f bilhões de reais", segundo_pib);
    printf("\nNúmero de Pontos Turísticos: %d", segundo_numero_de_pontos_turisticos);
    printf("\nDensidade Populacional: %.2f hab/km²", segunda_densidade_populacional);
    printf("\nPIB per Capita: %.2f reais", segundo_pib_per_capita);
    printf("\nSuper Poder: %.2f Poder\n", segundo_super_poder);
    
    // Variaveis Resultados
    int resultado_populacao = primeira_populacao>=segunda_populacao; 
    int resultado_area = primeira_area>=segunda_area; 
    int resultado_pib = primeiro_pib >= segundo_pib; 
    int resultado_turistico = primeiro_numero_de_pontos_turisticos >= segundo_numero_de_pontos_turisticos; 
    int resultado_densidade = primeira_densidade_populacional <= segunda_densidade_populacional; 
    int resultado_pib_per_capita = primeiro_pib_per_capita >= segundo_pib_per_capita; 
    int resultado_poder = primeiro_super_poder >= segundo_super_poder; 

    // Comparação Final de Cartas -- Resultado
    printf("\n\nComparação de Cartas:\n");

    // utilização de (2-resultado) para alterar a primeira variavel de 0 ou 1 para 1 ou 2, definindo assim qual a carta ganhadora
    printf("População: Carta %d venceu (%d)\n",(2-resultado_populacao), resultado_populacao);
    printf("Área: Carta %d venceu (%d)\n",(2-resultado_area), resultado_area);
    printf("PIB: Carta %d venceu (%d)\n",(2-resultado_pib), resultado_pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",(2-resultado_turistico), resultado_turistico);
    printf("Densidade Populacional: Carta %d venceu (%d)\n",(2-resultado_densidade), resultado_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n",(2-resultado_pib_per_capita), resultado_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n",(2-resultado_poder), resultado_poder);



    int resultado;

    int primeiro_atributo , segundo_atributo ;
    Menu_Escolhas(1,"0", &primeiro_atributo);
    Menu_Escolhas(2,primeiro_atributo, &segundo_atributo);

    float soma_geral_primeira_carta ;
    float soma_geral_segunda_carta;
    switch(primeiro_atributo){
        case 1:
            resultado = Definir_Vencedor("População" ,primeira_populacao, segunda_populacao);
            printf("\nComparação de Atributo (Atributo: População):");
            printf("\nCarta 1 - %s (%s%s): %lu", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_populacao);
            printf("\nCarta 2 - %s (%s%s): %lu", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_populacao);
            soma_geral_primeira_carta = primeira_populacao;
            soma_geral_segunda_carta = segunda_populacao;
            break;
        case 2:
            resultado = Definir_Vencedor("Área" ,primeira_area, segunda_area);
            printf("\nComparação de Atributo (Atributo: Área):");
            printf("\nCarta 1 - %s (%s%s): %.2f km²", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_area);
            printf("\nCarta 2 - %s (%s%s): %.2f km²", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_area);
            soma_geral_primeira_carta = primeira_area;
            soma_geral_segunda_carta = segunda_area;
            break;
        case 3:
            resultado = Definir_Vencedor("PIB" ,primeiro_pib, segundo_pib);
            printf("\nComparação de Atributo (Atributo: PIB):");
            printf("\nCarta 1 - %s (%s%s): %.2f bilhões de reais", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeiro_pib);
            printf("\nCarta 2 - %s (%s%s): %.2f bilhões de reais", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segundo_pib);
            soma_geral_primeira_carta = primeiro_pib;
            soma_geral_segunda_carta = segundo_pib;
            break;
        case 4:
            resultado = Definir_Vencedor("turísticos" ,primeiro_numero_de_pontos_turisticos, segundo_numero_de_pontos_turisticos);
            printf("\nComparação de Atributo (Atributo: Número de pontos turísticos):");
            printf("\nCarta 1 - %s (%s%s): %d", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeiro_numero_de_pontos_turisticos);
            printf("\nCarta 2 - %s (%s%s): %d", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segundo_numero_de_pontos_turisticos);
            soma_geral_primeira_carta = primeiro_numero_de_pontos_turisticos;
            soma_geral_segunda_carta = segundo_numero_de_pontos_turisticos;
            break;
        case 5:
            resultado = Definir_Vencedor("Densidade" ,primeira_densidade_populacional, segunda_densidade_populacional);
            printf("\nComparação de Atributo (Atributo: Densidade demográfica):");
            printf("\nCarta 1 - %s (%s%s): %.2f hab/km²", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_densidade_populacional);
            printf("\nCarta 2 - %s (%s%s): %.2f hab/km²", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_densidade_populacional);
            soma_geral_primeira_carta = primeira_densidade_populacional;
            soma_geral_segunda_carta = segunda_densidade_populacional;
            break;
        case 0:
            printf("Saindo");
            break;
        default:
            printf("Opção Invalida");
            break;
        
    }
    char vencedor_nome [20];
    if (resultado != 2){
        if (resultado == 0){
            strcpy(vencedor_nome, segundo_nome_da_cidade);
        }
        else{
        strcpy(vencedor_nome, primeiro_nome_da_cidade);
        }
        printf("\nResultado: Carta %d (%s) venceu!", (2-resultado), vencedor_nome);
    }
    else{
        printf("\n %s -- Empate -- %s",primeiro_nome_da_cidade, segundo_nome_da_cidade);
    };
    printf("\n");
    
    
    switch(segundo_atributo){
        case 1:
            resultado = Definir_Vencedor("População" ,primeira_populacao, segunda_populacao);
            printf("\nComparação de Atributo (Atributo: População):");
            printf("\nCarta 1 - %s (%s%s): %lu", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_populacao);
            printf("\nCarta 2 - %s (%s%s): %lu", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_populacao);
            soma_geral_primeira_carta += primeira_populacao;
            soma_geral_segunda_carta += segunda_populacao;
            break;
        case 2:
            resultado = Definir_Vencedor("Área" ,primeira_area, segunda_area);
            printf("\nComparação de Atributo (Atributo: Área):");
            printf("\nCarta 1 - %s (%s%s): %.2f km²", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_area);
            printf("\nCarta 2 - %s (%s%s): %.2f km²", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_area);
            soma_geral_primeira_carta += primeira_area;
            soma_geral_segunda_carta += segunda_area;
            break;
        case 3:
            resultado = Definir_Vencedor("PIB" ,primeiro_pib, segundo_pib);
            printf("\nComparação de Atributo (Atributo: PIB):");
            printf("\nCarta 1 - %s (%s%s): %.2f bilhões de reais", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeiro_pib);
            printf("\nCarta 2 - %s (%s%s): %.2f bilhões de reais", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segundo_pib);
            soma_geral_primeira_carta += primeiro_pib;
            soma_geral_segunda_carta += segundo_pib;
            break;
        case 4:
            resultado = Definir_Vencedor("turísticos" ,primeiro_numero_de_pontos_turisticos, segundo_numero_de_pontos_turisticos);
            printf("\nComparação de Atributo (Atributo: Número de pontos turísticos):");
            printf("\nCarta 1 - %s (%s%s): %d", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeiro_numero_de_pontos_turisticos);
            printf("\nCarta 2 - %s (%s%s): %d", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segundo_numero_de_pontos_turisticos);
            soma_geral_primeira_carta += primeiro_numero_de_pontos_turisticos;
            soma_geral_segunda_carta += segundo_numero_de_pontos_turisticos;
            break;
        case 5:
            resultado = Definir_Vencedor("Densidade" ,primeira_densidade_populacional, segunda_densidade_populacional);
            printf("\nComparação de Atributo (Atributo: Densidade demográfica):");
            printf("\nCarta 1 - %s (%s%s): %.2f hab/km²", primeiro_nome_da_cidade, primeiro_estado, primeiro_codigo_da_carta, primeira_densidade_populacional);
            printf("\nCarta 2 - %s (%s%s): %.2f hab/km²", segundo_nome_da_cidade, segundo_estado, segundo_codigo_da_carta, segunda_densidade_populacional);
            soma_geral_primeira_carta += primeira_densidade_populacional;
            soma_geral_segunda_carta += segunda_densidade_populacional;
            break;
        case 0:
            printf("Saindo");
            break;
        default:
            printf("Opção Invalida");
            break;
        
    }


    if (resultado != 2){
        if (resultado == 0){
            strcpy(vencedor_nome, segundo_nome_da_cidade);
        }
        else{
        strcpy(vencedor_nome, primeiro_nome_da_cidade);
        }
        printf("\nResultado: Carta %d (%s) venceu!\n", (2-resultado), vencedor_nome);
    }
    else{
        printf("\n %s -- Empate -- %s\n",primeiro_nome_da_cidade, segundo_nome_da_cidade);
    };
    

    printf("\n Valores Totais Carta 1 -- %s", primeiro_nome_da_cidade);
    printf("\n %2.f", soma_geral_primeira_carta);
    printf("\n Valores Totais Carta 2 -- %s", segundo_nome_da_cidade);
    printf("\n %2.f", soma_geral_segunda_carta);
    // loop para testar
    if (soma_geral_primeira_carta != soma_geral_segunda_carta){
        if (soma_geral_primeira_carta < soma_geral_segunda_carta){
            strcpy(vencedor_nome, segundo_nome_da_cidade);
        }
        else{
        strcpy(vencedor_nome, primeiro_nome_da_cidade);
        }
        printf("\nResultado: Carta %d (%s) venceu!", (2-(soma_geral_primeira_carta > soma_geral_segunda_carta)), vencedor_nome);
    }
    else{
        printf("\n %s -- Empate -- %s",primeiro_nome_da_cidade, segundo_nome_da_cidade);
    };
    main();
    return 0;
}