#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <windows.h>

void gotoxy(int lin, int col) {
    COORD coord;
    coord.X = col - 1;
    coord.Y = lin - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);

}

//COR TEXTO

enum{
    BLACK,          //0
    BLUE,           //1
    GREEN,          //2
    CYAN,           //3
    RED,            //4
    MAGENTA,        //5
    BROWN,          //6
    LIGHTGRAY,      //7
    DARKGRAY,       //8
    LIGHTBLUE,      //9
    LIGHTGREEN,     //10
    LIGHTCYAN,      //11
    LIGHTRED,       //12
    LIGHTMAGENTA,   //13
    YELLOW,         //14
    WHITE           //15
};
//COR FUNDO
enum{
    _BLACK=0,          //0
    _BLUE=16,           //1
    _GREEN=32,          //2
    _CYAN=46,           //3
    _RED=64,            //4
    _MAGENTA=80,        //5
    _BROWN=96,          //6
    _LIGHTGRAY=112,      //7
    _DARKGRAY=128,       //8
    _LIGHTBLUE=144,      //9
    _LIGHTGREEN=160,     //10
    _LIGHTCYAN=176,      //11
    _LIGHTRED=192,       //12
    _LIGHTMAGENTA=208,   //13
    _YELLOW=224,         //14
    _WHITE=240           //15
};

//função para mudar a cor do texto

void cortexto(int letras, int fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),letras+fundo);
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


void table(int lin1,int lin2,int col1,int col2){

    cortexto(LIGHTBLUE,_BLUE);


    int i;

    box(lin1,col1,lin2,col2);

    for(i=lin1+2;i<=lin2-2;i+=2){
        line(col1+1,col2-1,i);
    }
        for(i=col1+16;i<=col2-1;i+=16){
        collumn(lin1+1,lin2-1,i);
    }

    cortexto(WHITE,_BLACK);

}


int main(){


    int tamlinha, tamcoluna ;

    while(1){

        system("cls");
        printf("DIGITE O NUMERO DE LINHAS, DIGITE -1 PARA SAIR -->");
        scanf("%d",&tamlinha);
        
        if(tamlinha == -1){
        	break;
		}

        printf("DIGITE O NUMERO DE COLUNAS MAX 10 -->");
        scanf("%d",&tamcoluna);

        if(tamcoluna > 10){
            continue;
        }

        table(12,12+2*tamlinha,4,4+tamcoluna*16);
        printf("\n\n\n\n\n\n\n");system("pause");
    }

	return 0 ;
}
