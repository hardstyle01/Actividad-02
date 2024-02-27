#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para la funci�n transform
using namespace std;
// Definici�n de las estructuras
struct LIBRO {
	string titulo;
	string autor;
	string ISBN;
	int publicationYear;
	string genero;
	float precio;
	bool disponible;
};

struct USUARIO {
	int userID;
	string nombre;
	string apellido;
	string correo;
	int librosborrados;
};

struct BIBLIOTECARIO {
	int employeeID;
	string nombre;
	string apellido;
	string correo;
	string area;
};

// Listas fijas de nombres y apellidos de ejemplo
string nombres[] = {"Jorge", "Pedro", "Anabel", "Mario", "Carla", "Elizabeth", "Juan", "Marcos", "Manuel", "Cristina"};
string apellidos[] = {"Ramirez", "Yabeta", "Diaz", "Hernandez", "Tito", "Sanchez", "Gomez", "Paniagua", "Robles", "Huari"};
string generos[] = {"Suspenso", "Accion", "Romance", "Terror", "Comedia"};
string areas[] = {"Caja", "Red", "Vestibulo", "Seguridad", "Limpieza"};

int randomico(int max) {
	return rand() % max;
}

// Sobrecarga de la funci�n de llenado para usuarios
void llenado(USUARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].userID = i + 1;
		p[i].nombre = nombres[randomico(10)];
		p[i].apellido = apellidos[randomico(10)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@gmail.com";
		p[i].librosborrados = randomico(5);
	}
}

// Sobrecarga de la funci�n de llenado para bibliotecarios
void llenado(BIBLIOTECARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].employeeID = i + 101;
		p[i].nombre = nombres[randomico(10)];
		p[i].apellido = apellidos[randomico(10)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@yahoo.com.bo";
		p[i].area = areas[randomico(5)];
	}
}

// Sobrecarga de la funci�n de llenado para libros
void llenado(LIBRO *p, int cant) {
	string titulos[] = {"Aprende PHP", "Aprende LINUX", "Aprende Python", "Aprende C++"};
	
	for (int i = 0; i < cant; i++) {
		p[i].titulo = titulos[i];
		p[i].autor = nombres[randomico(10)] + " " + apellidos[randomico(10)];
		p[i].ISBN = "ISBN-" + to_string(i + 1);
		p[i].publicationYear = 2000 + randomico(22);
		p[i].genero = generos[randomico(5)];
		p[i].precio = 10.0 + static_cast<float>(randomico(90));
		p[i].disponible = true;
	}
}

// Funci�n auxiliar para convertir una cadena a min�sculas
string toLowercase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}


// Sobrecarga de la funci�n de impresi�n para usuarios
void Imprimir(const USUARIO& persona) {
	cout << "ID: " << persona.userID << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Libros Prestados: " << persona.librosborrados << endl;
}

// Sobrecarga de la funci�n de impresi�n para bibliotecarios
void Imprimir(const BIBLIOTECARIO& persona) {
	cout << "ID: " << persona.employeeID << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Area: " << persona.area << endl;
}

// Sobrecarga de la funci�n de impresi�n para libros
void Imprimir(const LIBRO& libro) {
	cout << "T�tulo: " << libro.titulo << " | ";
	cout << "Autor: " << libro.autor << " | ";
	cout << "ISBN: " << libro.ISBN << " | ";
	cout << "A�o de publicaci�n: " << libro.publicationYear << " | ";
	cout << "G�nero: " << libro.genero << " | ";
	cout << "Precio: BOB " << libro.precio << " | ";
	cout << "Disponible: " << (libro.disponible ? "S�" : "No") << endl;
}

// Funci�n auxiliar para convertir una cadena a min�sculas


// Funci�n para imprimir lista completa de usuarios
void ImprimirListaCompleta(const USUARIO *arrUsuarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrUsuarios[i]);
	}
}

// Funci�n para imprimir lista completa de bibliotecarios
void ImprimirListaCompleta(const BIBLIOTECARIO *arrBibliotecarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrBibliotecarios[i]);
	}
}

