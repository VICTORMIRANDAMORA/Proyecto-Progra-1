#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cctype>
#include <regex>
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"  
#define COLOR_BLUE    "\033[34m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_MAGENTA "\033[35m"

using namespace std;

int* cedulasRegistradas=nullptr;
int totalCedulas=0;
int entradasTotales=0;
int entradasVendidas=0;

class Persona{
    public:
    string nombre;
    string fechaNaciemiento;
    int cedula;

    Persona(const string& nombre, const string& fechaNaciemiento, int cedula) : nombre(nombre), fechaNaciemiento(fechaNaciemiento), cedula(cedula){}

    void mostrarDatos() const{
        cout<<"Nombre: "<<nombre<<", Fecha de nacimiento: "<<fechaNaciemiento<<", Cedula: "<<cedula<<endl;
    }
};

class ListaPersonas{
    private:
    Persona** personas;
    int capacidad;
    int cantidad;
    void redimensionar(){
        int nuevaCapacidad=capacidad*2;
        Persona** nuevoArreglo=new Persona*[nuevaCapacidad];

        for(int i=0;i<cantidad;i++){
            nuevoArreglo[i]=personas[i];
        }
        delete[]personas;
        personas=nuevoArreglo;
        capacidad=nuevaCapacidad;
    }

    public:
    ListaPersonas():capacidad(2), cantidad(0){
        personas=new Persona*[capacidad];
    }
    ~ListaPersonas(){
        for(int i=0; i<cantidad;i++){
            delete personas[i];
        }
        delete[] personas;
    }

    void agregarPersonas(const string& nombre, const string& fechaNaciemiento, int cedula){
        if(cantidad==capacidad){
            redimensionar();
        }
        personas[cantidad++]=new Persona(nombre,fechaNaciemiento, cedula);
    }

    void mostrarPersonas() const{
        for(int i=0; i<cantidad;i++){
            personas[i]->mostrarDatos();
        }
    }
};

char validarRespuesta(){
    char respuesta;
    do{
        cin>>respuesta;
        respuesta=tolower(respuesta);
        if(respuesta!='s' and respuesta!='n'){
            cout<<"Entrada no valida. Por favor ingresa 's' o 'n'\n";
        }
    }while(respuesta!='s' and respuesta!='n');
    return respuesta;
}

void crearSegmentos(int& numeroSegmentos,int*& filas, int*& columnas, int* precio){
    printf("Por favor, ingrese la cantidad de segmentos que quiere colocar\n");
    cin>>numeroSegmentos;
    cout<<"Se han creado "<<numeroSegmentos<<" segmentos\n";

    filas=new int[numeroSegmentos];
    columnas=new int[numeroSegmentos];
    precio=new int[numeroSegmentos];

    for(int i=0; i<numeroSegmentos;i++){
        cout<<"Por favor, ingrese la candidad de filas que desea anadir al segmento "<<i+1<<endl;
        cin>>filas[i];
        cout<<"Por favor, ingrese la cantidad de columnas que desea anadir al segmento "<<i+1<<endl;
        cin>>columnas[i];
        cout<<"Por favor, ingresa el precio de un asiento en el segmento "<< i+1<<endl;
        cin>>precio[i];
        entradasTotales+=filas[i]*columnas[i];
    }
    cout<<"\nEntradas totales: "<<entradasTotales<<endl<<endl;
}

void inicializarGraderia(string**& graderia, int filasTotales, int columnasTotales){
    graderia = new string*[filasTotales];
    for(int i = 0;i<filasTotales;i++){
        graderia[i]= new string[columnasTotales];
        for(int j=0;j<columnasTotales;j++){
            graderia[i][j]=" ";
        }
    }
}

void llenarGraderia(string** graderia,int* filas, int* columnas, int cantidadSegmentos){
    int filaActual=0;
    char caracterSegmento='A';
    for(int seg=0;seg<cantidadSegmentos;seg++){
        int numeroAsiento=1;
        for(int i=0;i<filas[seg];i++){
            for(int j=0;j<columnas[seg];j++){
                graderia[filaActual+i][j]=string(1,caracterSegmento)+ to_string(numeroAsiento++);
            }
        }
        filaActual += filas[seg];
        caracterSegmento++;
    }
}

