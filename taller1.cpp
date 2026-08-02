#include <iostream>
#include <string>

using namespace std;

// Definicion de constantes
const int MAX_AUTORES = 5;
const int MAX_LIBROS = 15;

//Definicion de estructuras
struct Autor{
    string nombre;
    string nacionalidad;
};

struct Libro{
    int codigo;
    string titulo;
    Autor autores[MAX_AUTORES];
    string editorial;
    int existenciaMinima;
    int existenciaActual;
    float precio;
    int numAutores;
};

struct Libreria{
    Libro libros[MAX_LIBROS];
    int numLibros;
};

//Encabezados de funciones
void ingresarLibro(Libreria &libreria, int codigo, string titulo, string editorial, int existenciaMinima, int existenciaActual, float precio);
void mostrarLibros (Libreria &libreria);
void consultarInfo(Libreria &libreria, int codTemporalInfo);
void consultarExistencia (Libreria &libreria, int codTemporalEx);
void consultarAutores(Libreria &libreria, int codTemporalAut);
void ingresarAutorALibro(Libreria &libreria, int codigo, string nombre, string nacionalidad);
void registrarPedido(Libreria &libreria, int codigo, int cantidad);
bool venderLibro(Libreria &libreria, int codigo, int cantidad);

// Punto de entrada
int main(){

    Libreria biblioteca = {{}, 0};

    cout << "\n--------Bienvenido al sistema de Librerias Javeriana--------" << endl;
    int opcion;

    do {
        cout << "1) Ingresar libro" << endl;
        cout << "2) Ingresar autor a un libro" << endl;
        cout << "3) Registrar pedido de un libro" << endl;
        cout << "4) Venta de un libro" << endl;
        cout << "5) Consultar existencias de un libro" << endl;
        cout << "6) Consultar autores de un libro" << endl;
        cout << "7) Mostrar todos los libros" << endl;
        cout << "8) Consultar informacion de un libro" << endl;
        cout << "9) Salir. " << endl;
        cin >> opcion;

        switch (opcion) {

            //Opcion 1, Ingresar Libros
            case 1:{
                string titulo, editorial;
                int exMin, exAct, codigo;
                float precio;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                cin.ignore();
                cout << "Ingrese el titulo del libro: ";
                getline(cin, titulo);
                cout << "Ingrese la editorial del libro: ";
                getline(cin, editorial);
                cout << "Ingrese la existencia minima del libro: ";
                cin >> exMin;
                cout << "Ingrese la existencia actual del libro: ";
                cin >> exAct;
                cout << "Ingrese el precio del libro: ";
                cin >> precio;
                ingresarLibro(biblioteca, codigo, titulo, editorial, exMin, exAct, precio);
                break;
            }

            //Opcion 2, Ingresar Autor a un libro
            case 2:{
                string nombre, nacionalidad;
                int codigo;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                cin.ignore();
                cout << "Ingrese el nombre del autor: ";
                getline(cin, nombre);
                cout << "Ingrese la nacionalidad del autor: ";
                getline(cin, nacionalidad);
                ingresarAutorALibro(biblioteca, codigo, nombre, nacionalidad);
                break;
            }

            //Opcion 3, Registrar un pedido de libros
            case 3:{
                int codigo, cantidad;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                cout << "Ingrese la cantidad de libros a vender: ";
                cin >> cantidad;
                registrarPedido(biblioteca, codigo, cantidad);
                break;
            }

            //Opcion 4, Vender libros
            case 4:{
                int codigo, cantidad;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                cout << "Ingrese la cantidad de libros a vender: ";
                cin >> cantidad;
                bool vendido = venderLibro(biblioteca, codigo, cantidad);
                if (vendido) {
                    cout << "Venta realizada con exito" << endl;
                }
                break;
            }

            //Opcion 5, Consultar existencias de un libro
            case 5:{
                int codigo;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                consultarExistencia(biblioteca, codigo);
                break;
            }

            //Opcion 6, Consultar autores de un libro en especifico
            case 6:{
                int codigo;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                consultarAutores(biblioteca, codigo);
                break;
            }

            //Opcion 7, Mostrar todos los libros de la libreria
            case 7:{
                mostrarLibros(biblioteca);
                break;
            }

            //Opcion 8, Consultar informacion de un libro en especifico
            case 8:{
                int codigo;
                cout << "Ingrese el codigo del libro: ";
                cin >> codigo;
                consultarInfo(biblioteca, codigo);
                break;
            }
            //Opcion 9, Salir del programa
            case 9:
                cout << "Saliendo...\n";
                break;

            //Default, informar al usuario de una opcion invalida
            default:
                cout << "Opcion invalida.\n";
                break;
    }

    }while (opcion != 9);
}

/*
*
*
*
*
* */
void ingresarLibro(Libreria &libreria, int codigo, string titulo, string editorial, int existenciaMinima, int existenciaActual, float precio) {
    if (libreria.numLibros >= MAX_LIBROS) {
        cout << "No hay espacio para mas libros." << endl;
        return;
    }
    for (int i = 0; i < libreria.numLibros; i++) {
        if (libreria.libros[i].codigo == codigo) {
            cout << "Ya existe un libro con el codigo ingresado." << endl;
            return;
        }
    }

    if (existenciaMinima < 0 || existenciaActual < 0 || precio < 0) {
        cout << "La existencia y el precio no pueden ser negativos" << endl;
        return;
    }

    int i = libreria.numLibros;
    libreria.libros[i].codigo = codigo;
    libreria.libros[i].titulo = titulo;
    libreria.libros[i].editorial = editorial;
    libreria.libros[i].existenciaMinima = existenciaMinima;
    libreria.libros[i].existenciaActual = existenciaActual;
    libreria.libros[i].precio = precio;
    libreria.libros[i].numAutores = 0;
 
    libreria.numLibros++;
    return;
}

