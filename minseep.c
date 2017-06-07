/*  マインスイーパ  */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3
#define boms 2

/*
・ map = 0 " "
・ 1 <= map <= 8 countbombs 
・ map = 9 "*"
・ map = 10 bombs
*/

int map[N+1][N+1];



void makeMaps(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            map[i][j] = 9;
        }
    }
    return;
}



void showMaps(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j] > 0 && map[i][j] < 9){
                printf("%d",map[i][j]);
            }else if(map[i][j] == 0){
                printf(" ");
            }
           /* else if(map[i][j]==10){
                printf("b");
            }*/
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
    return ;
    
}

void openMaps(){
    int i,j,n;
    scanf("%d%d",&i,&j);
    if(map[i][j] == 10){
	    map[i][j] = 11;
          }else{
        n = countBoms(i,j,map);
        map[i][j] = n;
    }
    return;
}

int  countBoms(int i,int j){
    int n;
    n = 0;
    if(map[i+1][j] == 10) n++;
    if(map[i+1][j-1] == 10) n++;
    if(map[i][j-1] == 10)  n++;
    if(map[i-1][j-1] == 10) n++;
    if(map[i-1][j] == 10)  n++;
    if(map[i-1][j+1] == 10) n++;
    if(map[i][j+1] == 10)  n++;
    if(map[i+1][j+1] == 10) n++;

    return n;
}

int stop(void){
     int i,j,count;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j] > 0 && map[i][j] < N){
                count++;
            }else if(map[i][j]==11){
		    printf("game over");
		    exit(-1);
	    }
        }
    }
    if(count ==N*N-boms){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    int i,j,k,n;
    
    makeMaps();
    srand((unsigned)time(NULL));
    for(k = 0;k < boms;k++){
        i = rand() % N;
        j = rand() % N;
        map[i][j] = 10;
    }
    while(stop()){
        showMaps();
        openMaps();
	n++;
    }
    return 0;
}

