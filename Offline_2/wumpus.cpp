#include <iostream>
#include <cmath>
#include <sstream>
#include<time.h>
#include<stdlib.h>

using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3


string to_String(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}


class Position
{

    int x, y;

public:

    Position (int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {x=0;y=0;}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {
        if(x<GRIDSIZE)x++;
    }

    void moveLeft()
    {
        if(x>0)x--;
    }

    void moveUp()
    {
        if(y<GRIDSIZE)y++;
    }

    void moveDown()
    {
        if(y>0)y--;
    }

    bool isAdjacent(Position p)
    {
        //implement the function

        int x_p=p.getX();
        int y_p=p.getY();

        //same row,adjacent cell

        if(x==x_p){
            if(((y-1)==y_p)||((y+1)==y_p))return true;
        }

        //same column,adjacent cell

        if(y==y_p){
            if(((x-1)==x_p)||((x+1)==x_p))return true;
        }
        //else
        return false;
    }

    bool isSamePoint(Position p)
    {
        //implement the function
        int x_p=p.getX();
        int y_p=p.getY();

        //same co-ordinate

        if((x==x_p)&&(y==y_p))return true;

        //else

        return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};


class Wumpus
{

    bool killed;
    Position p;

public:

    Wumpus(int x, int y)
    {
        p=Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        srand(time(NULL));
        int x=1+rand()%3;
        int y=1+rand()%3;
        p=Position(x,y);
    }

    void kill()
    {
        killed = true;
    }

    Position getPosition()
    {
        return p;
    }

};


class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:

    Player()
    {
        //...
        p=Position(0,0);
        killed=false;
        total_shots=3;
        direction=UP;
    }

    void turnLeft()
    {
        //...
        if(direction==UP)direction=LEFT;
        else if(direction==LEFT)direction=DOWN;
        else if(direction==DOWN)direction=RIGHT;
        else if(direction==RIGHT)direction=UP;
        
    }

    void turnRight()
    {
        //...
        if(direction==UP)direction=RIGHT;
        else if(direction==LEFT)direction=UP;
        else if(direction==DOWN)direction=LEFT;
        else if(direction==RIGHT)direction=DOWN;
    }

    void moveForward()
    {
        //...
        if(direction==UP)p.moveUp();
        else if(direction==DOWN)p.moveDown();
        else if(direction==RIGHT)p.moveRight();
        else if(direction==LEFT)p.moveLeft();

    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_String(p.getX()) + ", " + to_String(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

};



class WumpusWorld
{

private:

    Player player;
    Wumpus wumpus;
    Position gold_position;
    bool ended;

public:

    WumpusWorld()
    {
        //...
        //Wumpus(2,3);
        wumpus=Wumpus();
        srand(time(NULL));
        int x=1+rand()%3;
        int y=1+rand()%3;
        Position p=wumpus.getPosition();
        Position q(x,y);
        if(p.isSamePoint(q)){
            if(x<3)x++;
            else if(x==3)x--;
            gold_position=Position(x,y);
        }
        else{
            gold_position=Position(x,y);
        }

    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        srand(time(NULL));
        int x=rand()%4;
        int y=rand()%4;
        gold_position=Position(x,y);
    }



    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(gold_x,gold_y);

    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(gold_x,gold_y);
        int pitx=pit_x;
        int pity=pit_y;
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        //...
        //getting player's position=ooof!!!
        string s=player.getPositionInfo();
        int x_p,y_p;
        //x_p=atoi(s[s.length()-4]);
        string s1,s2;
        s1=s[s.length()-4];
        s2=s[s.length()-1];
        stringstream ss;
        ss<<s1;
        ss>>x_p;
        //cout<<x<<endl;
        ss.clear();
        ss<<s2;
        ss>>y_p;
        //cout<<y;

        Position p=wumpus.getPosition();
        int x=p.getX();
        int y=p.getY();
        string str=player.getDirectionInfo();
        int i=str.length()-1;
        while(i>=0&& str[i]!=' '){
            i--;
        }
        string direction;
        for(int j=i+1;j<str.length();j++){
            direction+=str[j];
        }
        if(direction=="up"){
            if(x==x_p&&y_p<y){
                cout<<"We killed the wumpus,yay!!!"<<endl;
            }
            else /*if(x==x_p&&y_p>y)*/{
                cout<<"You missed:("<<endl;
            }            
        }
        else if(direction=="down"){
            
            if(x==x_p&&y_p>y){
                cout<<"We killed the wumpus,yay!!!"<<endl;
            }  
            else{
                cout<<"You missed:("<<endl;
            }          
        }
        else if(direction=="left"){
            
            if(y==y_p&&x_p>x){
                cout<<"We killed the wumpus,yay!!!"<<endl;
            }    
            else{
                cout<<"You missed:("<<endl;
            }        
        }
        else if(direction=="right"){
            
            if(y==y_p&&x_p<x){
                cout<<"We killed the wumpus,yay!!!"<<endl;
            } 
            else{
                cout<<"You missed:("<<endl;
            }           
        }
    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }

};


int main()
{
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    //cin>>wumpus_x>> wumpus_y>> gold_x>>gold_y>> pit_x>>pit_y;
    WumpusWorld w;//(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }
    }
    return 0;
}
