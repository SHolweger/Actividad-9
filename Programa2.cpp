#include <iostream>
using namespace std;

struct Estudiante {
  int * id;
  string * nombres;
  string * apellidos;
  double ** notas;
  double * promedio;
};

double calcular_promedio(double * notas, int columnas) {
  int suma = 0;
  for (int i = 0; i < columnas; i++) {
    suma += notas[i];
  }
  return suma / columnas;
}

int main() {
  cout << " Bienvenido al programa 2 - Calcular notas mediante punteros y estructuras\n - Por Sebastian Holweger" << endl;
  Estudiante estudiante;
  int fila = 0, columna = 0;
  cout << "Cuantos estudiantes desea agregar: ";
  cin >> fila;
  cout << "Cuantas notas desea ingresar: ";
  cin >> columna;

  estudiante.id = new int[fila];
  estudiante.nombres = new string[fila];
  estudiante.apellidos = new string[fila];
  estudiante.notas = new double * [fila];
  for (int i = 0; i < fila; i++) {
    estudiante.notas[i] = new double[columna];
  }
  estudiante.promedio = new double[fila];

  cout << " ================= Ingreso de Notas ================= " << endl;
  for (int i = 0; i < fila; i++) {
    cout << "ID: ";
    cin >> estudiante.id[i];
    cin.ignore();

    cout << "Nombres: ";
    getline(cin, estudiante.nombres[i]);
    cout << "Apellidos: ";
    getline(cin, estudiante.apellidos[i]);

    for (int ii = 0; ii < columna; ii++) {
      cout << "Ingrese nota: ";
      cin >> * ( * (estudiante.notas + i) + ii);
    }

    estudiante.promedio[i] = calcular_promedio(estudiante.notas[i], columna);
    cout << " =================================================== " << endl;
  }

  cout << " ================= Mostrar Datos ================= " << endl;
  for (int i = 0; i < fila; i++) {
    cout << "ID: " << estudiante.id[i] << endl;
    cout << "Nombre: " << estudiante.nombres[i] << endl;
    cout << "Apellidos: " << estudiante.apellidos[i] << endl;
    cout << "Promedio: " << estudiante.promedio[i] << endl;

    if (estudiante.promedio[i] > 60) {
      cout << "El/la estudiante ha aprobado." << endl;
    } else {
      cout << "El/la estudiante ha reprobado." << endl;
    }
    cout << " =================================================== " << endl;
  }

  for (int i = 0; i < fila; i++) {
    delete[] estudiante.notas[i];
  }
  delete[] estudiante.id;
  delete[] estudiante.nombres;
  delete[] estudiante.apellidos;
  delete[] estudiante.notas;

  return 0;
}