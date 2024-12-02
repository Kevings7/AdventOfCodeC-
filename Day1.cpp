#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std; 





int main(){

    string linea;
    int numero;
    ifstream archivo;
    vector<int> vector1; 
    vector<int> vector2;
    archivo.open("input.txt");
    
    if (!archivo.is_open()){
        return 1;
    }
    
    while ( getline(archivo, linea)){
        stringstream ss(linea);
        ss >> numero; 
        vector1.push_back(numero);
        ss >> numero;
        vector2.push_back(numero);
    }

    sort( vector1.begin(), vector1.end());
    sort (vector2.begin(), vector2.end());

    int distancia, suma_distancias = 0;

    for ( int i = 0; i < vector1.size(); i++){
        distancia = vector1[i] - vector2[i];
        if ( distancia < 0 )
            distancia *= -1;
        suma_distancias += distancia;

    }

    cout << suma_distancias << endl;

    int coincidencias = 0, num_total_coincidencias = 0;


    for (int i = 0; i < vector2.size(); i++){
        for (int j = 0; j < vector2.size(); j++){
            if ( vector1[i] == vector2[j]){
                coincidencias++;

            }

        }

        num_total_coincidencias += (vector1[i] * coincidencias);
        coincidencias = 0;
    }

    cout << num_total_coincidencias << endl;

}