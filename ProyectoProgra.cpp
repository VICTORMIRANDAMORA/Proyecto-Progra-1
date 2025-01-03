#include<iostream>
#include<stdio.h>

/*Para hoy!!
-hacer (minimo) un intento de las graderias, puede usar el codigo del proyecto del cine
-para lo de anadir asientos, por lo menos, haga un objeto para hacer las pruebas
-con lo de los asientos, puede hacer un mensaje para dejar en "claro" los asientos que le quedan,o
decir cuantos asientos le quedan del total (de tipo: "quedan X asientos" o " quedan X/Y asientos")*/

using namespace std;

class Segmento {
private:


};

void anadirAsientos(){

}

int main(){

printf("Hola! Bienvenido!\n");
printf("Indicanos, eres cliente o administrador?\n");
printf("1.Administrador\n2.Cliente\n3. Acerca de...\n4. Salir\n");
int profile=0;
bool admin=false;
bool client=false;
bool active=true;
cin>>profile;
do{
if(profile==1){
    int accessPin=0;
    int adminChoice=0;
    admin=true;
    do{
    printf("Bienvenido, Administrador\n");
    printf("Por favor, ingresa tu pin de acceso\nO presiona 5 para regresar al menu anterior\n");
    cin>>accessPin;
    do{
    if(accessPin==12345 or accessPin==00000 or accessPin==11111 or accessPin==99999){
        printf("Bienvenido, Administrador, que deseas hacer?\n");
        printf("1. Configurar evento(s)\n2. Configurar descuento(s)\n3. Regresar\n");
        cin>>adminChoice;
        if(adminChoice==3){
        accessPin=0;
        }
        if(adminChoice==1){
            printf("Aqui se podra configurar un nuevo evento o uno ya existente\n");
            printf("Presiona 3 para regresar\n");
            cin>>adminChoice;
        }
        if(adminChoice==2){
            printf("Aqui se podra configurar un nuevo descuento o uno ya existente\n");
            printf("Presiona 3 para regresar\n");
            cin>>adminChoice;
        }
        if(adminChoice!=1 or adminChoice!=2){
            printf("Numero no valido\nPor favor, ingrese un numero correcto\n");
            cin>>adminChoice;
        }
    }
    else{
        printf("Pin de acceso invalido, por favor, ingresa un pin correcto o presiona 5 para regresar al menu anterior\n");
    }    
    }while(accessPin!=0 && admin);
    
    if(accessPin==5){
        admin=false;
    }
    }
    while(admin);
}
if(profile==2){
    client=true;
    int clientChoice=0;
    do{
    printf("Bienvenido, Cliente, que desea hacer?\n");
    printf("1.Consultar estado de entradas\n2.Comprar entradas\n5.Regresar al menu anterior\n");
    cin>>clientChoice;
    do{
    if(clientChoice==1){
        printf("Aqui se podran ver los eventos y sus graderias\n");
        printf("Presiona 3 para regresar\n");
        cin>>clientChoice;
    }
    if(clientChoice==2){
        printf("Aqui se podra comprar entradas para los eventos\n");
        printf("Presiona 3 para regresar\n");
        cin>>clientChoice;
    }
    if(clientChoice==3){
        clientChoice=0;
    }

    if(clientChoice!=1 or clientChoice!= 2){
        printf("Numero invalido, por favor, ingrese un numero correcto\n");
        cin>>clientChoice;
    }

    }while(clientChoice!=0 and client);

    if(clientChoice==5){
        client=false;
    }
    }while(client);
}

if(profile==3){
    do{
    printf("Este proyecto fue realizado por el estudiante\nVictor Miranda\nComo parte de la evaluacion de la materia");
    printf("Espero sea de su agrado :)\n");
    printf("5. Para regresar\n");
    cin>>profile;
    if(profile != 1 or profile != 2 or profile != 3){
        printf("Numero invalido, por favor, ingrese un numero correcto\n");
    }
    }while(profile != 5);
}

if(profile==4){
    printf("Gracias por preferirnos\n");
    active=false;
}
}while(active);

return 0;

}