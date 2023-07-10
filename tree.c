#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    struct Node* leftNode;
    struct Node* rightNode;
    int value;
} Node;

typedef struct
{
   struct Node* root;
} Tree;
void exibirMenu()
{
    printf("========== MENU ==========\n");
    printf("1. Inserir Novo valor 1\n");
    printf("2. Remover Um valor 2\n");
    printf("3. Visualizar Árvore 3\n");
    printf("4. Sair\n");
    printf("==========================\n");
    printf("Escolha uma opção: ");
}

int exibirMenuAdd()
{
    int valor;
    printf("========== Adicionar Novo Valor ==========\n");
    scanf("%d", &valor);    
   return valor;
};
void executarOpcao(int opcao,  Tree *tree)
{ 
int valor = NULL;
    switch (opcao)
    {
    case 1:
        valor = exibirMenuAdd();
        addNode(tree, valor);
       
        break;
    case 2:
        printf("Executando Opção 2\n");
        // Código para a Opção 2
        break;
    case 3:
        printf("Executando Opção 3\n");
            Node *visualizer = (Node*) malloc(sizeof(Node));
            visualizer = tree->root;
        while(1){
        
            printf("valor: %d",visualizer->value);
           visualizer = visualizer->leftNode;
            
            printf("valor: %d",visualizer->value);
    
          break;
        }
        break;
    case 4:
        printf("Encerrando o programa...\n");
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}

void addNode(Tree *tree, int value)
{
    Node *newNodeTemp = (Node*) malloc(sizeof(Node));
   
    newNodeTemp->value = value;
    newNodeTemp->leftNode = NULL;
    newNodeTemp->rightNode = NULL;

    if (tree->root == NULL)
    {
        tree->root = newNodeTemp;
    }
    else
    {

        Node *primary = tree->root;
        Node *parent = NULL;
        Node *parent2 = NULL;
      
        printf("\n raiz: %d", primary->value);
        while (1)
        {
            parent = primary;
            printf("\nparent: %d", parent->value);
            parent2 = parent->leftNode;
            if(parent2 == NULL){
                printf("\n esta nulo");
            }
            if(value < (parent->value)){
                printf("\nsalvo: %d", value);
                
                if(parent->leftNode == NULL){
                    primary = newNodeTemp;
                    break;
                }
                
            }else{                                              
                primary = parent->rightNode;
                
               if(primary == NULL){
                  parent->rightNode = newNodeTemp;
                  
               }
            }
        }
    }
     
}

int main()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    int opcao;
 

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        executarOpcao(opcao, tree);

        printf("\n");

    } while (opcao != 4);
 
}




