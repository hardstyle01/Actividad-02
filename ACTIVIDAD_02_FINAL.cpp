#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para la función transform
using namespace std;
// Definición de las estructuras
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
string nombres[] = {"Jorge", "Pedro", "Anabel", "Mario", "Carla", "Elizabeth", "Juan", "Marcos", "Manuel", "Cristina", "Lucia", "Luis", "Maria", "Fernando", "Gabriela"};
string apellidos[] = {"Ramirez", "Yabeta", "Diaz", "Hernandez", "Tito", "Sanchez", "Gomez", "Paniagua", "Robles", "Huari", "Torres", "Lopez", "Martinez", "Garcia", "Rodriguez"};
string generos[] = {"Suspenso", "Accion", "Romance", "Terror", "Comedia", "Ciencia ficcion", "Fantasia", "Drama", "Misterio", "Thriller"};
string areas[] = {"Caja", "Red", "Vestibulo", "Seguridad", "Limpieza", "Atención al cliente", "Recursos humanos", "Mantenimiento", "Marketing", "Administracion"};


int randomico(int max) {
	return rand() % max;
}

// Sobrecarga de la función de llenado para usuarios
void llenado(USUARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].userID = i + 1;
		p[i].nombre = nombres[randomico(15)];
		p[i].apellido = apellidos[randomico(15)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@gmail.com";
		p[i].librosborrados = randomico(10);
	}
}

// Sobrecarga de la función de llenado para bibliotecarios
void llenado(BIBLIOTECARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].employeeID = i + 101;
		p[i].nombre = nombres[randomico(15)];
		p[i].apellido = apellidos[randomico(15)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@yahoo.com.bo";
		p[i].area = areas[randomico(10)];
	}
}

// Sobrecarga de la función de llenado para libros
void llenado(LIBRO *p, int cant) {
	string titulos[] = {"Aprende PHP", "Aprende LINUX", "Aprende Python", "Aprende C++", "Introduccion a la Programacion en Java", "JavaScript para Principiantes", "HTML y CSS desde Cero", "Fundamentos de SQL", "Diseño de Algoritmos", "Inteligencia Artificial: Conceptos Basicos"};
	
	
	for (int i = 0; i < cant; i++) {
		p[i].titulo = titulos[i];
		p[i].autor = nombres[randomico(15)] +" " + apellidos[randomico(15)];
		p[i].ISBN = "ISBN-" + to_string(i + 1);
		p[i].publicationYear = 2000 + randomico(22);
		p[i].genero = generos[randomico(10)];
		p[i].precio = 10.0 + static_cast<float>(randomico(90));
		p[i].disponible = true;
	}
}

// Función auxiliar para convertir una cadena a minúsculas
string toLowercase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}



// Sobrecarga de la función de impresión para usuarios
void Imprimir(const USUARIO& persona) {
	cout << "ID: " << persona.userID << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Libros Prestados: " << persona.librosborrados << endl;
}

// Sobrecarga de la función de impresión para bibliotecarios
void Imprimir(const BIBLIOTECARIO& persona) {
	cout << "ID: " << persona.employeeID << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Area: " << persona.area << endl;
}

// Sobrecarga de la función de impresión para libros
void Imprimir(const LIBRO& libro) {
	cout << "Título: " << libro.titulo << " | ";
	cout << "Autor: " << libro.autor << " | ";
	cout << "ISBN: " << libro.ISBN << " | ";
	cout << "Año de publicación: " << libro.publicationYear << " | ";
	cout << "Género: " << libro.genero << " | ";
	cout << "Precio: BOB " << libro.precio << " | ";
	cout << "Disponible: " << (libro.disponible ? "Sí" : "No") << endl;
}

// Función auxiliar para convertir una cadena a minúsculas


// Función para imprimir lista completa de usuarios
void ImprimirListaCompleta(const USUARIO *arrUsuarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrUsuarios[i]);
	}
}

// Función para imprimir lista completa de bibliotecarios
void ImprimirListaCompleta(const BIBLIOTECARIO *arrBibliotecarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrBibliotecarios[i]);
	}
}

// Función para imprimir lista completa de libros
void ImprimirListaCompleta(const LIBRO *arrLibros, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrLibros[i]);
	}
}
bool BuscarLibroRecursivo(LIBRO *arrLibros, int cant, string terminacion) {
	bool encontrado = false;
	for (int i = 0; i < cant; ++i) {
		string tituloMinusculas = toLowercase(arrLibros[i].titulo);
		if (tituloMinusculas.find(terminacion) != string::npos) {
			Imprimir(arrLibros[i]);
			encontrado = true;
		}
	}
	return encontrado;
}

bool BuscarUsuarioRecursivo(USUARIO *arrUsuarios, int cant, string terminacion) {
	bool encontrado = false;
	for (int i = 0; i < cant; ++i) {
		string nombreMinusculas = toLowercase(arrUsuarios[i].nombre);
		string apellidoMinusculas = toLowercase(arrUsuarios[i].apellido);
		if (nombreMinusculas.find(terminacion) != string::npos || apellidoMinusculas.find(terminacion) != string::npos) {
			Imprimir(arrUsuarios[i]);
			encontrado = true;
		}
	}
	return encontrado;
}