// Funci�n para imprimir lista completa de libros
void ImprimirListaCompleta(const LIBRO *arrLibros, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrLibros[i]);
	}
}
bool BuscarLibroRecursivo(LIBRO *arrLibros, int cant, string tituloBuscado) {
	bool encontrado = false;
	// Convertir el t�rmino de b�squeda a min�sculas
	tituloBuscado = toLowercase(tituloBuscado);
	for (int i = 0; i < cant; ++i) {
		// Convertir el t�tulo del libro a min�sculas para la comparaci�n
		string tituloMinusculas = toLowercase(arrLibros[i].titulo);
		if (tituloMinusculas.find(tituloBuscado) != string::npos) {
			Imprimir(arrLibros[i]);
			encontrado = true;
		}
	}
	return encontrado;
}
		
bool BuscarUsuarioRecursivo(USUARIO *arrUsuarios, int cant, string nombreOApellido) {
	bool encontrado = false;
	// Convertir el t�rmino de b�squeda a min�sculas
	nombreOApellido = toLowercase(nombreOApellido);
	for (int i = 0; i < cant; ++i) {
		// Convertir el nombre y el apellido del usuario a min�sculas para la comparaci�n
		string nombreMinusculas = toLowercase(arrUsuarios[i].nombre);
		string apellidoMinusculas = toLowercase(arrUsuarios[i].apellido);
		if (nombreMinusculas == nombreOApellido || apellidoMinusculas == nombreOApellido) {
			Imprimir(arrUsuarios[i]);
			encontrado = true;
		}
	}
	return encontrado;
}

bool BuscarBibliotecarioRecursivo(BIBLIOTECARIO *arrBibliotecarios, int cant, string nombreOApellido) {
	bool encontrado = false;
	// Convertir el t�rmino de b�squeda a min�sculas
	nombreOApellido = toLowercase(nombreOApellido);
	for (int i = 0; i < cant; ++i) {
		// Convertir el nombre y el apellido del bibliotecario a min�sculas para la comparaci�n
		string nombreMinusculas = toLowercase(arrBibliotecarios[i].nombre);
		string apellidoMinusculas = toLowercase(arrBibliotecarios[i].apellido);
		if (nombreMinusculas == nombreOApellido || apellidoMinusculas == nombreOApellido) {
			Imprimir(arrBibliotecarios[i]);
			encontrado = true;
		}
	}
	return encontrado;
}


void LimpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void MostrarMenu() {
	cout << "MENU:" << endl;
	cout << "1) Llenado de Datos" << endl;
	
	cout << "2) Listados" << endl;
	
	cout << "3) B�squedas" << endl;
	
	cout << "0) Salir" << endl;
	
	cout << "ELECCION: ";
}

void MostrarSubMenuBusquedaLibro(LIBRO *arrLibros, int cant) {
	LimpiarPantalla();
	string tituloBuscado;
	cout << "B�squeda de Libro (T�tulo):" << endl;
	cout << "Ingrese el t�tulo del libro: ";
	cin.ignore();
	getline(cin, tituloBuscado);
	
	// Realizar b�squeda por t�tulo
	bool encontrado = BuscarLibroRecursivo(arrLibros, cant, tituloBuscado);
	
	if (!encontrado) {
		cout << "No se encontraron libros con ese t�tulo." << endl;
	}
}

void MostrarSubMenuBusquedaUsuario(USUARIO *arrUsuarios, int cant) {
	LimpiarPantalla();
	string nombreOApellido;
	cout << "B�squeda de Usuario (Nombre o Apellido):" << endl;
	cout << "Ingrese el nombre o apellido del usuario: ";
	cin >> nombreOApellido;
	
	// Realizar b�squeda por nombre o apellido
	bool encontrado = BuscarUsuarioRecursivo(arrUsuarios, cant, nombreOApellido);
	
	if (!encontrado) {
		cout << "No se encontraron usuarios con ese nombre o apellido." << endl;
	}
}


