

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct player
{
    char name[20];
    char x;
    char spot;
};

char mat[3][3];
char tab[9]={'1','2','3','4','5','6','7','8','9'};

void remplir()
{
    char l = '1';
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            mat[i][j]=l;
            l++;
        }
    };
}

void affichage()
{
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            printf("%c \t ",mat[i][j]);
        }
        printf("\n \n");
    }
}

int finish(char mat[3][3])
{
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j]!='x' && mat[i][j]!='o')
            {
                return 0;
            }
        }
    }
    return 1;
}


int check(char mat[3][3],char x)
{
     for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j]==x)
            {
                return 1;
            }
        }
    }
    return 0 ;
}

int checkd(char mat[3][3],char x,char o)
{
     for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j]==x)
            {
                return 1;
            }
        }
    }
    int n=x-48;
    int t=0;
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            t++;
            if(t==n)
            {
                if(mat[i][j]==o)
                {
                    return 0;
                }
            }
        }
    };
    return -1;

}

void ajout(char x,char n)
{
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j]==n)
            {
                mat[i][j]=x;
            }
        }
    }
}


int winner(char mat[3][3])
{
    int j=0,res=0;

    if(mat[0][2]==mat[1][1]&&mat[0][2]==mat[2][0])
    {
        res=1;
    }
    for(int i =0;i<3;i++)
    {
        if((mat[i][j]==mat[i][j+1]&&mat[i][j]==mat[i][j+2]) || (mat[j][i]==mat[j+1][i]&&mat[j][i]==mat[j+2][i]) || (mat[j][j]==mat[j+1][j+1] && mat[j][j]==mat[j+2][j+2]))
        {
            res=1;
        }

    };

    return res;
}

void multijoueur(int m)
{
    struct player player1;
    struct player player2;
    printf("first player what's your name \n");
    scanf("%s",&player1.name);
    do{
        printf("X or O");
        scanf("%c",&player1.x);
    }while(player1.x!='x' && player1.x!='o');
    if(m==1)
    {
        printf("second player what's your name \n");
        scanf("%s",&player2.name);
    }
    if(player1.x=='x')
    {
        player2.x='o';
    }
    else if(player1.x=='o')
    {
        player2.x='x';
    };
    int turn=1;
    int c;
    c=finish(mat);
    int t =1;
    int k,win=0;
    while(c!=1&&win==0)
    {
        if(t%2!=0)
        {


            do
            {

                printf("%s it's your turn choose an empty spot from 1 to 9 : ",player1.name);
                scanf("%c",&player1.spot);
                k=check(mat,player1.spot);
                printf("%c \n",player1.spot);
                printf("%d \n",k);
            }while(k==0);
            ajout(player1.x,player1.spot);
            system("cls");
            affichage();
            win=winner(mat);
            printf("%d \n",win);
            if(win==1)
            {
                printf("we got a winner congratulations %s you won ",player1.name);
            }

        else
        {
            if(m==1)
            {
            do
            {

                printf("%s it's your turn choose an empty spot from 1 to 9 : ",player2.name);
                scanf("%c",&player2.spot);
                k=check(mat,player2.spot);
            }while(k==0);
            ajout(player2.x,player2.spot);
            system("cls");
            affichage();
            win=winner(mat);
            printf("%d \n",win);
            if(win==1)
            {
                printf("we got a winner congratulations %s you won ",player2.name);
            }
        }
        else if(m==2)
        {
            srand(time(0));
            do{
            player2.spot=(rand()%8+49);
            k=check(mat,player2.spot);
            printf("%c \n",player2.spot);
            }while(k==0);
            ajout(player2.x,player2.spot);
            system("cls");
            affichage();
            win=winner(mat);
            printf("%d \n",win);
            if(win==1)
            {
                printf("you lost in the easy mode!!",player1.name);
            }

        }

    }

    }
    c=finish(mat);
    t++;

}
if(c==1 && win ==0)
    {
        printf("it's a draw !");
    }
}


