#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
//case
char case1(int i);
char case2(int i);
//setting array
char maze[15][15];
int m,n;
//running
int visit(char maze[][15],int m, int n);
//start&end
int startM , startN;  // ¤J¤f
int endM,endN;

int success = 0;

int i;

int main()
{
    string filename;
    cout<<"Please input filename:";
    cin>>filename;
    if(filename=="case1.txt"){
        startM=9;
        startN=1;
        endM=1;
        endN=9;
        case1(i);
        }
    if(filename=="case2.txt"){
        startM=10;
        startN=2;
        endM=1;
        endN=10;

        case2(i);}
}

int visit(char maze[][15],int m, int n) {
    maze[m][n] = '1';
    if(m == endM && n == endN)
        success = 1;
    if(success != 1 && maze[m][n-1] == '0') visit(maze,m, n-1);
    if(success != 1 && maze[m+1][n] == '0') visit(maze,m+1, n);
    if(success != 1 && maze[m][n+1] == '0') visit(maze,m, n+1);
    if(success != 1 && maze[m-1][n] == '0') visit(maze,m-1, n);
    if(success != 1)
        maze[m][n] = '0';
    return success;
}



char case1(int i){
    //Calling
    fstream a;
    char symbol;
    string filename;
    a.open("case1.txt",ios::in);
    if(!a)
        cout<<"File can not open!"<<endl;
    else{
        for(n=0;n<10;n++){
            for(m=0;m<10;m++){
                a.get(symbol);
                if(symbol=='\n'){
                a.get(symbol);
                cout<<endl;
                }
                maze[m][n]=symbol;
                cout<<maze[m][n];
            }
        }
    }
    cout<<endl;
    cout<<endl;
    //Running&Output
    if(visit(maze,startM,startN)==1){

        for(int n=0;n<10;n++){
            for(int m=0;m<10;m++){
                    cout<<maze[m][n];
            }
            cout<<endl;
        }
        ofstream b;
        cout<<"Output filename:case1_sol.E24039122.txt";
        b.open("case1_sol.E24039122.txt",ios::out);
        if(!b)
            cout<<"File can not open!"<<endl;
    }
}

char case2(int i){
    fstream a;
    char symbol;
    string filename;
    a.open("case2.txt",ios::in);
    if(!a)
        cout<<"File can not open!"<<endl;
    else{
        for(n=0;n<11;n++){
            for(m=0;m<11;m++){
                a.get(symbol);
                if(symbol=='\n'){
                a.get(symbol);
                cout<<endl;
                }
                maze[m][n]=symbol;
                cout<<maze[m][n];
            }
        }
    }
    cout<<endl;
    cout<<endl;
    maze[10][2]=1;
//Running&Output
    if(visit(maze,startM,startN)==1){

        for(int n=0;n<11;n++){
            for(int m=0;m<11;m++){
                    cout<<maze[m][n];
            }
            cout<<endl;
        }
        ofstream b;
        cout<<"Output filename:case2_sol.E24039122.txt";
        b.open("case2_sol.E24039122.txt",ios::out);
        if(!b)
            cout<<"File can not open!"<<endl;

        }
    }