void MostrarSubMenuBusquedaBibliotecario(BIBLIOTECARIO *arrBibliotecarios, int cant) {
	LimpiarPantalla();
	string nombreOApellido;
	cout << "B�squeda de Bibliotecario (Nombre o Apellido):" << endl;
	cout << "Ingrese el nombre o apellido del bibliotecario: ";
	cin >> nombreOApellido;
	
	// Realizar b�squeda por nombre o apellido
	bool encontrado = BuscarBibliotecarioRecursivo(arrBibliotecarios, cant, nombreOApellido);
	
	if (!encontrado) {
		cout << "No se encontraron bibliotecarios con ese nombre o apellido." << endl;
	}
}




int main() {
	srand(time(NULL)); // Inicializar la semilla del generador de n�meros aleatorios
	
	const int TAM_USUARIOS = 4;
	const int TAM_BIBLIOTECARIOS = 3;
	const int TAM_LIBROS = 4;
	
	USUARIO arrUsuarios[TAM_USUARIOS];
	BIBLIOTECARIO arrBibliotecarios[TAM_BIBLIOTECARIOS];
	LIBRO arrLibros[TAM_LIBROS];
	
	int opcion;
	char subopcion;
	
	do {
		LimpiarPantalla();
		MostrarMenu();
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenado(arrUsuarios, TAM_USUARIOS);
			llenado(arrBibliotecarios, TAM_BIBLIOTECARIOS);
			llenado(arrLibros, TAM_LIBROS);
			cout << "Datos llenados exitosamente." << endl;
			break;
			
		case 2:
			do {
				LimpiarPantalla();
				cout << "Submen� Listados:" << endl;
				cout << "A) Listado de Libros" << endl;
				cout << "B) Listado Usuarios" << endl;
				cout << "C) Listado Bibliotecarios" << endl;
				cout << "X) Salir al Men� Principal" << endl;
				cout << "Ingrese su elecci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
					LimpiarPantalla();
					cout << "Listado de Libros:" << endl;
					ImprimirListaCompleta(arrLibros, TAM_LIBROS);
					break;
					
				case 'B':
					LimpiarPantalla();
					cout << "Listado de Usuarios:" << endl;
					ImprimirListaCompleta(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'C':
					LimpiarPantalla();
					cout << "Listado de Bibliotecarios:" << endl;
					ImprimirListaCompleta(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'X':
					cout << "Volviendo al Men� Principal." << endl;
					break;
					
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
				}
				
				// Esperar a que el usuario presione Enter para continuar
				cout << "Presione Enter para continuar...";
				cin.ignore(); // Limpiar el buffer del teclado
				cin.get();    // Esperar a que se presione Enter
				
			} while (subopcion != 'X');
			
			break;
			
		case 3:
			do {
				LimpiarPantalla();
				cout << "Submen� B�squedas:" << endl;
				cout << "A) B�squeda de Libro (TITULO)" << endl;
				cout << "B) Lista B�squeda de Usuario (Nombre y Apellido)" << endl;
				cout << "C) Lista B�squeda de Bibliotecario (Nombre y Apellido)" << endl;
				cout << "X) Salir al Men� Principal" << endl;
				cout << "Ingrese su elecci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
					MostrarSubMenuBusquedaLibro(arrLibros, TAM_LIBROS);
					break;
					
				case 'B':
					MostrarSubMenuBusquedaUsuario(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'C':
					MostrarSubMenuBusquedaBibliotecario(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'X':
					cout << "Volviendo al Men� Principal." << endl;
					break;
					
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
				}
				
				// Esperar a que el usuario presione Enter para continuar
				cout << "Presione Enter para continuar...";
				cin.ignore(); // Limpiar el buffer del teclado
				cin.get();    // Esperar a que se presione Enter
				
			} while (subopcion != 'X');
			
			break;
			
		case 0:
			cout << "Saliendo del programa. �Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
		}
		
		// Esperar a que el usuario presione Enter para continuar
		cout << "Presione Enter para continuar...";
		cin.ignore(); // Limpiar el buffer del teclado
		cin.get();    // Esperar a que se presione Enter
		
	} while (opcion != 0);
	
	return 0;
}
