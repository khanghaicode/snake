#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#define WINDOWN_W 100
#define WINDOWN_H 25
using namespace std;
int posX=10,posY=10;
bool leftt=false,rightt=true,up=false,down=false;
bool thua=false;
int len=1;
int appleX=rand() % (WINDOWN_W-2,2);
int appleY=rand() % (WINDOWN_H-2,2);
vector<pair<int,int>>snake;
bool losecheck(){
    for(auto p:snake){
        if(posX==p.first&&posY==p.second)return true;
    }
    return false;
}
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawboard(){
    for(int i=0;i<WINDOWN_W;i++){
        gotoxy(i,0);
        cout<<'0';
    }
    for(int i=1;i<WINDOWN_H-1;i++){
        gotoxy(0,i);
        cout<<'0';
        gotoxy(WINDOWN_W-1,i);
        cout<<'0';
    }
    for(int i=0;i<WINDOWN_W;i++){
        gotoxy(i,WINDOWN_H-1);
        cout<<'0';
    }
}void update_apple(){
    appleX=rand() % (WINDOWN_W-2,2)+2;
    appleY=rand() % (WINDOWN_H-2,2)+2;
    len++;
}
void update_pos(){
    if(up)posY--;
    else if(down)posY++;
    else if(leftt)posX--;
    else if(rightt)posX++;
    if(posX>WINDOWN_W-1)posX=1;
    else if(posX<1)posX=WINDOWN_W-2;
    if(posY>WINDOWN_H-1)posY=1;
    else if(posY<1)posY=WINDOWN_H-2;
    if(losecheck())thua=true;
}
void insrtsnk(){
    pair<int,int>head={posX,posY};
    snake.push_back(head);
    if(snake.size()>len)snake.erase(snake.begin(),snake.begin()+1);
}
void draw_snake(){
    for(auto p:snake){
        gotoxy(p.first,p.second);
        cout<<'0';
    }
}
void draw_apple(){
    gotoxy(appleX,appleY);
    cout<<'a';
}
int main(){
    char key;
    while(!thua){
        system("cls");
        drawboard();
        if(kbhit()){
            key=getch();
            if(key=='a'&&!rightt){
            leftt=true;
            rightt=false;
            down=false;
            up=false;
        }
            else if(key=='d'&&!leftt){
            leftt=false;
            rightt=true;
            down=false;
            up=false;
        }
            else if(key=='w'&&!down){
            leftt=false;
            rightt=false;
            down=false;
            up=true;
        }
            else if(key=='s'&&!up){
            leftt=false;
            rightt=false;
            down=true;
            up=false;
        }
            else if(key=='f')len++;
        }
        update_pos();
        insrtsnk();
        draw_snake();
        if(posX==appleX&&posY==appleY)update_apple();//updateapple
        draw_apple();
        Sleep(1);
    }
    system("cls");
    cout<<"thua r";
}
