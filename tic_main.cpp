#include<iostream>
#include<string.h>
#include<vector>
#include<limits>
using namespace std;


   char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
   char token = 'x';
   int row;
   int digit;
   int column;

    void registerPlayers();
    void drawBoard();
    void playGame();
    void assignDigit();
    bool winning(){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if((space[i][0]==space[i][1]&& space[i][0]==space[i][2])||(space[0][j]==space[1][j]&& space[0][j]==space[2][j])||(space[0][0]==space[1][1]&& space[0][0]==space[2][2])){
            cout<<token<<"wins!!!!!";
            return true;
            }
        
        }
    }
    return false;
}
int main(){
    registerPlayers();
    drawBoard();
    winning();
    playGame();

    }

void drawBoard(){
    cout << "          |            |" << endl;
    cout << "          |            |" << endl;
    cout << space[0][0] <<"         |"<<space[0][1]<<"           |         "<< space[0][2] << endl;
    cout << "          |            |" << endl;
    cout << "__________|____________|__________" << endl;
    cout << "          |            |" << endl;
    cout << "          |            |" << endl;
    cout << space[1][0] <<"         |"<<space[1][1]<<"           |         "<< space[1][2] << endl;
    cout << "          |            |" << endl;
    cout << "__________|____________|__________" << endl;
    cout << "          |            |" << endl;
    cout << "          |            |" << endl;
    cout << space[2][0] <<"         |"<<space[2][1]<<"           |         "<< space[2][2] << endl;
    cout << "          |            |" << endl;
    cout << "          |            |" << endl;
}

void registerPlayers(){
    string n1;
    string n2;
    cout << "enter name of player one:" << endl; ;
    getline(cin,n1);
    cout << "enter name of player Two:" << endl ;
    getline(cin,n2);
}

void playGame(){
    while (true) {
        assignDigit();
        if(space[row][column]!='O'&& space[row][column]!='X'){
            space[row][column]= token;
            if(winning()){
                drawBoard();
                cout << token << " wins!!!!!" << endl;
                break;
            }
            else if (space[0][0] != '1' && space[0][1] != '2' && space[0][2] != '3' && space[1][0] != '4' && space[1][1] != '5' && space[1][2] != '6' && space[2][0] != '7' && space[2][1] != '8' && space[2][2] != '9') {
                drawBoard();
                cout << "It's a tie!" << endl;
                break;
            }
            else {
                if (token == 'X') {
                    token = 'O';
                }
                else {
                    token = 'X';
                }
                drawBoard();
            }
        }
        else{
            cout<< "already filled" << endl;
        }
    }
}


void assignDigit(){
    while (true) {
        cout << "Enter a digit between 1 and 9: ";
        cin >> digit;
        if (cin.fail() || digit < 1 || digit > 9) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    
    switch (digit) {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
    }
}