bool BuscarBibliotecarioRecursivo(BIBLIOTECARIO *arrBibliotecarios, int cant, string terminacion) {
	bool encontrado = false;
	for (int i = 0; i < cant; ++i) {
		string nombreMinusculas = toLowercase(arrBibliotecarios[i].nombre);
		string apellidoMinusculas = toLowercase(arrBibliotecarios[i].apellido);
		if (nombreMinusculas.find(terminacion) != string::npos || apellidoMinusculas.find(terminacion) != string::npos) {
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
	
	cout << "3) Búsquedas" << endl;
	
	cout << "0) Salir" << endl;
	
	cout << "ELECCION: ";
}

void MostrarSubMenuBusquedaLibro(LIBRO *arrLibros, int cant) {
	LimpiarPantalla();
	string terminacion;
	cout << "Búsqueda de Libro (Título):" << endl;
	cout << "Ingrese título del libro: ";
	cin >> terminacion;
	
	// Realizar búsqueda por terminación del título
	bool encontrado = BuscarLibroRecursivo(arrLibros, cant, terminacion);
	
	if (!encontrado) {
		cout << "No se encontraron libros con ese título." << endl;
	}
}

void MostrarSubMenuBusquedaUsuario(USUARIO *arrUsuarios, int cant) {
	LimpiarPantalla();
	string terminacion;
	cout << "Búsqueda de Usuario (Nombre o Apellido):" << endl;
	cout << "Ingrese nombre o apellido del usuario: ";
	cin >> terminacion;
	
	// Realizar búsqueda por terminación del nombre o apellido
	bool encontrado = BuscarUsuarioRecursivo(arrUsuarios, cant, terminacion);
	
	if (!encontrado) {
		cout << "No se encontraron usuarios con ese nombre o apellido." << endl;
	}
}

void MostrarSubMenuBusquedaBibliotecario(BIBLIOTECARIO *arrBibliotecarios, int cant) {
	LimpiarPantalla();
	string terminacion;
	cout << "Búsqueda de Bibliotecario (Nombre o Apellido):" << endl;
	cout << "Ingrese nombre o apellido del bibliotecario: ";
	cin >> terminacion;
	
	// Realizar búsqueda por terminación del nombre o apellido
	bool encontrado = BuscarBibliotecarioRecursivo(arrBibliotecarios, cant, terminacion);
	
	if (!encontrado) {
		cout << "No se encontraron bibliotecarios con ese nombre o apellido." << endl;
	}
}



int main() {
	srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios
	
	const int TAM_USUARIOS = 10;
	const int TAM_BIBLIOTECARIOS = 12;
	const int TAM_LIBROS = 9;
	
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
				cout << "Submenú Listados:" << endl;
				cout << "A) Listado de Libros" << endl;
				cout << "B) Listado Usuarios" << endl;
				cout << "C) Listado Bibliotecarios" << endl;
				cout << "X) Salir al Menú Principal" << endl;
				cout << "Ingrese su elección: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'a':
					LimpiarPantalla();
					cout << "Listado de Libros:" << endl;
					ImprimirListaCompleta(arrLibros, TAM_LIBROS);
					break;
					
				case 'b':
					LimpiarPantalla();
					cout << "Listado de Usuarios:" << endl;
					ImprimirListaCompleta(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'c':
					LimpiarPantalla();
					cout << "Listado de Bibliotecarios:" << endl;
					ImprimirListaCompleta(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'x':
					cout << "Volviendo al Menú Principal." << endl;
					break;
					
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
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
				cout << "Submenú Búsquedas:" << endl;
				cout << "A) Búsqueda de Libro (TITULO)" << endl;
				cout << "B) Lista Búsqueda de Usuario (Nombre y Apellido)" << endl;
				cout << "C) Lista Búsqueda de Bibliotecario (Nombre y Apellido)" << endl;
				cout << "X) Salir al Menú Principal" << endl;
				cout << "Ingrese su elección: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'a':
					MostrarSubMenuBusquedaLibro(arrLibros, TAM_LIBROS);
					break;
					
				case 'b':
					MostrarSubMenuBusquedaUsuario(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'c':
					MostrarSubMenuBusquedaBibliotecario(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'x':
					cout << "Volviendo al Menú Principal." << endl;
					break;
					
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
				
				// Esperar a que el usuario presione Enter para continuar
				cout << "Presione Enter para continuar...";
				cin.ignore(); // Limpiar el buffer del teclado
				cin.get();    // Esperar a que se presione Enter
				
			} while (subopcion != 'X');
			
			break;
			
		case 0:
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
		
		// Esperar a que el usuario presione Enter para continuar
		cout << "Presione Enter para continuar...";
		cin.ignore(); // Limpiar el buffer del teclado
		cin.get();    // Esperar a que se presione Enter
		
	} while (opcion != 0);
	
	return 0;
}
