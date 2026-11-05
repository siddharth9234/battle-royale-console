#include <stdio.h>
#include  <stdlib.h>
#include <time.h>
#include <string.h>
int play(){
    srand(time(NULL));
    int g1=1,g2=500,a=0;
    /*    g1=rand()%(100-1+1)+1;    g2=rand()%(100-1+1)+1; */
    struct details{
        int id;
        int no;
    };

    struct details user[59];
    for(int i=0;i<49;i++){
        user[i].id=(rand()%(99999-10000+1)+10000);
    }
    int count=50;
    printf("\nEnter your user id:");
    scanf("%d",&user[49].id);
  //  for(int i=0;i<50;i++) printf("%d\n",user[i].id);
    while(count>1){
        printf("\e[1;1H\e[2J");
        count=0;
    //    if(count<=1) break;
        
        for(int i=0;i<49;i++){
            if(user[i].id==0) continue;
            else user[i].no=(rand()%(500-1+1)+1);
        }

        g1=rand()%(g2-g1+1)+g1;
        g2=rand()%(g2-g1+1)+g1;
        
        if(user[49].id!=0){
            printf("\nEnter your choice:");
            scanf("%d",&user[49].no);
            printf("\nPrevious Range:%d-%d\n",g1,g2);
        }

        

        if(g1>g2){
            int temp=g1;
            g1=g2;
            g2=temp;
        }
   //   printf("%d %d\n",g1,g2);
        for(int i=0;i<50;i++){
            if((user[i].no<g1 || user[i].no>g2) && user[i].id!=0){
                printf("%d eliminated ",user[i].id);
                user[i].id=0;
            }
        }

        for(int i=0;i<50;i++){
            if(user[i].id!=0) count++;
        }
    }
    for(int i=0;i<50;i++){
        if(user[i].id==0) a++;
    }
    if(a==50) printf("\nEveroyne eleminated!!\nBOOYAH");
    else if(user[49].id==0){
        printf("\nYou lose!!\n");
        for(int i=0;i<50;i++){
            if(user[i].id!=0){
                printf("%d WINS!! Choice-%d",user[i].id,user[i].no);
            }
        }
    }
    else if(user[49].id!=0) printf("You wins!!\nBOOYAH");}int main(){
    printf("Welcome to the multiplayer guessing game\nIn this game you have to  guess a number and then other users will also guess a number and a range will be chosen by bot if number is in the range we woll go for round 2\nTo play game again enter 'y'\n");
    char lp;
    do{
        play();
        printf("\nWant to play again??");
        scanf(" %c",&lp);
    }while(lp=='y');
    printf("BYE!!");
}