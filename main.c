#include <stdio.h>
#include <stdlib.h>
#define SIZE_PLAYGROUD 100

typedef struct antWatch{

    int startX;
    int startY;
    char direction;

} antWatch;


void initializePlayground(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD]);
void printPlayground(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD], antWatch antPosi);
void moveAnt(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD], antWatch * antPosi, int turns);


int main()
{
    char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD];
    int turns = 0;
    antWatch antPosi;
    antPosi.direction = 'W';

    printf("Number of turns: ");
    scanf("%d", &turns);

    printf("Start position: ");
    scanf("%d %d", &antPosi.startY, &antPosi.startX);

    initializePlayground(playground);
    moveAnt(playground, &antPosi, turns);





    printPlayground(playground, antPosi);

    return 0;
}

void initializePlayground(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD]){

        for(int i = 0; i < SIZE_PLAYGROUD; i++){
            for(int k = 0; k < SIZE_PLAYGROUD; k++){
                playground[i][k] = '.';
            }
        }
}

void printPlayground(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD], antWatch antPosi){

    if(antPosi.startX >= 0 && antPosi.startX < SIZE_PLAYGROUD && antPosi.startY >= 0 && antPosi.startY < SIZE_PLAYGROUD) {
        if(playground[antPosi.startX][antPosi.startY] == '.') {
            playground[antPosi.startX][antPosi.startY] = 'a';
        } else if(playground[antPosi.startX][antPosi.startY] == '#') {
            playground[antPosi.startX][antPosi.startY] = 'A';
        }
    }


    for(int i = 0; i < SIZE_PLAYGROUD; i++){
        for(int k = 0; k < SIZE_PLAYGROUD; k++){
            printf("%c", playground[i][k]);
        }
        printf("\n");
    }
}

void moveAnt(char playground[SIZE_PLAYGROUD][SIZE_PLAYGROUD], antWatch * antPosi, int turns){

    while(turns > 0){
        if(antPosi->startX >= 0 && antPosi->startX < SIZE_PLAYGROUD && antPosi->startY >= 0 && antPosi->startY < SIZE_PLAYGROUD){
            if(playground[antPosi->startX][antPosi->startY] == '.'){
                if(antPosi->direction == 'W'){
                    playground[antPosi->startX][antPosi->startY] = '#';
                    antPosi->direction = 'N';
                    antPosi->startX--;
                    turns--;
                }else if(antPosi->direction == 'N'){
                    playground[antPosi->startX][antPosi->startY] = '#';
                    antPosi->direction = 'E';
                    antPosi->startY++;
                    turns--;
                }else if(antPosi->direction == 'E'){
                    playground[antPosi->startX][antPosi->startY] = '#';
                    antPosi->direction = 'S';
                    antPosi->startX++;
                    turns--;
                }else if(antPosi->direction == 'S'){
                    playground[antPosi->startX][antPosi->startY] = '#';
                    antPosi->direction = 'W';
                    antPosi->startY--;
                    turns--;
                }
            }else if(playground[antPosi->startX][antPosi->startY] == '#'){
                if(antPosi->direction == 'W'){
                    playground[antPosi->startX][antPosi->startY] = '.';
                    antPosi->direction = 'S';
                    antPosi->startX++;
                    turns--;
                }else if(antPosi->direction == 'S'){
                    playground[antPosi->startX][antPosi->startY] = '.';
                    antPosi->direction = 'E';
                    antPosi->startY++;
                    turns--;
                }else if(antPosi->direction == 'E'){
                    playground[antPosi->startX][antPosi->startY] = '.';
                    antPosi->direction = 'N';
                    antPosi->startX--;
                    turns--;
                }else if(antPosi->direction == 'N'){
                    playground[antPosi->startX][antPosi->startY] = '.';
                    antPosi->direction = 'W';
                    antPosi->startY--;
                    turns--;
                }
            }
        }else{
            break;
        }
    }
}
