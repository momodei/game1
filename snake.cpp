#include<bits/stdc++.h>
#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

time_t curTime;
int sc;
int score = 0;
int L, R, U, D;
char mp[10][9];
int h = 4;
void Graphics()
{
    system("cls");
    cout << "Score: " << score << " Max Score: " << max(sc, score) << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++) {
                cout << mp[i][j];
        }cout << "|\n";
    }
}
int newWall = 0;
void Update(){
    for(int i = 9; i > 0; i--){
        for(int j = 0; j < 9; j++) {
            mp[i][j] = mp[i-1][j];
        }
    }
    srand(time(NULL));
    newWall++;
    if(newWall == 5) {
        for(int i = 0; i < 9; i++) mp[0][i] = (rand()%2 == 0)? '#' : ' ';
        newWall = 0;
    }
    else for(int i = 0; i < 9; i++) {
        mp[0][i] = ' ';
    }
    if(mp[9][h] == '#') {
            freopen("score.txt", "w", stdout);
            if(score > sc) sc = score;
            cout << sc;
            exit(0);
    }
    mp[9][h] = '*';
    score++;
}

void KEYBOARD() {
    if(_kbhit())

    {
        char key;
        key = _getch();
        switch( key )
        {
            case 'd':
            {
                if (h != 9) {
                    cout << (mp[0][h] = ' ') << endl;
                    h++;
                }
                break;
            }

            case 'a':
            {
                if (h != 0)
                {
                    cout << (mp[0][h] = ' ') << endl;
                    h--;
                }
            break;
            }
        }
        cout << (mp[0][h] = ' ') << endl;
    }
}

void Start()
{
    while(true){
        KEYBOARD();
        if(clock() - curTime >= 100) {
            Update();
            Graphics();
            curTime = clock();
        }
    }
}

int main(){
    freopen("score.txt", "r", stdin);
    cin >> sc;
    curTime = clock();
    Start();

}
