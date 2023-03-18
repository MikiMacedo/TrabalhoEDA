#include <stdio.h>

typedef struct registogestores
{int idgestor; // número identificador do gestor
 char nomegestor[60];
 struct registogestores* seguinte;
} Gestor;

// Inserção de um novo registo de Gestor
Gestor* inserirGestor(Gestor * inicio, int idges, char nomeges[]);

// listar na consola o conteúdo da lista ligada
void listarGestores(Gestor* inicio);

// Determinar existência do 'identificador do gestor' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeGestor(Gestor* inicio, int idges);

// Remover um gestor a partir do seu código
Gestor* removerGestor(Gestor* inicio, int idges);

//Tamanho da lista ligada
int tamanhoGestores(Gestor* inicio);

// Inserção de um novo registo no fim
Gestor* inserirFimGes(Gestor* inicio, int idges, char nomeges[]);
// remover lista ligada

int removerTodosGes(Gestor* inicio);

// consultar registo a partir do identificador de gestor
Gestor* consultarGes(Gestor* inicio, int idges);

// Criar uma cópia da lista ligada
Gestor* copiaListaGesLigada(Gestor* inicio);

// Guarda registo do gestor
int guardarGestor(Gestor* inicio);

// Ler registos do gestores
Gestor* lerGestores();

// Alterar um gestor a partir do seu identificador
Gestor* alterarGestor(Gestor* inicio, int idges, char nomeges[]);
