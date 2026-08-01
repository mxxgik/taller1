#include <iostream>
#include <string>

using namespace std;

const int MAX_AUTORES = 5;
const int MAX_LIBROS = 15;

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

void ingresarLibro(Libreria &libreria, int codigo, string titulo, string editorial, int existenciaMinima, int existenciaActual, float precio);
void mostrarLibros (Libreria &libreria);
void consultarInfo(Libreria &libreria, int codTemporalInfo);
void consultarExistencia (Libreria &libreria, int codTemporalEx);
void consultarAutores(Libreria &libreria, int codTemporalAut);
void ingresarAutorALibro(Libreria &libreria, int codigo, string nombre, string nacionalidad);
void registrarPedido(Libreria &libreria, int codigo, int cantidad);
bool venderLibro(Libreria &libreria, int codigo, int cantidad);

int main(){

    Libreria biblioteca = {{}, 0};

    cout << "\n--------Bienvenido al sistema de Librerias biblioteca--------" << endl;
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
            case 1:{
                string titulo, editorial;
                int exMin, exAct, codigo;
                float precio;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                cin.ignore();
                cout << "Ingrese el titulo del libro";
                getline(cin, titulo);
                cout << "Ingrese la editorial del libro";
                getline(cin, editorial);
                cout << "Ingrese la existencia minima del libro";
                cin >> exMin;
                cout << "Ingrese la existencia actual del libro";
                cin >> exAct;
                cout << "Ingrese el precio del libro";
                cin >> precio;
                ingresarLibro(biblioteca, codigo, titulo, editorial, exMin, exAct, precio);
                break;
            }
            case 2:{
                string nombre, nacionalidad, codigo;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                cin.ignore();
                cout << "Ingrese el nombre del autor";
                getline(cin, nombre);
                cout << "Ingrese la nacionalidad del autor";
                getline(cin, nacionalidad);
                break;
            }
            case 3:{
                int codigo, cantidad;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                cout << "Ingrese la cantidad de libros a vender";
                cin >> cantidad;
                registrarPedido(biblioteca, codigo, cantidad);
                break;
            }
            case 4:{
                int codigo, cantidad;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                cout << "Ingrese la cantidad de libros a vender";
                cin >> cantidad;
                bool vendido = venderLibro(biblioteca, codigo, cantidad);

                break;
            }
            case 5:{
                int codigo;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                consultarAutores(biblioteca, codigo);
                break;
            }
            case 6:{
                int codigo;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                consultarAutores(biblioteca, codigo);
                break;
            }
            case 7:{
                mostrarLibros(biblioteca);
                break;
            }
            case 8:{
                int codigo;
                cout << "Ingrese el codigo del libro";
                cin >> codigo;
                consultarInfo(biblioteca, codigo);
                break;
            }
            case 9:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no invalida.\n";
                break;
    }

    }while (opcion != 9);
}

void ingresarLibro(Libreria &libreria, int codigo, string titulo, string editorial, int existenciaMinima, int existenciaActual, float precio) {
    if (libreria.numLibros >= MAX_LIBROS) {
        cout << "No hay espacio para mas libros." << endl;
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
}


void mostrarLibros (Libreria &libreria) {
	cout << "\n----Libreria biblioteca----" << endl;
	for (int a = 0; a < libreria.numLibros; a++) {
		cout << "----- " << libreria.libros[a].titulo <<" -----" <<endl;
		cout << "Codigo --> " << libreria.libros[a].codigo << endl;
        for (int b = 0; b < MAX_AUTORES; b++){
		    cout << "Autor --> " << libreria.libros[a].autores[b].nombre << endl;
            cout << "Nacionalidad --> " << libreria.libros[a].autores[b].nacionalidad << endl;
        }
		cout << "Editorial --> " << libreria.libros[a].editorial << endl;
		cout << "Existencia Minima --> " << libreria.libros[a].existenciaMinima << endl;
		cout << "Existencia Actual --> " << libreria.libros[a].existenciaActual << endl;
		cout << "Precio --> " << libreria.libros[a].precio << endl;
		cout << "------------------------------------------" <<endl;
	}
}
void consultarInfo(Libreria &libreria, int codTemporalInfo) {
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalInfo == libreria.libros[i].codigo) {
            cout << "----Libreria biblioteca----" << endl;
            cout << "----- " << libreria.libros[i].titulo << " -----" << endl;
            cout << "Codigo --> " << libreria.libros[i].codigo << endl;
            for (int b = 0; b < libreria.libros[i].numAutores; b++) {
                cout << "Autor --> " << libreria.libros[i].autores[b].nombre << endl;
                cout << "Nacionalidad --> " << libreria.libros[i].autores[b].nacionalidad << endl;
            }
            cout << "Editorial --> " << libreria.libros[i].editorial << endl;
            cout << "Existencia Minima --> " << libreria.libros[i].existenciaMinima << endl;
            cout << "Existencia Actual --> " << libreria.libros[i].existenciaActual << endl;
            cout << "Precio --> " << libreria.libros[i].precio << endl;
            cout << "------------------------------------------" << endl;
            return;
        }
    } 
    cout << "No se encontro un libro con ese codigo" << endl;
}
void consultarExistencia (Libreria &libreria, int codTemporalEx){
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalEx == libreria.libros[i].codigo){
        cout << "----Libreria biblioteca----" << endl;
        cout << "Existencia Minima --> " << libreria.libros[i].existenciaMinima << endl;
		cout << "Existencia Actual --> " << libreria.libros[i].existenciaActual << endl;
        cout << "------------------------------------------" <<endl;
        return;
         }
    }
    cout << "No se encontro un libro con ese codigo" << endl;
}

void consultarAutores(Libreria &libreria, int codTemporalAut) {
    for (int i = 0; i < libreria.numLibros; i++) {
        if (codTemporalAut == libreria.libros[i].codigo) {
            cout << "----Libreria biblioteca----" << endl;
            cout << "----- " << libreria.libros[i].titulo << " -----" << endl;
            for (int b = 0; b < libreria.libros[i].numAutores; b++) {
                cout << "Autor --> " << libreria.libros[i].autores[b].nombre << endl;
                cout << "Nacionalidad --> " << libreria.libros[i].autores[b].nacionalidad << endl;
         }
            return;
       }
    }
    cout << "No se encontro un libro con ese codigo." << endl;
}
