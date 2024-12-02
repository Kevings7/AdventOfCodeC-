#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

bool intervalo_valido( int elemento, int elementosig, bool creciente){
    int intervalo;
    
    if (creciente){
        if ( elementosig < elemento){
            return false;
        }
        intervalo = elementosig - elemento;
    } else{ 
        if ( elementosig > elemento)
            return false;
        intervalo = elemento - elementosig;
    }

    if ( intervalo  < 1 || intervalo > 3 )
        return false;
    else 
        return true;

}

int main(){
    int elemento, elementosig, contador_safe = 0;
    bool creciente;
    ifstream archivo("input.txt");
    vector<int> crecimiento; 

    if (!archivo.is_open()){
        return 1;
    }

    string linea;

    while (getline(archivo, linea)){
        queue<int> cola;
        stringstream ss(linea);
        int numero;

        while (ss >> numero ){ 
            cola.push(numero);
        }


        bool valido = true;

        elemento = cola.front();
        cola.pop();
        elementosig = cola.front();
        if ( elemento < elementosig)
                creciente = true;
            else 
                creciente = false;
      

        while ( !cola.empty() && valido) { 
            valido = intervalo_valido(elemento, elementosig, creciente);
            elemento = elementosig;
            cola.pop();
            elementosig = cola.front();   
        }
        
        if (valido)
            contador_safe++;

      


    }

    archivo.close();
    cout << contador_safe;
    return 0;

}