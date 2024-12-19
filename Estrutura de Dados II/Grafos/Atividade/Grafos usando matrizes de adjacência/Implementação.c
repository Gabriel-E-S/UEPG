//  Atividade de  grafos usando matrizes de adjascência Gabriel E.S    //
//  Disciplina de Estrutura de Dados II                                                                    //
/////////////////////////////////////////////////////////////////////////


// bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#endif

//////////////////////////////////////////////////////
//        PARTE GRÁFICA                             //
//////////////////////////////////////////////////////

// Função para mover o cursor para uma posição específica (gotoxy)
void gotoxy(int linha, int coluna) {
    #ifdef _WIN32
        // Versão para Windows usando a API de console
        COORD pos;
        pos.X = coluna - 1;  // Ajuste para base zero
        pos.Y = linha - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    #else
        // Versão para Linux usando ANSI escape codes
        printf("\033[*;*H", linha, coluna);
    #endif
}

//COR TEXTO

enum {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
    DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

enum {
    _BLACK = 0, _BLUE = 16, _GREEN = 32, _CYAN = 48, _RED = 64, 
    _MAGENTA = 80, _BROWN = 96, _LIGHTGRAY = 112, _DARKGRAY = 128, 
    _LIGHTBLUE = 144, _LIGHTGREEN = 160, _LIGHTCYAN = 176, 
    _LIGHTRED = 192, _LIGHTMAGENTA = 208, _YELLOW = 224, _WHITE = 240
};


// Função para pausar o programa até que o usuário pressione Enter (pause)
void pause() {
    #ifdef _WIN32
        // Versão para Windows
        system("pause");
    #else
        // Versão para Linux
        printf("Pressione Enter para continuar...");
        getchar();
    #endif
}


/ Função para definir a cor do texto e do fundo
void cortexto(int letras, int fundo) {
    #ifdef _WIN32
        // Windows: usa SetConsoleTextAttribute
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
    #else
        // Linux: usa ANSI escape codes
        int text_color = letras;
        int background_color = (fundo / 16) + 40;  // Divide por 16 para alinhar com ANSI e adiciona 40 para fundo

        printf("\033[%d;%dm", background_color, text_color + 30);
    #endif
}

void resetarCores() {
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    #else
        printf("\033[0m");  // Reseta para a cor padrão no Linux
    #endif
}

// procedimento que imprime colunas

void collumn(int lin1,int lin2,int col1){

    setlocale(LC_ALL,"C");
    int i,j;

    for(i=lin1;i<=lin2;i++){ //fazendo as linhas
        gotoxy(i,col1);
        printf("%c",179);
        }

    setlocale(LC_ALL,"");
}

// procedimento que imprime linhas

void line(int col1,int col2,int lin1){

    setlocale(LC_ALL,"C");
    int i,j;

    for(i=col1;i<=col2;i++){ //fazendo as linhas
        gotoxy(lin1,i);
        printf("%c",196);
        }

    setlocale(LC_ALL,"");
}

//função para criar uma caixa ao redor do menu

void box(int lin1,int col1, int lin2,int col2){


    int i,j;

    line(col1,col2,lin1);
    line(col1,col2,lin2);
    collumn(lin1,lin2,col1);
    collumn(lin1,lin2,col2);

    setlocale(LC_ALL,"C");

    for(i=lin1+1;i<lin2;i++){ //preenchendo
        for(j=col1+1;j<col2;j++){
            gotoxy(i,j);printf(" ");
        }
    }

    //colocando os cantos;
    gotoxy(lin1,col1);
    printf("%c",218);
    gotoxy(lin1,col2);
    printf("%c",191);
    gotoxy(lin2,col1);
    printf("%c",192);
    gotoxy(lin2,col2);
    printf("%c",217);
    setlocale(LC_ALL,"");
}

int MENUPRINCIPAL(int lin1,int col1,int qtd,char lista[][100]){
    int opc = 1, lin2,col2, linha,i, tamMAXitem,tecla;

    //nessa parte é verificado qual das frases é maior
    tamMAXitem = strlen(lista[0]);

    for(i=1;i<qtd;i++){
        if(strlen(lista[i]) > tamMAXitem){
            tamMAXitem = strlen(lista[i]);
        }
    }
    lin2 = lin1+(qtd*2+2);
    col2 = col1 + tamMAXitem+4;

    cortexto(WHITE,_BLUE);
    setlocale(  LC_ALL,"C");
    box(lin1,col1,lin2,col2);
    setlocale(LC_ALL,"");

    while(1){

        linha = lin1 + 2;

        for(i=0;i<qtd;i++){
            if(i+1 == opc){
                cortexto(BLACK,_LIGHTGREEN); //se a opção for igual ao i a cor do texto fica diferente
            }
            else{
                cortexto(WHITE,_BLUE);
            }
        gotoxy(linha,col1+2);
        printf("%s",lista[i]);
        linha +=2;
        }
        //vendo as teclas
        gotoxy(1,1);
        tecla = getch();
        gotoxy(30,1);
        //printf("Tecla: %d",tecla);

        //teclas


        if(tecla ==27){ //ESC
            opc=0;
            break;
        }
        if(tecla == 13){ //ENTER
            break;
        }

        if(tecla==72){ //setinha pra baixo
            if(opc>1)
                opc--;
        }
        if(tecla==80){ //setinha pra cima
            if(opc<qtd)
                opc++;
        }
    }
    cortexto(WHITE,_BLACK);
    return opc;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////



#define N 6     // Tamanho máximo do grafo


int vetorVertices[N], matrizAdj[N][N], tamanhoAtual = 0;    // Variáveis globais
                                                            // Um contador de elementos, um vetor contendo os vértices e
                                                            // uma matriz de adjascência desses vértices.

// Procedimento que inicializa a matriz de adjascência e o vetor de vértices.

void inicializarMatrizAdj(){

    int i, j;

    for(i=0;i<N;i++){
        vetorVertices[i] = -1;
        for(j=0;j<N;j++){
            matrizAdj[i][j] = 0;
        }
    }
}

// Função que consulta se um vértice está no vetor de vértices.

int verificarExistencia(int valor){
    int i;

    for(i=0;i<N;i++){
        if(vetorVertices[i] == valor){  // Busca sequencial simples retornando o índice do elemento quando encontrado.
            return i;
        }
    }
    return -1;                          // Quando o elemento não existe retorna -1, pois -1 não pode ser nenhum índice.
}

// Procedimento que insere um vértice no grafo

void insereVertice(int valor){

    if(tamanhoAtual < N && verificarExistencia(valor) == -1){ // Se ainda houver espaço no vetor e valor não existir nele o
        vetorVertices[tamanhoAtual] = valor ;                 // elemento é inserido e o tamanho atualizado.
        tamanhoAtual+=1 ;

        gotoxy(19,4);   printf("VÉRTICE %d ADICIONADO",valor);

    }else{
        gotoxy(19,4);   printf("NÃO FOI POSSÍVEL INSERIR O VALOR");
    }
}

// Procedimento que insere um vértice dando uma origem e um destino

void insereAresta(int origem, int destino){

    int valor1 = verificarExistencia(origem) ;      // Verificamos se os vértices existem.
    int valor2 = verificarExistencia(destino) ;

    if( valor1 != -1 && valor2 != -1 ){             // Se ambos existirem criamos a aresta na matriz.
        matrizAdj[valor1][valor2] = 1 ;
        gotoxy(21,4);printf("ARESTA INSERIDA COM SUCESSO!");
    }
    else{
        if(valor1 == -1){
            gotoxy(19,4);   printf("O VÉRTICE DE ORIGEM NÃO EXISTE");   // Caso contrário mostra-se a mensagem de erro e o motivo.
        }
        if(valor2 == -1){
            gotoxy(20,4);   printf("O VÉRTICE DE DESTINO NÃO EXISTE");
        }
    }
}

// Procedimento que remove uma aresta dada uma origem e um destino

void removeAresta(int origem, int destino){

     int valor1 = verificarExistencia(origem) ;     // Verificamos se os vértices existem.
    int valor2 = verificarExistencia(destino) ;

    if( valor1 != -1 && valor2 != -1 ){             // Se ambos existirem criamos a aresta na matriz.
        matrizAdj[valor1][valor2] = 0 ;
        gotoxy(21,4);   printf("ARESTA REMOVIDA COM SUCESSO!");
    }
    else{
        if(valor1 == -1){
            gotoxy(21,4);   printf("O VÉRTICE DE ORIGEM NÃO EXISTE");   // Caso contrário mostra-se a mensagem de erro e o motivo.
        }
        if(valor2 == -1){
            gotoxy(22,4);   printf("O VÉRTICE DE DESTINO NÃO EXISTE");
        }
    }
}

// Procedimento que verifica se uma aresta existe no grafo.

void haAresta(int origem, int destino){

    int valor1 = verificarExistencia(origem) ;      // Mesmo procedimento anterior
    int valor2 = verificarExistencia(destino) ;

    if( valor1 != -1 && valor2 != -1 ){
        if(matrizAdj[valor1][valor2] == 1){
            gotoxy(23,4);   printf("A ARESTA ENTRE %d e %d EXISTE",origem,destino);
        }
        else{
            gotoxy(23,4);   printf("A ARESTA ENTRE %d e %d NÃO EXISTE",origem,destino);
        }
    }
    else{
        if(valor1 == -1){
            gotoxy(23,4);   printf("O VÉRTICE DE ORIGEM NÃO EXISTE");
        }
        if(valor2 == -1){
            gotoxy(24,4);   printf("O VÉRTICE DE DESTINO NÃO EXISTE");
        }
    }
}

// Procedimento que imprime uma matriz

void imprimeMatrizAd(){

    int i, j;

    gotoxy(18,4); printf("MATRIZ DE ADJASCÊNCIA");

    int linha = 22; // os gotoxy podem assustar a principio, mas eles somente servem para posicionar o cursor corretamente.

    for(i=0;i<tamanhoAtual;i++){
        int coluna = 6;
        gotoxy(linha,coluna-3);printf("%d |",vetorVertices[i]);
        for(j=0;j<tamanhoAtual;j++){
            gotoxy(linha,coluna+2);printf("%d ",matrizAdj[i][j]);
            gotoxy(20,coluna+2);printf("%d ",vetorVertices[j]);
            gotoxy(21,coluna+1);printf("---",vetorVertices[j]);
            coluna+=3;
        }
        linha += 1;
    }
}

// Procedimento que imprime todas as arestas que estão saindo de um vértice.

void imprimeArestas(int linha){

    int i;

    int coluna = 36;

    for(i=0;i<N;i++){
        if(matrizAdj[linha][i] != 0){
            gotoxy(21+linha,coluna);   printf("<%d,%d> ",vetorVertices[linha],vetorVertices[i]);
            coluna+= 7;
        }
    }
}

// Procedimento que imprime o grafo usando o procedimento anterior.

void imprimeGrafo(){

    int i;

    if(tamanhoAtual > 0){

        imprimeMatrizAd();  // Imprimimos a matriz.

        gotoxy(18,30); printf("GRAFO ATUAL");   // E em seguida o gráfico.

        for(i=0;i<tamanhoAtual;i++){
            gotoxy(21+i,30);printf("%d -> ",vetorVertices[i]);
            imprimeArestas(i);
            printf("\n");
        }
    }
    printf("\n\n\n\n   "); pause();  // O comando system("pause") pausa a execução do programa até uma tecla ser pressionada.
}

// Procedimento para imprimir uma arte ascii.

void arteAscii(int linha, int coluna) {
    gotoxy(linha, coluna);  printf("  ____            __                                               \n");
    gotoxy(linha + 1, coluna);  printf(" / ___|_ __ __ _ / _| ___  ___                                     \n");
    gotoxy(linha + 2, coluna);  printf("| |  _| '__/ _` | |_ / _ \\/ __|                                    \n");
    gotoxy(linha + 3, coluna);  printf("| |_| | | | (_| |  _| (_) \\__ \\                                    \n");
    gotoxy(linha + 4, coluna);  printf(" \\____|_|  \\__,_|_|  \\___/|___/                _                   \n");
    gotoxy(linha + 5, coluna);  printf("  __| (_)_ __ ___  ___(_) ___  _ __   __ _  __| | ___  ___         \n");
    gotoxy(linha + 6, coluna);  printf(" / _` | | '__/ _ \\/ __| |/ _ \\| '_ \\ / _` |/ _` |/ _ \\/ __|        \n");
    gotoxy(linha + 7, coluna);  printf("| (_| | | | |  __/ (__| | (_) | | | | (_| | (_| | (_) \\__ \\        \n");
    gotoxy(linha + 8, coluna);  printf(" \\__,_|_|_|  \\___|\\___|_|\\___/|_| |_|\\__,_|\\__,_|\\___/|___/ _      \n");
    gotoxy(linha + 9, coluna);  printf("  ___ ___  _ __ ___    _ __ ___   __ _| |_ _ __(_)____   __| | ___ \n");
    gotoxy(linha + 10, coluna); printf(" / __/ _ \\| '_ ` _ \\  | '_ ` _ \\ / _` | __| '__| |_  /  / _` |/ _ \\\n");
    gotoxy(linha + 11, coluna); printf("| (_| (_) | | | | | | | | | | | | (_| | |_| |  | |/ /  | (_| |  __/\n");
    gotoxy(linha + 12, coluna); printf(" \\___\\___/|_| |_| |_| |_| |_| |//\\__,_|\\__|_|  |_|/___|  \\__,_|\\___|\n");
    gotoxy(linha + 13, coluna); printf("  __ _  __| |(_) __ _ ___  ___|/_\\|_ __   ___(_) __ _              \n");
    gotoxy(linha + 14, coluna); printf(" / _` |/ _` || |/ _` / __|/ __/ _ \\ '_ \\ / __| |/ _` |             \n");
    gotoxy(linha + 15, coluna); printf("| (_| | (_| || | (_| \\__ \\ (_|  __/ | | | (__| | (_| |             \n");
    gotoxy(linha + 16, coluna); printf(" \\__,_|\\__,_|/ |\\__,_|___/\\___\\___|_| |_|\\___|_|\\__,_|             \n");
    gotoxy(linha + 17, coluna); printf("           |__/                                                    \n");
}

// Procedimento do menu.

void menu(){

    char matopcs[5][100] = {"INSERIR VÉRTICE","INSERIR ARESTA","REMOVER ARESTA","VERIFICAR EXISTÊNCIA DE ARESTA","IMPRIMIR GRAFO"};

    int opc = 1;
    inicializarMatrizAdj();

    while(opc != 0){

        cls();
        arteAscii(1,50);
        opc = MENUPRINCIPAL(2,3,5,matopcs);
         gotoxy(15,5);

        switch(opc){
            case 1:{
                int valor;

                gotoxy(17,4);   printf("DIGITE O VALOR PARA INSERIR COMO VÉRTICE: ");
                scanf("%d",&valor);

                while(getchar()!='\n'); // Para limpar o buffer do teclado.

                insereVertice(valor);

                break;
            }
            case 2:{
                int valor,valor2;

                gotoxy(17,4);   printf("DIGITE O VÉRTICE DE ORIGEM: ");
                scanf("%d",&valor);

                while(getchar()!='\n');

                gotoxy(19,4);   printf("DIGITE O VÉRTICE DE DESTINO: ");
                scanf("%d",&valor2);

                while(getchar()!='\n');

                insereAresta(valor,valor2);

                break;
            }
            case 3:{
                 int valor,valor2;

                gotoxy(17,4);   printf("DIGITE O VÉRTICE DE ORIGEM DA REMOÇÃO: ");
                scanf("%d",&valor);

                while(getchar()!='\n');

                gotoxy(19,4);   printf("DIGITE O VÉRTICE DE DESTINO DA REMOÇÃO: ");
                scanf("%d",&valor2);

                while(getchar()!='\n');

                removeAresta(valor,valor2);

                break;
            }
            case 4:{
                int valor,valor2;

                gotoxy(17,4);   printf("VERIFICAR EXISTÊNCIA");

                gotoxy(19,4);   printf("DIGITE O VÉRTICE DE ORIGEM: ");
                scanf("%d",&valor);

                while(getchar()!='\n');

                gotoxy(21,4);   printf("DIGITE O VÉRTICE DE DESTINO: ");
                scanf("%d",&valor2);

                while(getchar()!='\n');

                haAresta(valor,valor2);


                break;
            }
            case 5:{
                imprimeGrafo();
                break;
            }
        }
        Sleep(1500);    // O comando Sleep pausa o programa em um tempo em ms.
    }
}

// Procedimento main.

int main(){

    setlocale(LC_ALL,"Portuguese");

    menu();

    return 0;

}
