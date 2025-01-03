#include <iostream>

using namespace std;

class Circulo{
    private:
    int radio;
    public:
    Circulo(int _radio){
        radio=_radio;
    }

    int getRadio(){
        return radio;
    }
};

int main(){
    char verifier='n'; 
    cout<<"Buenos dias!\n";    
    int radius;
    while(verifier=='n'||verifier=='N'){
    cout<<"Por favor ingresa el radio del circulo\n";
    cin>>radius;
    Circulo circulo(radius);
    if(radius>0){
    cout<<"El valor del radio del circulo es "<<circulo.getRadio();    
    cout<<"\nDesea salir?\ny/n";
    cin>>verifier;
    }
    else{
        cout<<"El numero ingresado no es valido\n";
    }

    }

}