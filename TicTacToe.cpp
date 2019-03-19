#include<iostream>
#include<Windows.h>
#include<string>
#include<time.h>
using namespace std;
int getRandom(int num) {
    srand(time(0));
    return rand() % num;
}

void disp(int arr[][3]) {
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            cout<<" "<<i * 3 + j;
            if(j == 2) {
                break;
            }
            cout<<" |";
        }
        if(i == 2)
            break;
        cout<<endl<<"---|---|---"<<endl;
    }
    cout<<endl<<endl;

    char a[3][3];
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            if(arr[i][j] == 1)
                a[i][j] = 'X';
            else if(arr[i][j] == -1)
                a[i][j] = '0';
            else
                a[i][j] = ' ';
        }
    }
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            cout<<" "<<a[i][j];
            if(j == 2) {
                break;
            }
            cout<<" |";
        }
        if(i == 2)
            break;
        cout<<endl<<"---|---|---"<<endl;
    }
    cout<<endl;
}

int isWin(int arr[][3],int input) {
    for(int i = 0;i < 3;i++) {
        if(arr[i][0] == arr[i][1] == arr[i][2]) {
            if(arr[i][0] == input) {
                return true;
            }
        }
    }
    for(int i = 0;i < 3;i++) {
        if(arr[0][i] == arr[1][i] == arr[2][i]) {
            if(arr[0][i] == input) {
                return true;
            }
        }
    }
    if(arr[0][0] == arr[1][1] == arr[2][2] == input)
        return true;
    if(arr[0][2] == arr[1][1] == arr[2][0] == input)
        return true;
    return false;
}

int playHuman(int arr[][3]) {
    cin.ignore();
    string player1,player2;
    int x;
    cout<<"Enter name of first player who takes 'X' : ";
    getline(cin,player1);
    cout<<"Enter name of second player who takes '0' : ";
    getline(cin,player2);
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            cout<<" "<<i * 3 + j;
            if(j == 2) {
                break;
            }
            cout<<" |";
        }
        if(i == 2)
            break;
        cout<<endl<<"---|---|---"<<endl;
    }
    cout<<endl;
    for(int i = 0;i < 2;i++) {
        cout<<endl;
        cout<<player1<<" enter the position you want to insert : ";
        cin>>x;
        if(arr[x / 3][x % 3] == 0) {
            arr[x / 3][x % 3] = 1;
        }
        else {
            cout<<"Rules violated";
            Sleep(1000);
            return 1;
        }
        disp(arr);
        cout<<endl;
        cout<<player2<<" enter the position you want to insert : ";
        cin>>x;
        if(arr[x / 3][x % 3] == 0) {
            arr[x / 3][x % 3] = -1;
        }
        else {
            cout<<"Rules violated";
            Sleep(1000);
            return 1;
        }
        system("cls");
        disp(arr);
    }

    int count = 2;
    while(true) {
        cout<<endl;
        cout<<player1<<" enter the position you want to insert : ";
        cin>>x;
        if(arr[x / 3][x % 3] == 0) {
            arr[x / 3][x % 3] = 1;
        }
        else {
            cout<<"Rules violated";
            Sleep(1000);
            return 1;
        }
        if(isWin(arr,1)) {
            cout<<player1<<" wins";
            Sleep(1000);
            return 0;
        }
        if(count == 4) {
            cout<<"Game Draw";
            Sleep(1000);
            return 0;
        }
        disp(arr);
        cout<<endl;
        cout<<player2<<" enter the position you want to insert : ";
        cin>>x;
        if(arr[x / 3][x % 3] == 0) {
            arr[x / 3][x % 3] = 1;
        }
        else {
            cout<<"Rules violated";
            Sleep(1000);
            return 1;
        }
        if(isWin(arr,-1)) {
            cout<<player2<<" wins";
            Sleep(1000);
            return 0;
        }
        system("cls");
        disp(arr);
        count++;
    }
    
    

}

int main() {
    // 1 is X and -1 is 0, 0 is " "
    //Computer is -1 and user is 1, else 0
    int arr[3][3] = {0};
    int choice;
    cout<<" Menu \n"
          "1. V/S Computer \n"
          "2. V/S Human \n"
          "3. Exit \n";
    while(true) {
        cout<<"Select your choice - ";
        cin>>choice;
        if(choice == 1 || choice == 2 || choice == 3)
            break;
        cout<<"Wrong choice \n";
    }
    if(choice == 3) {
        cout<<"\nHope to see you again ";
        Sleep(1000);
        return 0;
    }
    if(choice == 2) {
        if(playHuman(arr) == 0) {
            disp(arr);
        }
        return 0;
    }


    disp(arr);
    system("cls");
    cout<<"LOL";
    cin>>choice;
    return 0;
}