void imprimirGraderia(string** graderia,int totalFilas, int totalColumnas, int* filas, int numeroSegmentos, string nombreEvento){
    cout<<"Evento: "<<nombreEvento<<endl;
    int filaActual=0;
    int princFilaSegmento=filas[0];

    const char* colores[]={COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA};
    int indiceColor=0;

    for(int i=0;i<totalFilas;i++){
        for(int j=0;j<totalColumnas;j++){
            if(graderia[i][j]!=" "){
                cout<<"|"<< colores[indiceColor]<<setw(5) <<graderia[i][j]<<COLOR_RESET;
            }
            else{
                cout<<"|"<<setw(5)<<" ";
            }
        }
        cout<<"|\n";
        if(i+1==princFilaSegmento&&filaActual<numeroSegmentos-1){
            cout<<string(totalColumnas*5,'-')<<endl;
            filaActual++;
            princFilaSegmento+=filas[filaActual];
            indiceColor=(indiceColor+1)%6;
        }
    }
}

void liberarMemoria(string** graderia, int totalFilas){
    for(int i=0;i<totalFilas;i++){
        delete[]graderia[i];
    }
    delete[]graderia;
}

int calcularEdad(const string& fechaNacimiento){
    int dia, mes, ano;
    regex formatoFecha("^\\d{2}/\\d{2}/\\d{4}$");
    if(!regex_match(fechaNacimiento,formatoFecha)){
        cout<<"Formato de fecha incorrecto. Usa el formato dd/mm/yyyy.\n";
        return -1;
    }

    sscanf(fechaNacimiento.c_str(), "%d/%d/%d",&dia, &mes, &ano);

    time_t t=time(nullptr);
    tm* fechaActual=localtime(&t);

    int anoActual=fechaActual->tm_year+1900;
    int mesActual=fechaActual->tm_mon+1;
    int diaActual=fechaActual->tm_mday;

    int edad=anoActual-ano;
    if(mesActual<mes or (mesActual==mes and diaActual<dia)){
        edad--;
    }
    return edad;
}

void seleccionarAsientos(string** graderia, int totalFilas, int totalColumnas, int maxEntradas){
    int entradasCompradas=0;
    while(entradasCompradas<maxEntradas and (entradasTotales-entradasVendidas)>0){
        cout<<"Seleccione un asiento:\n";
        string asientoSeleccionado;
        cin>>asientoSeleccionado;

        bool encontrado=false;
        for(int i=0; i<totalFilas;i++){
            for(int j=0;j<totalColumnas;j++){
                if(graderia[i][j]==asientoSeleccionado){
                    graderia[i][j]="OCUP";
                    encontrado=true;
                    entradasCompradas++;
                    entradasVendidas++;
                    cout<<"Asiento "<<asientoSeleccionado<<" reservado con exito\n";
                    cout<<"Quedan "<< entradasTotales-entradasVendidas<<" asientos disponibles\n";
                    cout<<"Se han vendido "<<entradasVendidas<<" entradas\n";
                    break;
                }
            }
            if(encontrado)break;
        }
        if(!encontrado){
            cout<<"Asiento no encontrado o ya esta ocupado.\nIntente nuevamente\n";
        }
        if(entradasCompradas<maxEntradas and (entradasTotales-entradasVendidas)>0){
            char opcion;
            cout<<"Desea seleccionar otro asiento? (s/n): ";
            opcion=validarRespuesta();
            if(opcion != 's'){
                break;
            }
        }
    }

    if((entradasTotales-entradasVendidas)==0){
        cout<<"Lo sentimos, todas las entradas se han vendido\n";
    }
}

