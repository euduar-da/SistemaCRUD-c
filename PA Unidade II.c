#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
// while não sei um limite estabelecido, nao sei a condição de limite
// for sei onde começa e onde termina

void cadastrar();
void doLogin();
int login();
void menu();
void printMenuOptions2();
void menuposlogin();
void cadastrarlivro();
void listarlivros();
int pesquisar();
void excluirId();
void printMenuAlterar();
void menuAlterar();
void clearScreen();
int op;
int main()
{
    menu();
    return 0;
}

struct cad
{
    char usuario[100]; //vai receber as informações do login
    char senha[100];
};

struct cad Cad[100];
int qtd = 0;

void menu()
{
   

    printMenuOptions();

    scanf("%d", &op);

    switch(op){
        case 1: 
        
            cadastrar();
            break;
        
        case 2:
            doLogin();
            break;
        case 3:
            printf("Obrigada pela Preferência!\n");
            exit(0);
            break;
        default: 
       
            printf("opcao invalida\n");
    }
}

void printMenuOptions()
{
    printf("== escolha uma opção ==\n");
    printf("1 - cadastrar\n");
    printf("2 - Login\n");
    printf("3 - sair\n");
}

void cadastrar()
{
    printf("Informe um email e uma senha que deseja cadastrar\n");
    scanf("%s %s", Cad[qtd].usuario, Cad[qtd].senha);
    qtd++;
    clearScreen();
    printf("Cadastro realizado com sucesso!\n");
    menu();
}

void doLogin()
{
    int i;
    char typeduser[100];
    char typedpass[100];
    printf("Informe o email e a senha\n");
    scanf("%s %s", typeduser, typedpass);

    int resultLogin = login(typeduser, typedpass);
    if (resultLogin == 1)
    {
        clearScreen();
        printf("LOGADO\n");
        menuposlogin();
        //MANDA PARA O MENU DE LIVROs
    }

    else
    {
        printf("Login Incorreto, tente novamente!\n");
        menu();
    }
}

int login(char* typeduser, char *typedpass)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        if (strcmp(typeduser, Cad[i].usuario) == 0 && strcmp(typedpass, Cad[i].senha) == 0)
        {
            return 1;
        }
    }

    return 0;
}


struct Livro {
	int idlivro;
    char nomelivro[100];
    float precolivro;
};

struct Livro livros[100];
int qt = 0;

void cadastrarlivro() {
    setlocale(LC_ALL, "Portuguese");
    printf("Você está acessando a área de cadastro de livros, para realizar o procedimento inform:\n");
    printf("o id do livro\n");
    scanf("%d", &livros[qt].idlivro);
    getchar();
    printf("o Nome do livro\n");
    fgets(livros[qt].nomelivro,100, stdin);
    printf("o preco do livro\n");
    scanf("%f", &livros[qt].precolivro);
    clearScreen();
    getchar();
    qt++;
    menuposlogin();
    
    //scanf("%d %s %f", &livros[qtd].idlivro, livros[qtd].nomelivro, &livros[qtd].precolivro);
  
}

void listarlivros() {
    int i;
    for (i = 0; i < qt; i++){
        printf ("aqui estão as informações:\n");
        printf("Id do livro: %d\n", livros[i].idlivro);
        printf("Nome do livro: %s\n", livros[i].nomelivro);
        printf("preco do livro: %f\n", livros[i].precolivro);
    }
    menuposlogin();
}

int pesquisar(int idlivro){
    int i;
    for(i = 0; i < qt; i++){
        if(livros[i].idlivro == idlivro){
            return i;
        }
    }
    return -1;
}

void excluirId(int idlivro){
    int i;
    int pos = pesquisar(idlivro);
    if(pos == -1){
        printf("Impossivel excluir");
    }
    else {
      for (i = pos; i < qt; i++){
            livros[i] = livros [i + 1];
            printf("excluído com sucesso!\n");
        }
        qt--;
    }


}

void printMenuOptions2(){
    printf("== escolha uma opcao ==\n");
    printf("1 - cadastrar\n");
    printf("2 - listar\n");
    printf("3 - excluir\n");
    printf("4 - editar\n");
    printf("5 - participar da rifa\n");
    printf("6 - sair\n");
    printf("Você deseja:\n ");
}

void printMenuAlterar(){
    printf("Você Deseja: \n");
    printf("1 - alterar o id de um livro \n");
    printf("2 - alterar o nome de um livro \n");
    printf("3 - alterar o preço de um livro \n");
    printf("4 - retornar para o menu \n");
}

void menuAlterar(int idlivro){
    int pos = pesquisar(idlivro);
    if(pos == -1){
        printf("impossível alterar!\n");
    }
    else{
        printMenuAlterar();
        int op;
        scanf("%d", &op);
        if(op == 1){
            printf("insira um novo id: \n");
            scanf("%d", &livros[pos].idlivro);
            printf("Alterado com sucesso!\n");
        }
        else if(op == 2){
            printf("insira um novo nome para o livro: \n");
            scanf("%s", livros[pos].nomelivro);
            printf("Alterado com sucesso!\n");
        }
        else if(op == 3){
            
            printf("insira um novo preço para o livro: \n");
            scanf("%d", &livros[pos].precolivro);
            printf("Alterado com sucesso!\n");
        }
        else if(op == 4){
            menuposlogin();
        }

    }

}

int getCartela(int row, int col){  //   19; 23; 24; 25; 27; 28; 
    int matriz[3][7] = {
        {10, 15, 14, 17, 18, 26, 30},   //intervalo de 10 até 31
        {12, 21, 13, 22, 16, 29, 20},
        {19, 23, 24, 27, 25, 28, 31}

        
    };
    return matriz[row][col];
    
}

int gerarNumAlatorio(int min, int max){
    srand(time(NULL));
    return min + rand() % (max - min +1);
}
int numcartela; //variavel global


void printCartela(){
    int i;
    int j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 7; j++)
        {
            printf("%d", getCartela(i,j));
            if (j != 6){
                printf(" ");
            }
        } 
         printf("\n");
    }
}

void sorteioCartela(){
    int i;
    int linhaSorteada = gerarNumAlatorio(0, 2);
    int colunaSorteada = gerarNumAlatorio(0, 6);
    int numSorteado = getCartela(linhaSorteada, colunaSorteada);

    if(numcartela == numSorteado)
    {
        printf("Parabens, o seu número foi sorteado!\n");
    }
    else {
        printf("nao foi dessa vez :( \n");
        printf("o nuumero sorteado foi: %d\n", numSorteado);
        menuposlogin();
    }
}
void menuposlogin() {

    printMenuOptions2();
   
   
    scanf("%d", &op);
    getchar();
    
 
   switch (op) {
        case 1: 
            clearScreen();
            cadastrarlivro();
            break;
        case 2: 
            clearScreen();
            listarlivros();
            break;
        case 3:
            int idlivro;
            printf("Inform o id:\n");
            scanf("%d", &idlivro);
            excluirId(idlivro);
            menuposlogin();
            break;
        case 4:
           
            printf("informe a o id do livro:\n");
            scanf("%d", &idlivro);
            menuAlterar(idlivro);
            menuposlogin();
            break;
        case 5:
            printCartela();
            printf("Selecione um número presente na cartela para participar do sorteio de dois livros! \n"); 
            scanf("%d", &numcartela);
            sorteioCartela();
            break;
        case 6:
            printf("Obrigada pela Preferência!\n");
            exit(0);
            break;
        default:
            printf("opcao invalida\n");
        
    }
}


void clearScreen() //função para limpar a tela no linux e windows
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}