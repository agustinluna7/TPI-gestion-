#include <iostream>

using namespace std;

int main()
{
const int TAM=10;
int codigos [TAM];
string nombres[TAM];

  int contador=0;

  cout << "-------lote de marcas------" << endl;

while (contador < TAM)
    {
     int codigo;
string nombre;

  cout << "marca " << contador +1 << ":"<< endl;
  cout <<"ingrese el codigo (entre 1 y 10): ";
  cin>>codigo;

  if (codigo >= 1 && codigo <=10)
    {
     cin.ignore();
     cout << "ingrese nombre: " ;
     getline (cin, nombre);

     if (nombre!="")
        {
         codigos[contador]=codigo;
         nombres[contador]=nombre;
         contador++;
        }
     else
        {
         cout << "el nombre no puede estar vacio"<< endl;
            cout << endl;
        }

    }
     else
        {
          cout << "codigo invalido. debe estar 1 y 10"<< endl;
          cout << endl;
        }
cout << endl;
    }

    cout << "marcas ingresadas correctamente: ";
    for (int x=0; x<TAM; x++)
        {
         cout << "marca " << x+1 << " codigo= " << codigos[x]<< ", nombre = "<< nombres[x]<< endl;
        }

return 0;
}