bool validarCedulas(int cedula){
    for(int i=0;i<totalCedulas;i++){
        if(cedulasRegistradas[i]==cedula){
            cout<<"Error. La cedula ingresada ya se encuentra registrada. Intente nuevamente\n";
            return false;
        }
    }
    return true;
}

void registrarCedula(int cedula){
    int* nuevoArreglo=new int[totalCedulas+1];
    for(int i=0;i<totalCedulas;i++){
        nuevoArreglo[i]=cedulasRegistradas[i];
    }

    nuevoArreglo[totalCedulas]=cedula;
    totalCedulas++;

    delete[]cedulasRegistradas;
    cedulasRegistradas=nuevoArreglo;
}

void crearPersonas(string** graderia,int totalFilas, int totalColumnas, int* filas, int numeroSegmentos, string nombreEvento){
    ListaPersonas lista;
    string nombre;
    string fechaNacimiento;
    int cedula;
    char opcion;
    if((entradasTotales-entradasVendidas)==0){
        cout<<"Lo sentimos, todas las entradas se han vendido\n";
        return;
    }
    do{
        cout<<"Ingrese el nombre de la persona que compra\n";
        cin.ignore();
        getline(cin,nombre);
        int edad=-1;
        do{
        cout<<"Ingrese su fecha de nacimiento (con formato dd/mm/yyyy)\n";
        cin>>fechaNacimiento;
        edad=calcularEdad(fechaNacimiento);
        if(edad==-1){
            cout<<"Formato de fecha invalido\n";
        }
        else if(edad<18){
            cout<<"Lo sentimos, debe ser mayor de edad para poder realizar la compra\n";
            edad=-1;
        }
        }while(edad==-1);
        do{
        cout<<"Ingrese su numero de cedula\n";
        cin>>cedula;
        if(to_string(cedula).length()!=9){
            cout<<"Lo sentimos, debe ingresar una cedula de 9 digitos\n";
        }else if(!validarCedulas(cedula)){
            continue;
        }else{
            registrarCedula(cedula);
            break;
        }
        }while(true);

        lista.agregarPersonas(nombre, fechaNacimiento, cedula);
        cout<<"Seleccione sus asientos (5 como maximo)\n";
        imprimirGraderia(graderia,totalFilas,totalColumnas,filas,numeroSegmentos,nombreEvento);
        seleccionarAsientos(graderia,totalFilas,totalColumnas,5);
        if((entradasTotales-entradasVendidas)!=0){
        cout<<"Desea agregar otro comprador? (s/n): ";
        opcion=validarRespuesta();
        }
    }while(opcion=='s' and (entradasTotales-entradasVendidas)!=0);

    cout<<"Lista de compradores:\n";
    lista.mostrarPersonas();
}




int main(){
    int numeroSegmentos;
    int* filas=nullptr;
    int* columnas=nullptr;
    int* precio=nullptr;
    string nombreEvento;
    cout<<"Por favor, ingrese el nombre del evento\n";
    getline(cin,nombreEvento);
    crearSegmentos(numeroSegmentos, filas, columnas, precio);

    int totalFilas=0, totalColumnas=0;
    for(int i=0;i<numeroSegmentos;i++){
        totalFilas+=filas[i];
        if(columnas[i]>totalColumnas){
            totalColumnas=columnas[i];
        }
    }

    string** graderia=nullptr;
    inicializarGraderia(graderia, totalFilas, totalColumnas);
    llenarGraderia(graderia,filas,columnas,numeroSegmentos);
    imprimirGraderia(graderia, totalFilas, totalColumnas,filas,numeroSegmentos,nombreEvento);

    cout<<"\n\n\n";

    crearPersonas(graderia,totalFilas,totalColumnas, filas,numeroSegmentos,nombreEvento);

    cout<<"\nEstado final de la graderia:\n";
    imprimirGraderia(graderia,totalFilas,totalColumnas,filas,numeroSegmentos,nombreEvento);

    liberarMemoria(graderia,totalFilas);
    delete[]filas;
    delete[]columnas;
    delete[]cedulasRegistradas;


    return 0;
}