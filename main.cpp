// =================================================================
//
// File: main.cpp
// Author: David René Langarica Hernández - A01708936
// Date: 2 de septiembre de 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"


using std::cin, std::endl, std::ifstream, std::ofstream, std::vector;

int main(int argc, char* argv[]) {

	int n,q,d,s,aux1,aux2,aux3;
	vector<int> vector, vectorv2, vectorv3;
	pair <int,int> searches;

	ifstream archivo(argv[1]); // Porque es en terminal
	ofstream archivo2(argv[2]);

	archivo >> n; //Datos primera linea

	for (int i = 0; i < n; i++){ //Datos segunda linea
		archivo >> q;
		vector.push_back(q); //Guardar datos Buscar alternativa
	}

	vectorv2 = vector; 
	vectorv3 = vector;

	aux1 = bubbleSort(vector); 
	aux2 = selectionSort(vectorv2); 
	aux3 = insertionSort(vectorv3);

	archivo2 << aux1 << " " << aux2 << " " << aux3 << endl << endl;

	archivo >> d;

	for (int i = 0; i < d; i++){
		archivo >> s;
		searches = sequentialSearch(vector,s); 
		archivo2 << searches.first << " " << searches.second << " "; 

		searches = binarySearch(vector, s);
		archivo2 << searches.second << endl;
	}

	archivo.close();
	archivo2.close();


	return 0;
}
