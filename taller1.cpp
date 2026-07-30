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
    int existenciaAcual;
    float precio;
    int numAutores;
};

struct Libreria{
    Libro libros[MAX_LIBROS];
    int numLibros;
};

void ingresarLibro();
void ingresarAutorALibro();
void registrarPedido();
bool venderLibro();
bool venderLibro();

int main(){

    Libreria javeriana = {{}, 0};

    cout << "--------Bienvenido al sistema de Librerias Javeriana--------" << endl;
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
                string codigo, titulo, editorial;
                int exMin, exMax;
                float precio;
                cout << "Ingrese el codigo del libro";
                getline(cin, titulo);
                cout << "Ingrese el titulo del libro";
                getline(cin, titulo);
                cout << "Ingrese la editorial del libro";
                getline(cin, titulo);
                cout << "Ingrese la existencia minima del libro";
                cin >> exMin;
                cout << "Ingrese la existencia actual del libro";
                cin >> exMax;
                cout << "Ingrese el precio del libro";
                cin >> precio;
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
                string codigo;
                break;
            }
            case 4:{

                break;
            }
            case 5:{

                break;
            }
            case 6:{

                break;
            }
            case 7:{

                break;
            }
            case 8:{

                break;
            }
            case 9:
                cout << "Saliendo...";
                break;
            default:
                cout << "Opcion no invalida.";
                break;
    }

    }while (opcion != 9);
}
