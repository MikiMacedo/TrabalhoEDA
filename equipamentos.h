#include <stdio.h>

typedef struct registoeq
{int idequipamento; // código de identificação do equipamento de mobilidade elétrica;
    char tipo[50];
    float bateria;
    float autonomia;
    char localiza[50];
struct registoeq* seguinteq;
} Equipamento;


// Inserção de um novo registo
Equipamento* inserirEquipamento(Equipamento* inicio, int ideq, char tipo[], float bat, float aut, char loc[]); 

// listar na consola o conteúdo da lista ligada
void listarEquipamentos(Equipamento* inicio); 

// Determinar existência do 'identificador' na lista ligada 'inicio'
int existeEquipamento(Equipamento* inicio, int idequipamento);

// Remover um equipamento a partir do seu identificador
Equipamento* removerEquipamento(Equipamento* inicio, int ideq);

//Tamanho da lista ligada
int tamanho(Equipamento* inicio);
// Inserção de um novo registo no fim
Equipamento* inserirFim(Equipamento* inicio, int ideq, char tip[], float bat, float aut, char loc[]);
// remover lista ligada
int removerTodos(Equipamento* inicio);
// consultar registo a partir do identificador
Equipamento* consultarEq(Equipamento* inicio, int ideq);
// cálculo da autonomia média
float mediaAutonomia(Equipamento* inicio);
// Criar uma cópia da lista ligada
Equipamento* copiaListaLigada(Equipamento* inicio);
// Inserção de um novo registo numa determinada posição
Equipamento* inserirPos(Equipamento* inicio, int pos, int ideq, char tip[], float bat, float aut, char loc[]);
// Alterar dados

// Associar histórico de alugueres sob a forma de uma lista ligada

// Guarda a lista de equipamentos
int guardarEquipamento(Equipamento* inicio);

// Le a lista de equipamentos
Equipamento* lerEquipamentos();

// Alterar um Equipamento a partir do seu identificador
Equipamento* alterarEquipamento(Equipamento* inicio, int ideq, char tip[], float bat, float aut, char loc[]);

// Listar os equipamentos por ordem decrescente de Autonomia
void listarEquipamentosAutonomia(Equipamento * regequip, int idequipamento, char tipo[], float bateria, float autonomia, char localiza[]);

// Listar Equipamentos em uma determinada localização
void listarEquipamentosLocaliza(Equipamento * inicio, char localizaprocura[]);
