// Language C++
#include<bits/stdc++.h>
using  namespace std;

class Player
{
private:
    int id;
    string name;
    int currPos;
public:
    Player(int id,string name){
        this->id=id;
        this->name=name;
        this->currPos=-1;
    }
    string getPlName() {return this->name;}
    int getPlPos() {return this->currPos;}
    bool won(){
        return currPos == 100;
    }
    bool move(int diceVal ,map<int,int> &snake,map<int,int> &ladder){ // zigzag
        int moveto = currPos+diceVal;
        if(moveto > 100)
            return false;
        else if(snake.find(moveto) != snake.end()){
                move(snake[moveto],snake,ladder);
        }
        else if(ladder.find(moveto) != ladder.end()){
                move(ladder[moveto],snake,ladder);
        }
        currPos = moveto;
        return true;
    }
};


int main()
{
    // Initilisation and Input
    map<int,int> snake,ladder;
    int playerCount;
    int currPlayer = 0;
    vector<Player> players;
    int s,l;
    cin>>s;
    for(int i=0;i<s;i++){
        int a,b;
        cin>>a>>b;
        snake[a]=b;
    }
    cin>>l;
    for(int i=0;i<l;i++){
        int a,b;
        cin>>a>>b;
        snake[a]=b;
    }
    cin>>playerCount;
    for(int i=0;i<playerCount;i++){
        string tempPlName;
        cin>>tempPlName;
        Player obj(i,tempPlName);
        players.push_back(obj);
    }
    srand(time(NULL));
    
    // Game Start
    while(true){
        currPlayer++;
        currPlayer%=playerCount;
        
        int currPos = players[currPlayer].getPlPos();
        
        int dice = rand() % 6 + 1;
        players[currPlayer].move(dice,snake,ladder);
        
        cout<<players[currPlayer].getPlName()<<" rolled a "<<dice<<" and moved from "<<currPos<<" to "<<players[currPlayer].getPlPos()<<endl;
        
        if(players[currPlayer].won()){
            cout<<players[currPlayer].getPlName()<<" wins the game";
            break;
        }
    }
    return 0;
}