void normal()
{
    struct player player1;
    struct player player2;
    double occ;
    printf("first player what's your name \n");
    scanf("%s",&player1.name);
    do{
        printf("X or O");
        scanf("%c",&player1.x);
    }while(player1.x!='x' && player1.x!='o');

    if(player1.x=='x')
    {
        player2.x='o';
    }
    else if(player1.x=='o')
    {
        player2.x='x';
    };
    int c;
    c=finish(mat);
    char t;
    int k,win=0;
    ajout(player2.x,'6');
    system("cls");
    affichage();
    do{
        printf("take a spot: ");
        scanf("%c",&player1.spot);
        k=check(mat,player1.spot);
    }while(k==0);
    ajout(player1.x,player1.spot);
    if(check(mat,'3')!=0)
    {
        ajout(player2.x,'3');
        t='1';
    }
    else
    {
        ajout(player2.x,'9');
        t='7';
    };
    system("cls");
    affichage();
    do{
        printf("take a spot: ");
        scanf("%c",&player1.spot);
        k=check(mat,player1.spot);
    }while(k==0);
    ajout(player1.x,player1.spot);
    if(check(mat,'3')!=0 || check(mat,'9')!=0)
    {
        if(t=='7'){
        ajout(player2.x,'3');}
        else{
            ajout(player2.x,'9');
        }
    }
    else if(t=='7' && (check(mat,'2')==0))
    {
        ajout(player2.x,'1');
        occ=1.1;
    }
    else if(t=='7' && (check(mat,'1')==0))
    {
        ajout(player2.x,'2');
        occ=1.2;
    }
    else if(t=='1' && check(mat,'7')==0)
    {
        ajout(player2.x,'8');
        occ=2.1;
    }
    else if(t=='1' && check(mat,'8')==0)
    {
        ajout(player2.x,'7');
        occ=2.2;
    }
    else if(check(mat,'5')!=0 && check(mat,'4')!=0)
    {
        ajout(player2.x,'5');
        occ=3.0;
    }
    else
    {
        if(t=='7')
        {
            ajout(player2.x,'7');
            occ=4.2;
        }
        else{
            ajout(player2.x,'1');
            occ=4.1;
        }
    }
    system("cls");
    affichage();
    win=winner(mat);
    if(win==1)
    {
        printf("you lost in the normal mode!!");
        exit(0);
    }
    do{
        printf("take a spot: ");
        scanf("%c",&player1.spot);
        k=check(mat,player1.spot);
    }while(k==0);
    ajout(player1.x,player1.spot);
    system("cls");
    affichage();
    win=winner(mat);
    if(win==1)
    {
        printf("congratulations %s you won in the normal mode!!",player1.name);
        exit(0);
    };
    if(occ==1.1)
    {
        if(check(mat,'5')!=0)
        {
            ajout(player2.x,'5');
        }
        else
        {
            ajout(player2.x,'4');
            occ=1.11;
        }
    }
    else if(occ==4.1)
    {
        if(check(mat,'2')!=0)
        {
            ajout(player2.x,'2');
        }
        else
        {
            ajout(player2.x,'7');
        }
    }
    else if(occ==4.2)
    {
        if(check(mat,'8')!=0)
        {
            ajout(player2.x,'8');
        }
        else
        {
            ajout(player2.x,'1');
        }
    }
    else if(occ==3.0)
    {
        if(check(mat,'4')!=0)
        {
            ajout(player2.x,'4');
            occ=3.1;
        }
        else
        {
            ajout(player2.x,'7');
        }
    }
    else if(occ==1.2)
    {
        if(check(mat,'7')==0)
        {
            ajout(player2.x,'5');
            occ=1.21;
        }
        else if(check(mat,'4')==0)
        {
            ajout(player2.x,'7');
            occ=1.22;
        }
        else if(check(mat,'5')==0)
        {
            ajout(player2.x,'7');
            occ=1.23;
        }
        else
        {
            ajout(player2.x,'7');
            occ==1.24;
        }
    }
    else if(occ==2.2)
    {
        if(check(mat,'5')==0)
        {
            ajout(player2.x,'2');
            occ=2.22;
        }
        else
        {
            ajout(player2.x,'5');
            occ=2.21;
        }
    }
    else if(occ=2.1)
    {
        if(check(mat,'1')==0)
        {
            ajout(player2.x,'5');
            occ=2.11;
        }
        else if(check(mat,'5')==0)
        {
            ajout(player2.x,'2');
            occ=2.12;
        }
        else if(check(mat,'2')==0)
        {
            ajout(player2.x,'5');
            occ=2.13;
        }
        else
        {
            ajout(player2.x,'1');
            occ=2.14;
        }

    }
    system("cls");
    affichage();
    win=winner(mat);
    if(win==1)
    {
        printf("you lost in the normal mode!!");
        exit(0);
    }
    do{
        printf("take a spot: ");
        scanf("%c",&player1.spot);
        k=check(mat,player1.spot);
    }while(k==0);
    ajout(player1.x,player1.spot);
    system("cls");
    affichage();
    win=winner(mat);
    if(win==1)
    {
        printf("congratulations %s you won in the normal mode!!",player1.name);
        exit(0);
    };

    srand(time(0));
    char s;
    do
    {
        s=(rand()%8+49);
        k=check(mat,s);
    }while(k==0);
    ajout(player2.x,s);
    if(win==1)
    {
        printf("you lost in the normal mode!!\n");
        exit(0);
    }
    else
    {
        printf("it's a draw!\n");
    }
    affichage();

}