void mostrarLibros (Libreria &libreria) {
    cout << "\n----Libreria Javeriana----" << endl;
    for (int i = 0; i < libreria.numLibros; i++) {
        cout << "----- " << libreria.libros[i].titulo <<" -----" <<endl;
        cout << "Codigo: " << libreria.libros[i].codigo << endl;
        for (int j = 0; j < libreria.libros[i].numAutores; j++){
            cout << "Autor: " << libreria.libros[i].autores[j].nombre << endl;
            cout << "Nacionalidad: " << libreria.libros[i].autores[j].nacionalidad << endl;
        }
        cout << "Editorial: " << libreria.libros[i].editorial << endl;
        cout << "Existencia Minima: " << libreria.libros[i].existenciaMinima << endl;
        cout << "Existencia Actual: " << libreria.libros[i].existenciaActual << endl;
        cout << "Precio: " << libreria.libros[i].precio << endl;
        cout << "------------------------------------------" <<endl;
    }
    return;
}

void consultarInfo(Libreria &libreria, int codTemporalInfo) {
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalInfo == libreria.libros[i].codigo) {
            cout << "----Libreria bibliotenca----" << endl;
            cout << "----- " << libreria.libros[i].titulo << " -----" << endl;
            cout << "Codigo: " << libreria.libros[i].codigo << endl;
            for (int j = 0; j < libreria.libros[i].numAutores; j++) {
                cout << "Autor: " << libreria.libros[i].autores[j].nombre << endl;
                cout << "Nacionalidad: " << libreria.libros[i].autores[j].nacionalidad << endl;
            }
            cout << "Editorial: " << libreria.libros[i].editorial << endl;
            cout << "Existencia Minima: " << libreria.libros[i].existenciaMinima << endl;
            cout << "Existencia Actual: " << libreria.libros[i].existenciaActual << endl;
            cout << "Precio: " << libreria.libros[i].precio << endl;
            cout << "------------------------------------------" << endl;
            return;
        }
    } 
    cout << "No se encontro un libro con ese codigo" << endl;
}

void consultarExistencia (Libreria &libreria, int codTemporalEx){
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalEx == libreria.libros[i].codigo){
        cout << "----Libreria Javeriana----" << endl;
        cout << "Existencia Minima: " << libreria.libros[i].existenciaMinima << endl;
        cout << "Existencia Actual: " << libreria.libros[i].existenciaActual << endl;
        cout << "------------------------------------------" <<endl;
        return;
         }
    }
    cout << "No se encontro un libro con ese codigo" << endl;
}

void consultarAutores(Libreria &libreria, int codTemporalAut) {
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalAut == libreria.libros[i].codigo) {
            cout << "----Libreria Javeriana----" << endl;
            cout << "----- " << libreria.libros[i].titulo << " -----" << endl;
            for (int j = 0; j < libreria.libros[i].numAutores; j++) {
                cout << "Autor: " << libreria.libros[i].autores[j].nombre << endl;
                cout << "Nacionalidad: " << libreria.libros[i].autores[j].nacionalidad << endl;
         }
            return;
       }
    }
    cout << "No se encontro un libro con ese codigo." << endl;
}

void ingresarAutorALibro(Libreria &libreria, int codigo, string nombre, string nacionalidad) {
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codigo == libreria.libros[i].codigo) {
            if (libreria.libros[i].numAutores >= MAX_AUTORES) {
                cout << "No hay espacio para mas autores en este libro." << endl;
                return;
            }

            libreria.libros[i].autores[libreria.libros[i].numAutores].nombre = nombre;
            libreria.libros[i].autores[libreria.libros[i].numAutores].nacionalidad = nacionalidad;
            libreria.libros[i].numAutores++;
            cout << "Autor agregado con exito." << endl;
            return;
        }
    }
    cout << "No se encontro un libro con ese codigo." << endl;
}
 
void registrarPedido(Libreria &libreria, int codigo, int cantidad) {

    if (cantidad <= 0) {
        cout << "La cantidad debe ser un numero mayor que 0" << endl;
        return;
    }

    for (int i = 0; i < libreria.numLibros; i++) {
        if (codigo == libreria.libros[i].codigo) {
            libreria.libros[i].existenciaActual = libreria.libros[i].existenciaActual + cantidad;
            cout << "Pedido registrado con exito." << endl;
            return;
        }
    }
    cout << "No se encontro un libro con ese codigo." << endl;
}

bool venderLibro(Libreria &libreria, int codigo, int cantidad) {

    if(cantidad <= 0){
        cout << "La cantidad debe ser un numero mayor que 0" << endl;
        return false;
    }

    for (int i = 0; i < libreria.numLibros; i++) {
        if (codigo == libreria.libros[i].codigo) {
            if (libreria.libros[i].existenciaActual < cantidad) {
                cout << "No hay suficientes existencias de ese libro." << endl;
                return false;
            }
            libreria.libros[i].existenciaActual = libreria.libros[i].existenciaActual - cantidad;
            return true;
        }
    }
    cout << "No se encontro un libro con ese codigo." << endl;
    return false;
}
