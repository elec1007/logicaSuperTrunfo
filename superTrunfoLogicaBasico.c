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
  Carta cartaUm = {
      .estado = "SP",
      .codigo = "SP01",
      .cidade = "Sao Paulo",
      .populacao = 12396372,
      .area = 1521.11,
      .pib = 763.8,
      .pontosTuristicos = 50};

  Carta cartaDois = {
      .estado = "RJ",
      .codigo = "RJ01",
      .cidade = "Rio de Janeiro",
      .populacao = 6775561,
      .area = 1200.25,
      .pib = 354.2,
      .pontosTuristicos = 30};

  // calculo de densidade e pib per capita, das duas cartas
  float densidadeUm = cartaUm.populacao / cartaUm.area;
  float pibPerCapitaUm = cartaUm.pib / cartaUm.populacao;

  float densidadeDois = cartaDois.populacao / cartaDois.area;
  float pibPerCapitaDois = cartaDois.pib / cartaDois.populacao;

  // Exibição das informações das cartas
  printf("--- Dados da Carta 1 ---\n");
  exibirCarta(cartaUm, densidadeUm, pibPerCapitaUm);

  printf("\n--- Dados da Carta 2 ---\n");
  exibirCarta(cartaDois, densidadeDois, pibPerCapitaDois);

 //escolha o atributo diretamente aq

  // if (cartaUm.populacao > cartaDois.populacao) {
  //   printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  // } else {
  //   printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  // }

  // if (cartaUm.area > cartaDois.area) {
  //   printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  // } else {
  //   printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  // }

  // if (cartaUm.pib > cartaDois.pib) {
  //   printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  // } else {
  //   printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  // }

  // if (cartaUm.pontosTuristicos > cartaDois.pontosTuristicos) {
  //   printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  // } else {
  //   printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  // }

  printf("\n--- Comparacao por Densidade Populacional ---\n");
  if (densidadeUm < densidadeDois) {
    printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  } else {
    printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  }

  // if (pibPerCapitaUm > pibPerCapitaDois) {
  //   printf("Vencedor: Carta 1 (%s)\n", cartaUm.cidade);
  // } else {
  //   printf("Vencedor: Carta 2 (%s)\n", cartaDois.cidade);
  // }

  return 0;
}