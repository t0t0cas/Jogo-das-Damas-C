#include <stdio.h>
#include <stdlib.h>

    int coli,lini,cd,ld, opcao=0, jogador=1;
    int tabuleiro[9][9] = { {' ','1','2','3','4','5','6','7','8'}, {'1','p','-','p','-','p','-','p','-'}, {'2','-','p','-','p','-','p','-','p'}, {'3','p','-','p','-','p','-','p','-'},{'4','-','-','-','-','-','-','-','-'},
                            {'5','-','-','-','-','-','-','-','-'}, {'6','-','b','-','b','-','b','-','b'}, {'7','b','-','b','-','b','-','b','-'}, {'8','-','b','-','b','-','b','-','b'}};

char jogador1[20] = {' '};
char jogador2[20] = {' '};
void imprimir_tab( int tabuleiro[9][9]){
    system("@cls||clear");
    int i = 0, j = 0;
    for (i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int regras_b(){
// brancas a mexer
   if(tabuleiro[lini][coli]=='b'){
        if((lini-ld)==1 && ((coli-cd)==1 || (coli-cd)==-1) && tabuleiro[ld][cd]=='-'){
            tabuleiro[ld][cd]='b';
            tabuleiro[lini][coli]='-';
            jogador=2;
        }
        else {
            printf("DESTINO ERRADO!");
            mover_pecas();
        }
   }
   else{
    printf("SELECIONE UMA PECA!");
    mover_pecas();
   }
}
int regras_p(){
    if(tabuleiro[lini][coli]=='p'){
        if((lini-ld)==-1 && ((coli-cd)==1 || (coli-cd)==-1) && tabuleiro[ld][cd]=='-'){
            tabuleiro[ld][cd]='p';
            tabuleiro[lini][coli]='-';
            jogador=1;
        }
        else {
            printf("DESTINO ERRADO!");
            mover_pecas();
        }
    }
    else{
        printf("SELECIONE UMA PECA!");
        mover_pecas();
    }
}
int comer_b(){
//jogador das brancas para comer as pretas
    if(tabuleiro[lini][coli]=='b' && tabuleiro[lini-1][coli+1]=='p' && tabuleiro[ld][cd]=='-' && tabuleiro[lini-2][coli+2]=='-'){
        if((lini-ld)==2 && (coli-cd)==-2){
            tabuleiro[ld][cd]='b';
            tabuleiro[lini][coli]='-';
            tabuleiro[lini-1][coli+1]='-';
            //verifica se após comer a peça adversária, a peca do jogador que comeu, pode comer outra vez. Se não puder passa para o jogador adversário
            if (tabuleiro[ld][cd]=='b' && tabuleiro[ld-1][cd+1]=='p' && tabuleiro[ld-2][cd+2]=='-' && tabuleiro[lini-4][coli+4]=='-')
            {

                jogador=1;

            }else if (tabuleiro[ld][cd]=='b' && tabuleiro[ld-1][cd-1]=='p' && tabuleiro[ld-2][cd-2]=='-' && tabuleiro[lini-4][coli]=='-')
            {
                jogador=1;
            }
            else
            {
                jogador=2;
            }
        }else{
            printf("OBRIGATORIO COMER PECA NA LINHA %d, COLUNA %d !\n",(lini-1),(coli+1));
            mover_pecas();
        }
    }else if(tabuleiro[lini][coli]=='b' && tabuleiro[lini-1][coli-1]=='p' && tabuleiro[ld][cd]=='-' && tabuleiro[lini-2][coli-2]=='-'){
       if((lini-ld)==2 && (coli-cd)==2){
            tabuleiro[ld][cd]='b';
            tabuleiro[lini][coli]='-';
            tabuleiro[lini-1][coli-1]='-';
           //verifica se após comer a peça adversária, a peca do jogador que comeu, pode comer outra vez. Se não puder passa para o jogador adversário
            if (tabuleiro[ld][cd]=='b' && tabuleiro[ld-1][cd-1]=='p' && tabuleiro[ld-2][cd-2]=='-' && tabuleiro[lini-4][coli-4]=='-')
            {

                jogador=1;

            }
            else if (tabuleiro[ld][cd]=='b' && tabuleiro[ld-1][cd+1]=='p' && tabuleiro[ld-2][cd+2]=='-' && tabuleiro[lini-4][coli]=='-')
            {
                jogador=1;
            }
            else
            {
                jogador=2;
            }
        }else{
            printf("OBRIGATORIO COMER PECA NA LINHA %d, COLUNA %d !\n",(lini-1),(coli-1));
            mover_pecas();
        }
    }else{
        regras_b();
    }
}

int comer_p(){
//jogador das pretas para comer as brancas
    if(tabuleiro[lini][coli]=='p' && tabuleiro[lini+1][coli+1]=='b' && tabuleiro[ld][cd]=='-' && tabuleiro[lini+2][coli+2]=='-'){
        if((lini-ld)==-2 && (coli-cd)==-2){
            tabuleiro[ld][cd]='p';
            tabuleiro[lini][coli]='-';
            tabuleiro[lini+1][coli+1]='-';
            //verifica se após comer a peça adversária, a peca do jogador que comeu, pode comer outra vez. Se não puder passa para o jogador adversário
            if(tabuleiro[ld][cd]=='p' && tabuleiro[ld+1][cd+1]=='b' && tabuleiro[ld+2][cd+2]=='-' && tabuleiro[lini+4][coli+4]=='-')
            {
                jogador=2;
            }else if(tabuleiro[ld][cd]=='p' && tabuleiro[ld+1][cd-1]=='b' && tabuleiro[ld+2][cd-2]=='-' && tabuleiro[lini+4][coli]=='-')
            {
                jogador=2;
            }
            else {
                jogador=1;
            }
        }else{
            printf("OBRIGATORIO COMER PECA NA LINHA %d, COLUNA %d !\n",(lini+1),(coli+1));
            mover_pecas();
        }
    }else if(tabuleiro[lini][coli]=='p' && tabuleiro[lini+1][coli-1]=='b' && tabuleiro[ld][cd]=='-' && tabuleiro[lini+2][coli-2]=='-' ){
        if((lini-ld)==-2 && (coli-cd)==2){
            tabuleiro[ld][cd]='p';
            tabuleiro[lini][coli]='-';
            tabuleiro[lini+1][coli-1]='-';
            //verifica se após comer a peça adversária, a peca do jogador que comeu, pode comer outra vez. Se não puder passa para o jogador adversário
            if(tabuleiro[ld][cd]=='p' && tabuleiro[ld+1][cd-1]=='b' && tabuleiro[ld+2][cd-2]=='-' && tabuleiro[lini+4][coli-4]=='-')
            {
                jogador=2;
            }else if(tabuleiro[ld][cd]=='p' && tabuleiro[ld+1][cd+1]=='b' && tabuleiro[ld+2][cd+2]=='-' && tabuleiro[lini+4][coli]=='-')
            {
                jogador=2;
            }
            else
            {
                jogador=1;
            }
        }else{
            printf("OBRIGATORIO COMER PECA NA LINHA %d, COLUNA %d !\n",(lini+1),(coli-1));
            mover_pecas();
        }
    }else{
        regras_p();
    }
}

int move_damabr(){
        int i;
        if(tabuleiro[lini][coli] == 'B'){
        if(abs(lini-ld) == abs(coli-cd)){
            for (i = 1; i <= abs(coli-cd); i++){
                 if(analisa_moveD(lini,coli,lini+i,coli+i) == 1)
                 {

                 }
                 else {
                    tabuleiro[lini+i+1][coli+i+1] = 'B';
                     tabuleiro[lini+i][coli+i] = '-';
                     tabuleiro[lini][coli] = '-';
                     imprimir_tab(tabuleiro);
                     jogador == 2;
                    }
            }
        }
    }
    mover_pecas();
}

int move_damapr(){
        int i;
        if(tabuleiro[lini][coli] == 'P'){
        if(abs(lini-ld) == abs(coli-cd)){
            for (i = 0; i < abs(coli-cd); i++){
                 if(analisa_moveD(lini,coli,lini+i,coli+i) == 0)
                 {
                     tabuleiro[lini+i][coli+i] = 'P';
                     tabuleiro[lini][coli] = '-';
                     tabuleiro[lini][coli] = '-';
                     imprimir_tab(tabuleiro);
                     jogador == 1;
                 }
                 else{
                 }
            }
        }
    }
    mover_pecas();
}


int analisa_moveD(int lini , int coli , int ld , int cd)//funcao que analisa o movimento das damas
{
        if(tabuleiro[ld][cd] == 'b' || tabuleiro[ld][cd] == 'B'){
                return 1;
        }else if(tabuleiro[ld][cd] == 'p' || tabuleiro[ld][cd] == 'P'){
                return 1;
            }else return 0;
}

void mover_pecas(){
    //inicializa a variável contagem para ser usada como contadora das peças que estão no tabuleiro
    int cont = 0;
   while(cont==0){
       if(jogador==1)//mostra no tabuleiro qual é o jogador que vai jogar
             printf("%s \n", jogador1);
        else  printf("%s \n", jogador2);

        printf("Qual peca que deseja mover:\n");
        printf("Linha:\n");
        scanf("%d", &lini);
        printf("Coluna:\n");
        scanf("%d", &coli);
        printf("Para onde a deseja mover:\n");
        printf("Linha:\n");
        scanf("%d", &ld);
        printf("Coluna:\n");
        scanf("%d", &cd);
        if(jogador==1){
            comer_b();
            if(tabuleiro[ld][0] == '1')
                {
                //verifica se a peça branca chega ao fim do tabuleiro, e se sim torna-a em dama
                    tabuleiro[ld][cd] = 'B';
                    tabuleiro[lini][coli] = '-';
                    jogador = 2;

              }
                if(tabuleiro[lini][coli] == 'B'){
                //verifica se a peça branca chega ao fim do tabuleiro, e se sim torna-a em dama
                    move_damabr();
                    jogador = 2;

              }
        }
        else{
            comer_p();
            if(tabuleiro[ld][0] == '8'){
                //verifica se a peça preta chega ao fim do tabuleiro, e se sim torna-a em dama
                    tabuleiro[ld][cd] = 'P';
                    tabuleiro[lini][coli] = '-';
                    move_damapr();
                    jogador = 1;
               }if(tabuleiro[lini][coli] == 'P'){
                    move_damapr();
                    jogador = 1;
               }
        }
        //contador inicializado para o verifica peças de modo a ver se existem peças no tabuleiro e se sim continua a jogar
        cont = verifica_pecas();
        if(cont==1){
            imprimir_tab(tabuleiro);
            printf("\n O jogador 1 ganhou");
        }else if(cont==2){
            imprimir_tab(tabuleiro);
            printf("\n O jogador 2 ganhou");
        }else
        imprimir_tab(tabuleiro);
    }
}
int verifica_pecas(){
   int p1=0;
   int p2=0;
   int tam = 9;
    int i = 0, j = 0;
    for (i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(tabuleiro[i][j] == 'b') p1++;
            else if(tabuleiro[i][j] == 'p') p2++;
        }
    }
    //verifica as peças de cada jogador para saber quem ganhou
    if(p1==0){
        return 2;
    }
    if(p2==0){
        return 1;
    }
    else return 0;
}

void desenha_menu(){
        printf("\t___________________________________\n");
        printf("\t__________                 ________\n");
        printf("\t__________ Jogo das Damas  ________\n");
        printf("\t___________________________________\n");
        printf("\t###################################\n");
        printf("\t_________1. Comecar o jogo ________\n");
        printf("\t###################################\n");
        printf("\t__2. Informacoes sobre o jogo _____\n");
        printf("\t###################################\n");
        printf("\t__________3. Criadores ____________\n");
        printf("\t###################################\n");
        printf("\t__________ 4. Sair ________________\n");
        scanf("%d", &opcao);
        system("@cls||clear");
        switch(opcao){
        case 1:
                printf("AS BRANCAS JOGAM PRIMEIRO!\n");
                printf("Introduza o nome do jogador 1 (brancas): \n");
                scanf("%s", &jogador1);
                printf("Introduza o nome do jogador 2 (pretas): \n");
                scanf("%s", &jogador2);
                system("@cls||clear");
                imprimir_tab(tabuleiro);
                mover_pecas();
            break;
            case 2:
                system("@cls||clear");
                printf("\t____ O QUE E O JOGO DAS DAMAS____ \n");
                printf("O jogo das Damas e um jogo entre dois jogadores, em que cada jogador\n tem 12 pecas brancas e pretas num tabuleiro de 64 casas");
                printf("alternadas entre casas\n claras e escuras. Cada jogador coloca as suas pecas nas casas escuras. O jogo\n decorre alternadamente");
                printf("entre os dois jogadores, enquanto um deles tiver as pecas sobre o tabuleiro. \n");
                printf("\t____ Objetivo____ \n");
                printf("O objetivo deste jogo e comer as peças do adversario de modo a que cheguemos ao outro lado do tabuleiro e possamos fazer a dama.");
            break;
            case 3:
                system("@cls||clear");
                printf("\t___CRIADORES___ \n");
                printf("Antonio Fialho - n.21895\n");
                printf("Luis Vieira - n.22100");
            break;
            case 4:
                system("@cls||clear");
                printf("\t____FIM DO JOGO____\n");
            break;
            default: desenha_menu();
            break;
        }
}

int main()
{
    desenha_menu();
}
