#include <stdio.h>
#include <string.h>

// Definição da estrutura para as cartas
typedef struct {
  char estado[6];
  char codigo[6];
  char cidade[30];
  unsigned long int populacao;
  float area;
  float pib;
  int pontosTuristicos;
} Carta;

// funcao que exibe informacoes de uma carta
void exibirCarta(Carta carta, float densidade, float pibPerCapita) {
  printf("Cidade: %s\n", carta.cidade);
  printf("Estado: %s\n", carta.estado);
  printf("Populacao: %lu\n", carta.populacao);
  printf("Area: %.2f km2\n", carta.area);
  printf("PIB: %.2f bilhoes de reais\n", carta.pib);
  printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
  printf("Densidade populacional: %.2f hab/km2\n", densidade);
  printf("PIB per Capita: %.2f\n", pibPerCapita);
}

int main() {
  // inicializa dados da primeira e segunda carta
  Carta cartaUm = {.estado = "SP",
                   .codigo = "SP01",
                   .cidade = "Sao Paulo",
                   .populacao = 12396372,
                   .area = 1521.11,
                   .pib = 763.8,
                   .pontosTuristicos = 50};

  Carta cartaDois = {.estado = "RJ",
                     .codigo = "RJ01",
                     .cidade = "Rio de Janeiro",
                     .populacao = 6775561,
                     .area = 1200.25,
                     .pib = 354.2,
                     .pontosTuristicos = 30};

  // calculo de densidade e pib per capita, das duas cartas
  float densidadeUm = cartaUm.populacao / cartaUm.area;
  float pibPerCapitaUm = (cartaUm.pib*1000000000) / cartaUm.populacao; //multipliquei o pib por 1 bilhao, pra igualar a magnitude dos valores

  float densidadeDois = cartaDois.populacao / cartaDois.area;
  float pibPerCapitaDois = (cartaDois.pib*1000000000) / cartaDois.populacao; 

  // Exibição das informações das cartas
  printf("--- Dados da Carta 1 ---\n");
  exibirCarta(cartaUm, densidadeUm, pibPerCapitaUm);

  printf("\n--- Dados da Carta 2 ---\n");
  exibirCarta(cartaDois, densidadeDois, pibPerCapitaDois);

  printf("\n");

  int escolhaAtributo;
  printf("Escolha o atributo que quer comparar:");
  printf("1-Populacao\n");
  printf("2-Area\n");
  printf("3-PIB\n");
  printf("4-Numero de pontos turisticos\n");
  printf("5-Densidade demografica\n");
  scanf("%d", &escolhaAtributo);

  switch (escolhaAtributo) {
  case 1:
    if (cartaUm.populacao > cartaDois.populacao) {
      printf("Vencedor: Carta 1 (%s); Populacao: %lu\n", cartaUm.cidade,
             cartaUm.populacao);
      printf("Perdedor: Carta 2(%s); Populacao: %lu\n", cartaDois.cidade,
             cartaDois.populacao);
    } else if (cartaUm.populacao < cartaDois.populacao) {
      printf("Vencedor: Carta 2 (%s); Populacao: %lu\n", cartaDois.cidade,
             cartaDois.populacao);
      printf("Perdedor: Carta 1(%s); Populacao: %lu\n", cartaUm.cidade,
             cartaUm.populacao);
    } else {
      printf("Empate!\n");
      printf("Carta 1(%s); Carta 2(%s)\n", cartaUm.cidade, cartaDois.cidade);
    }
    break;

  case 2:

    if (cartaUm.area > cartaDois.area) {
      printf("Vencedor: Carta 1 (%s); Area: %f\n", cartaUm.cidade,
             cartaUm.area);
      printf("Perdedor: Carta 2(%s); Area: %f\n", cartaDois.cidade,
             cartaDois.area);
    } else if (cartaUm.area < cartaDois.area) {
      printf("Vencedor: Carta 2 (%s); Area: %f\n", cartaDois.cidade,
             cartaDois.area);
      printf("Perdedor: Carta 1(%s); Area: %f\n", cartaUm.cidade, cartaUm.area);
    } else {
      printf("Empate!\n");
      printf("Carta 1(%s); Carta 2(%s)\n", cartaUm.cidade, cartaDois.cidade);
    }
    break;

  case 3:
    if (cartaUm.pib > cartaDois.pib) {
      printf("Vencedor: Carta 1 (%s); PIB: %f\n", cartaUm.cidade, cartaUm.pib);
      printf("Perdedor: Carta 2(%s); PIB: %f\n", cartaDois.cidade,
             cartaDois.pib);
    } else if (cartaUm.pib < cartaDois.pib) {
      printf("Vencedor: Carta 2 (%s); PIB: %f\n", cartaDois.cidade,
             cartaDois.pib);
      printf("Perdedor: Carta 1(%s); PIB: %f\n", cartaUm.cidade, cartaUm.pib);
    } else {
      printf("Empate!\n");
      printf("Carta 1(%s); Carta 2(%s)\n", cartaUm.cidade, cartaDois.cidade);
    }
    break;

  case 4:
   if (cartaUm.pontosTuristicos > cartaDois.pontosTuristicos) {
      printf("Vencedor: Carta 1 (%s); Numero de pontos turisticos: %d\n", cartaUm.cidade,
             cartaUm.pontosTuristicos);
      printf("Perdedor: Carta 2(%s); Numero de pontos turisticos: %d\n", cartaDois.cidade,
             cartaDois.pontosTuristicos);
    } else if (cartaUm.pontosTuristicos < cartaDois.pontosTuristicos) {
      printf("Vencedor: Carta 2 (%s); Numero de pontos turisticos: %d\n", cartaDois.cidade,
             cartaDois.pontosTuristicos);
      printf("Perdedor: Carta 1(%s); Numero de pontos turisticos: %d\n", cartaUm.cidade, cartaUm.pontosTuristicos);
    } else {
      printf("Empate!\n");
      printf("Carta 1(%s); Carta 2(%s)\n", cartaUm.cidade, cartaDois.cidade);
    }
    break;

   case 5:
   if (densidadeUm < densidadeDois) {
      printf("Vencedor: Carta 1 (%s); Numero de pontos turisticos: %f\n", cartaUm.cidade,
             densidadeUm);
      printf("Perdedor: Carta 2(%s); Numero de pontos turisticos: %f\n", cartaDois.cidade,
             densidadeDois);
    } else if (densidadeDois < densidadeUm) {
      printf("Vencedor: Carta 2 (%s); Numero de pontos turisticos: %f\n", cartaDois.cidade,
             densidadeDois);
      printf("Perdedor: Carta 1(%s); Numero de pontos turisticos: %f\n", cartaUm.cidade, densidadeUm);
    } else {
      printf("Empate!\n");
      printf("Carta 1(%s); Carta 2(%s)\n", cartaUm.cidade, cartaDois.cidade);
    }
    break;
  }

  return 0;
}