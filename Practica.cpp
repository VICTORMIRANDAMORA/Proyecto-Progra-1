#include <iostream>
#include<stdio.h>

using namespace std;

void calcMostNotas (){
        int vector[10];
    for (int i=0;i<10;i++){
        cout<<"Por favor, ingresa una nota\n";
        cin>>vector[i];
    }

cout<<"Las notas del estudiante son: ";

    for(int i=0;i<10;i++){
        cout<<vector[i]<<", ";
    }
}

void temperaturas(){
    int matriz[5][3];
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout<<"Por favor, ingrese la temperatura del dia "<< i+1<<" del mes "<<j+1<<endl;
            cin>>matriz[i][j];
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Bienvenido\n";
    temperaturas();

}