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


using std::cin, std::ifstream, std::ofstream, std::vector;

int main(int argc, char* argv[]) {

	int n, q, i = 0, j = 0, aux1, aux2, aux3;
	vector<int> vector, vectorv2, vectorv3;
	pair <int,int> searches;

	ifstream archivo(argv[1]); 
	ofstream archivo2(argv[2]);

	archivo >> n; 

	while (i < n) {
		archivo >> q;
		vector.push_back(q);
		i++;
	}

	vectorv2 = vector; 
	vectorv3 = vector;

	aux1 = bubbleSort(vector); 
	aux2 = selectionSort(vectorv2); 
	aux3 = insertionSort(vectorv3);

	archivo2 << aux1 << " " << aux2 << " " << aux3 << "\n" << "\n";

	archivo >> n;

	while (j < n){
		archivo >> q;
		searches = sequentialSearch(vector, q); 
		archivo2 << searches.first << " " << searches.second << " "; 

		searches = binarySearch(vector, q);
		archivo2 << searches.second << "\n";
		j++;
	}

	archivo.close();
	archivo2.close();


	return 0;
}