void diff()
{
    struct player player1;
    struct player player2;
    printf("first player what's your name \n");
    scanf("%s",&player1.name);
    do{
        printf("X or O");
        scanf("%c",&player1.x);
    }while(player1.x!='x' && player1.x!='o');
    if(player1.x=='x')
    {
        player2.x='o';
    }
    else if(player1.x=='o')
    {
        player2.x='x';
    };
    srand(time(0));
    int turn=1;
    int c,t;
    c=finish(mat);
    int k,win=0;
    while(c!=1 && win == 0)
    {
        if(turn%2!=0)
        {
            do
            {
                printf("take a spot: ");
                scanf("%c",&player1.spot);
                k=check(mat,player1.spot);

            }while(k==0);
            ajout(player1.x,player1.spot);
            turn++;
            win=winner(mat);
            if(win==1)
            {
                printf("congratulations %s you won!",player1.name);
            }
        }
        else
        {
            if(checkd(mat,'1',player2.x)==0 && checkd(mat,'2',player2.x)==0 && checkd(mat,'3',player2.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player2.x)==0 && checkd(mat,'5',player2.x)==0 && checkd(mat,'6',player2.x)==1)
            {
                ajout(player2.x,'6');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'7',player2.x)==0 && checkd(mat,'8',player2.x)==0 && checkd(mat,'9',player2.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'2',player2.x)==0 && checkd(mat,'3',player2.x)==0 && checkd(mat,'1',player2.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player2.x)==0 && checkd(mat,'6',player2.x)==0 && checkd(mat,'4',player2.x)==1)
            {
                ajout(player2.x,'4');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'8',player2.x)==0 && checkd(mat,'9',player2.x)==0 && checkd(mat,'7',player2.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player2.x)==0 && checkd(mat,'3',player2.x)==0 && checkd(mat,'2',player2.x)==1)
            {
                ajout(player2.x,'2');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player2.x)==0 && checkd(mat,'6',player2.x)==0 && checkd(mat,'5',player2.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'7',player2.x)==0 && checkd(mat,'9',player2.x)==0 && checkd(mat,'8',player2.x)==1)
            {
                ajout(player2.x,'8');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player2.x)==0 && checkd(mat,'4',player2.x)==0 && checkd(mat,'7',player2.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }

            else if(checkd(mat,'2',player2.x)==0 && checkd(mat,'5',player2.x)==0 && checkd(mat,'8',player2.x)==1)
            {
                ajout(player2.x,'8');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player2.x)==0 && checkd(mat,'6',player2.x)==0 && checkd(mat,'9',player2.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player2.x)==0 && checkd(mat,'7',player2.x)==0 && checkd(mat,'1',player2.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player2.x)==0 && checkd(mat,'8',player2.x)==0 && checkd(mat,'2',player2.x)==1)
            {
                ajout(player2.x,'2');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'9',player2.x)==0 && checkd(mat,'6',player2.x)==0 && checkd(mat,'3',player2.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player2.x)==0 && checkd(mat,'7',player2.x)==0 && checkd(mat,'4',player2.x)==1)
            {
                ajout(player2.x,'4');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'2',player2.x)==0 && checkd(mat,'8',player2.x)==0 && checkd(mat,'5',player2.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player2.x)==0 && checkd(mat,'9',player2.x)==0 && checkd(mat,'6',player2.x)==1)
            {
                ajout(player2.x,'6');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player2.x)==0 && checkd(mat,'5',player2.x)==0 && checkd(mat,'9',player2.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player2.x)==0 && checkd(mat,'9',player2.x)==0 && checkd(mat,'1',player2.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player2.x)==0 && checkd(mat,'9',player2.x)==0 && checkd(mat,'5',player2.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player2.x)==0 && checkd(mat,'5',player2.x)==0 && checkd(mat,'7',player2.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player2.x)==0 && checkd(mat,'7',player2.x)==0 && checkd(mat,'3',player2.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player2.x)==0 && checkd(mat,'7',player2.x)==0 && checkd(mat,'5',player2.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'2',player1.x)==0 && checkd(mat,'3',player1.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player1.x)==0 && checkd(mat,'5',player1.x)==0 && checkd(mat,'6',player1.x)==1)
            {
                ajout(player2.x,'6');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'7',player1.x)==0 && checkd(mat,'8',player1.x)==0 && checkd(mat,'9',player1.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'2',player1.x)==0 && checkd(mat,'3',player1.x)==0 && checkd(mat,'1',player1.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player1.x)==0 && checkd(mat,'6',player1.x)==0 && checkd(mat,'4',player1.x)==1)
            {
                ajout(player2.x,'4');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'8',player1.x)==0 && checkd(mat,'9',player1.x)==0 && checkd(mat,'7',player1.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'3',player1.x)==0 && checkd(mat,'2',player1.x)==1)
            {
                ajout(player2.x,'2');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player1.x)==0 && checkd(mat,'6',player1.x)==0 && checkd(mat,'5',player1.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'7',player1.x)==0 && checkd(mat,'9',player1.x)==0 && checkd(mat,'8',player1.x)==1)
            {
                ajout(player2.x,'8');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'4',player1.x)==0 && checkd(mat,'7',player1.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }

            else if(checkd(mat,'2',player1.x)==0 && checkd(mat,'5',player1.x)==0 && checkd(mat,'8',player1.x)==1)
            {
                ajout(player2.x,'8');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player1.x)==0 && checkd(mat,'6',player1.x)==0 && checkd(mat,'9',player1.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'4',player1.x)==0 && checkd(mat,'7',player1.x)==0 && checkd(mat,'1',player1.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player1.x)==0 && checkd(mat,'8',player1.x)==0 && checkd(mat,'2',player1.x)==1)
            {
                ajout(player2.x,'2');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'9',player1.x)==0 && checkd(mat,'6',player1.x)==0 && checkd(mat,'3',player1.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'7',player1.x)==0 && checkd(mat,'4',player1.x)==1)
            {
                ajout(player2.x,'4');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'2',player1.x)==0 && checkd(mat,'8',player1.x)==0 && checkd(mat,'5',player1.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player1.x)==0 && checkd(mat,'9',player1.x)==0 && checkd(mat,'6',player1.x)==1)
            {
                ajout(player2.x,'6');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'5',player1.x)==0 && checkd(mat,'9',player1.x)==1)
            {
                ajout(player2.x,'9');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player1.x)==0 && checkd(mat,'9',player1.x)==0 && checkd(mat,'1',player1.x)==1)
            {
                ajout(player2.x,'1');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'1',player1.x)==0 && checkd(mat,'9',player1.x)==0 && checkd(mat,'5',player1.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player1.x)==0 && checkd(mat,'5',player1.x)==0 && checkd(mat,'7',player1.x)==1)
            {
                ajout(player2.x,'7');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'5',player1.x)==0 && checkd(mat,'7',player1.x)==0 && checkd(mat,'3',player1.x)==1)
            {
                ajout(player2.x,'3');
                system("cls");
                affichage();
            }
            else if(checkd(mat,'3',player1.x)==0 && checkd(mat,'7',player1.x)==0 && checkd(mat,'5',player1.x)==1)
            {
                ajout(player2.x,'5');
                system("cls");
                affichage();
            }
            else
            {
                t=(rand()%8+49);
                while(check(mat,t)==0)
                {
                    t=(rand()%8+49);
                }
                ajout(player2.x,t);
                system("cls");
                affichage();

            }
            win=winner(mat);
            if(win==1)
            {
                printf("You Lost!!",player1.name);
            }
            turn++;
        }

    }
    if(win==0)
    {
        printf("It's a Draw");
    }
}


int main()
{
    int mode;
    printf("\t Hello and Welcome To TIC TAC TOE \n");
    printf("Game Mode: \n 1->1 v 1 \n 2->easy Mode \n 3-> Normal Mode \n 4->Hard Mode \n ");
    scanf("%d",&mode);
    if(mode==1)
    {
        system("cls");
        remplir();
        affichage();
        multijoueur(mode);
    }
    else if(mode==2)
    {
        system("cls");
        remplir();
        affichage();
        multijoueur(mode);

    }
    else if(mode==3)
    {
        system("cls");
        remplir();
        affichage();
        normal();
    }
    else
    {
        system("cls");
        remplir();
        affichage();
        diff();
    }
}

