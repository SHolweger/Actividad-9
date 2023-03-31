#include <iostream>
using namespace std;

int main() {
  int n = 0, id = 0;
  string nombres, apellidos;
//Cantidad de estudiantes
  cout << "Bienvenido al programa 1 - Calcular promedio de notas mediante arreglos - Por Sebastian Holweger" << endl;
  cout << "Ingrese la cantidad de estudiantes: ";
  cin >> n;

  double nota[n][4];
  double promedio = 0;
//SOlicito datos
  for (int a = 0; a < n; a++) {
    cout << "Ingrese ID: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese nombres: ";
    getline(cin, nombres);
    cout << "Ingrese apellidos: ";
    getline(cin, apellidos);
    for (int b = 0; b < 4; b++) {
      cout << "Ingrese nota " << b+1 << " del estudiante " << a+1 << ": ";
      cin >> nota[a][b];
    }
    // Para Calcular promedio
    promedio = (nota[a][0] + nota[a][1] + nota[a][2] + nota[a][3]) / 4;
    // Determinar si el estudiante aprobó o reprobó
    if (promedio > 60) {
      cout << "El estudiante " << nombres << " " << apellidos << " con ID " << id << " ha APROBADO con un promedio de " << promedio << endl;
    } else {
      cout << "El estudiante " << nombres << " " << apellidos << " con ID: " << id << " ha REPROBADO con un promedio de " << promedio << endl;
    }
  }
  return 0;
}
