#include <iostream>
#include<time.h>

using namespace std;

void imprimirAbecedario(){
char *pc;
char c;
pc=&c;
for(int i=65;i<=90;i++){
    c=i;
    cout<<*pc<<" ";
}
}

void invertirArray(){
    int array[5]={1,2,3,4,5};
    int *yarra[5];
    for(int i=0,j=4;i<5,j>=0;i++,j--){
        yarra[i]= &array[j];
    }
    for(int i=0;i<5;i++){
        cout<<*yarra[i]<<" ";    
    }

}

void sumDiags(){
    const int fil=3,col=3;
    int matriz[fil][col];
    int result=0;
    int num=1;
    for(int i=0;i<fil;i++){
        for(int j =0; j<col;j++){
            matriz[i][j]=num;
            if(i==j){
                result+=matriz[i][j];
           }
           if(i+j==col-1){
            result+=matriz[i][j];
           }
           num++;
        }
    }
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
     cout<<result;
}

void sumArray(){
    int array[5]={3,7,1,8,5};
    string sarray[5]={"Hola","buenas","noches","mi","estimado"};
    string _string="";
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=array[i];
    }
    for(int i =0;i<5;i++){
        _string+=sarray[i]+" ";
    }
    cout<<_string;

}

void matrizIdenidad(){
    int matriz[5][5];
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j){
                matriz[i][j]=1;
            }
            else{
            matriz[i][j]=0;
            }
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

void marco(){
    const int col=7,fil=5;
    int matriz[fil][col];
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            if(i==0||j==0||i==fil-1||j==col-1){
                matriz[i][j]=1;
            }
            else{
                matriz[i][j]=0;
            }
        }
    }

    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

void rotate(){
    const int fil=5,col=5;
    int matriz[fil][col];
    int matAux[fil][col];
    int num=1;
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            matriz[i][j]=num;
            num++;
        }

    }

    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            matAux[i][j]=matriz[i][j];
        }
    }
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            matriz[j][fil-1-i]=matAux[i][j];
        }
    }

    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

void sumMarco(){
    
}

int main(){
    //imprimirAbecedario();
    //cout<<endl;
    //invertirArray();
   //cout<<endl;
    //sumDiags();
   //cout<<endl;
    //sumArray();
    //cout<<endl;
    //matrizIdenidad();
    //cout<<endl;
    //marco();
    //cout<<endl;
    rotate();
    cout<<endl;
}