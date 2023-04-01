#include <iostream>

using namespace std;

const char* nombre_archivo = "notas.dat"; // nombre del archivo donde se almacenarán los datos

struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    double notas[4];
    double promedio;
    char resultado[10];
};

void Crear(Estudiante* estudiantes, int n) {
     system("cls"); 
    FILE* archivo = fopen(nombre_archivo,"a+b");
    for (int i = 0; i < n; i++) {
        estudiantes[i].id = i + 1;
        cin.ignore();
        cout << "Ingrese nombres del estudiante " << i + 1 << ": ";
        cin.getline(estudiantes[i].nombres, 50);
        cout << "Ingrese apellidos del estudiante " << i + 1 << ": ";
        cin.getline(estudiantes[i].apellidos, 50);
        for (int j = 0; j < 4; j++) {
            cout << "Ingrese nota " << j + 1 << " del estudiante " << i + 1 << ": ";
            cin >> estudiantes[i].notas[j];
            estudiantes[i].promedio += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio /= 4;
        if (estudiantes[i].promedio >= 60) {
            strcpy(estudiantes[i].resultado, "APROBADO");
        }
        else {
            strcpy(estudiantes[i].resultado, "REPROBADO");
        }
        fwrite(&estudiantes[i], sizeof(Estudiante), 1, archivo); 
    }
    fclose(archivo);
}

void Leer() {
     system("cls"); //funcion para borrar los datos y todo lo que esta dentro de la pantalla de la consola.
    FILE* archivo = fopen(nombre_archivo,"rb"); 
    if (!archivo){
    archivo = fopen(nombre_archivo,"w+b"); 
    }
   Estudiante estudiante; //el tamaño
    int id=0; // indice o posicion del registro (fila) dentro del archivo
    fread(&estudiante,sizeof(Estudiante),1,archivo);
    cout<<"____________________________________________________________"<<endl;
    cout<<"ID"<<"|"<<" Nombres "<<"|"<<"   Apellidos   "<<"|"<<"    N1 "<<"|"<<" N2"<<"|"<<" N3"<<"|"<<"N4"<<"|"<<" Promedio "<<"|"<<"  Resultado "<<endl;

    do
    {
        cout<<id<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.notas[0]<<"|"<<estudiante.notas[1]<<"|"<<estudiante.notas[2]<<"|"<<estudiante.notas[3]<<"|    "<<estudiante.promedio<<"|      "<<estudiante.resultado<<endl;
        id+=1;
        fread(&estudiante,sizeof(Estudiante),1,archivo);
    } while (feof(archivo)==0); //hasta que ya no encuentre elementos no se va a ejecutar
    fclose(archivo);
}

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes que desea registrar: ";
    cin >> n;
    Estudiante* estudiantes = new Estudiante[n]; // crear un arreglo dinámico de estudiantes
    Crear(estudiantes, n); // guardar los datos en el archivo
    Leer(); // mostrar los datos del archivo
    delete[] estudiantes; // liberar la memoria del arreglo dinámico
    return 0;
}
