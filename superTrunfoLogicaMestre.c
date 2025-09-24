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

// botei as funcoes que printam as informacoes das cartas em funcoes, pra facilitar 
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

//mesma coisa pro menu de selecao
void menuSelecao() {
  printf("1-Populacao\n");
  printf("2-Area\n");
  printf("3-PIB\n");
  printf("4-Numero de pontos turisticos\n");
  printf("5-Densidade demografica\n");

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
  float pibPerCapitaUm = (cartaUm.pib * 1000000000) /
                       cartaUm.populacao; // multipliquei o pib por 1 bilhao,
                                          // pra igualar a magnitude dos valores

  float densidadeDois = cartaDois.populacao / cartaDois.area;
  float pibPerCapitaDois = (cartaDois.pib * 1000000000) / cartaDois.populacao;

  // printa as informações das cartas
  printf("--- Dados da Carta 1 ---\n");
  exibirCarta(cartaUm, densidadeUm, pibPerCapitaUm);

  printf("\n--- Dados da Carta 2 ---\n");
  exibirCarta(cartaDois, densidadeDois, pibPerCapitaDois);

  printf("\n");

  int escolhaUm;
  int escolhaDois;

  menuSelecao();
  printf("Escolha o primeiro atributo: ");
  scanf("%d ",&escolhaUm);

  printf("\n");

  menuSelecao();
  printf("Escolha o segundo atributo: ");
  scanf("%d ",&escolhaDois);

  if (escolhaUm == escolhaDois) {
    printf("Nao e permitido escolher o mesmo atributo duas vezes. O programa sera encerrado.\n");
    return 1; 
  }


  float valorUm_attr1, valorDois_attr1;
  float valorUm_attr2, valorDois_attr2;
  float somaUm = 0.0;
  float somaDois = 0.0;

  //logica para as combinacoes de valores de soma
  switch (escolhaUm) {
    case 1: 
      valorUm_attr1 = (float)cartaUm.populacao;
      valorDois_attr1 = (float)cartaDois.populacao;
      break;
    case 2: 
      valorUm_attr1 = cartaUm.area;
      valorDois_attr1 = cartaDois.area;
      break;
    case 3: 
      valorUm_attr1 = cartaUm.pib;
      valorDois_attr1 = cartaDois.pib;
      break;
    case 4:
      valorUm_attr1 = (float)cartaUm.pontosTuristicos;
      valorDois_attr1 = (float)cartaDois.pontosTuristicos;
      break;
    case 5: 
      valorUm_attr1 = (float)cartaUm.populacao / cartaUm.area;
      valorDois_attr1 = (float)cartaDois.populacao / cartaDois.area;
      break;
    default:
      printf("Opcao de atributo invalida. O programa sera encerrado.\n");
      return 1;
  }

  switch (escolhaDois) {
    case 1: 
      valorUm_attr2 = (float)cartaUm.populacao;
      valorDois_attr2 = (float)cartaDois.populacao;
      break;
    case 2: 
      valorUm_attr2 = cartaUm.area;
      valorDois_attr2 = cartaDois.area;
      break;
    case 3: 
      valorUm_attr2 = cartaUm.pib;
      valorDois_attr2 = cartaDois.pib;
      break;
    case 4: 
      valorUm_attr2 = (float)cartaUm.pontosTuristicos;
      valorDois_attr2 = (float)cartaDois.pontosTuristicos;
      break;
    case 5: 
      valorUm_attr2 = (float)cartaUm.populacao / cartaUm.area;
      valorDois_attr2 = (float)cartaDois.populacao / cartaDois.area;
      break;
    default:
      printf("Opcao de atributo invalida. O programa sera encerrado.\n");
      return 1;
  }



  printf("\n--- Comparacao de Cartas ---\n");
  printf("Carta 1: %s vs Carta 2: %s\n", cartaUm.estado, cartaDois.estado);
  
  // comparacao do primeiro atributo
  char *vencedorAttr1 = (escolhaUm == 5) ?
                        (valorUm_attr1 < valorDois_attr1 ? "Carta 1" : (valorDois_attr1 < valorUm_attr1 ? "Carta 2" : "Empate")) :
                        (valorUm_attr1 > valorDois_attr1 ? "Carta 1" : (valorDois_attr1 > valorUm_attr1 ? "Carta 2" : "Empate"));
  printf("Resultado do primeiro atributo: %s\n", vencedorAttr1);

  // comparacao do segundo atributo
  char *vencedorAttr2 = (escolhaDois == 5) ?
                        (valorUm_attr2 < valorDois_attr2 ? "Carta 1" : (valorDois_attr2 < valorUm_attr2 ? "Carta 2" : "Empate")) :
                        (valorUm_attr2 > valorDois_attr2 ? "Carta 1" : (valorDois_attr2 > valorUm_attr2 ? "Carta 2" : "Empate"));
  printf("Resultado do segundo atributo: %s\n", vencedorAttr2);
  

  somaUm = valorUm_attr1 + valorUm_attr2;
  somaDois = valorDois_attr1 + valorDois_attr2;
  
  printf("\nSoma da Carta 1 (%s): %.2f\n", cartaUm.estado, somaUm);
  printf("Soma da Carta 2 (%s): %.2f\n", cartaDois.estado, somaDois);
  
  // resultado final da soma
  if (somaUm > somaDois) {
    printf("\nVencedor da rodada: Carta 1 (%s)\n", cartaUm.estado);
  } else if (somaDois > somaUm) {
    printf("\nVencedor da rodada: Carta 2 (%s)\n", cartaDois.estado);
  } else {
    printf("\nEmpate na rodada!\n");
  }


  return 0;
}