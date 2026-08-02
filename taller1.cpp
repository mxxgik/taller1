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


//Declaracion de la funcion para ingresar un libro a la libreria
/*

libreria: estructura Libreria donde se va a ingresar el libro
codigo: codigo unico que identifica al libro
titulo: titulo del libro
editorial: editorial que publico el libro
existenciaMinima: cantidad minima de existencias a las que debe mantenerse del libro
existenciaActual: cantidad actual de existencias del libro
precio: precio de venta del libro

Esta funcion agrega un nuevo libro al arreglo de libros de la libreria, validando
que haya espacio disponible, que el codigo no este repetido y que la existencia
y el precio no sean negativos. El libro se ingresa inicialmente sin autores.
*/
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

//Declaracion de la funcion para mostrar todos los libros de la libreria
/*

libreria: estructura Libreria que contiene el arreglo de libros a mostrar

Esta funcion recorre todos los libros registrados en la libreria y muestra por
pantalla su informacion completa: codigo, autores con su nacionalidad, editorial,
existencia minima, existencia actual y precio.
*/
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

//Declaracion de la funcion para consultar la informacion completa de un libro
/*

libreria: estructura Libreria donde se realiza la busqueda
codTemporalInfo: codigo del libro que se desea consultar

Funcion que busca un libro por su codigo dentro del arreglo de libros y, si lo
encuentra, muestra toda su informacion: titulo, codigo, autores con su
nacionalidad, editorial, existencia minima, existencia actual y precio. Si no
encuentra un libro con ese codigo, informa al usuario.
*/
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


//Declaracion de la funcion para consultar la existencia de un libro
/*

libreria: estructura Libreria donde se realiza la busqueda
codTemporalEx: codigo del libro cuya existencia se desea consultar

Busca un libro por su codigo y, si lo encuentra, muestra su
existencia minima y su existencia actual. Si no encuentra un libro con ese
codigo, informa al usuario.
*/
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

//Declaracion de la funcion para consultar los autores de un libro
/*

libreria: estructura Libreria donde se realiza la busqueda
codTemporalAut: codigo del libro cuyos autores se desean consultar

Esta funcion busca un libro por su codigo y, si lo encuentra, muestra el titulo
del libro junto con el nombre y la nacionalidad de cada uno de sus autores. Si
no encuentra un libro con ese codigo, informa al usuario.
*/
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

//Declaracion de la funcion para ingresar un autor a un libro existente
/*

libreria: estructura Libreria donde se realiza la busqueda
codigo: codigo del libro al cual se le va a agregar el autor
nombre: nombre completo del autor a agregar
nacionalidad: nacionalidad del autor a agregar

Funcion que busca un libro por su codigo y, si lo encuentra, agrega un nuevo
autor a su arreglo de autores, validando primero que haya espacio disponible.
Si no encuentra un libro con ese codigo, informa al usuario.
*/
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
 
//Declaracion de la funcion para registrar el pedido de un libro
/*

libreria: estructura Libreria donde se realiza la busqueda
codigo: codigo del libro al cual se le va a registrar el pedido
cantidad: cantidad de ejemplares que llegaron en el pedido

Funcion que busca un libro por su codigo y, si lo encuentra, aumenta su
existencia actual en la cantidad indicada, validando primero que la cantidad
sea mayor que cero. Si no encuentra un libro con ese codigo, informa al usuario.
*/
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

//Declaracion de la funcion para vender una cantidad de un libro
/*

libreria: estructura Libreria donde se realiza la busqueda
codigo: codigo del libro que se desea vender
cantidad: cantidad de ejemplares a vender

Funcion que busca un libro por su codigo y, si lo encuentra, disminuye su
existencia actual en la cantidad indicada, validando que la cantidad sea mayor
que cero y que haya suficiente existencia disponible. Retorna true si la venta
se realizo con exito y false si la cantidad es invalida, si no hay suficientes
existencias o si no se encuentra un libro con ese codigo.
*/
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
