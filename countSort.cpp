#include <iostream>
#include <stdlib.h>

using namespace std;

void countSort(int *elementos,int total);

int main(int argc, char const *argv[]) {
  int total;
  cout << "qual o total de elementos que deseja ordenar?" << '\n';
  cin >> total;
  int *elementos = new int[total];
  if(elementos=0){
  	cout << "memoria nao pode ser alocada.";
  }
  else{
  	cout << "insira os elementos.\n";
	for (size_t i = 0; i < total; i++) {
		cin >> elementos[i];
	}
	countSort(elementos,total);
	while(total--){
	  cout << elementos[total] << ' ';
	}
	  delete elementos;
  }

  return 0;
}

void countSort(int *elementos,int total){
  int maior=0;
  for (size_t i = 0; i < total; i++) {
    if (maior < elementos[i]) {
      maior = elementos[i];
    }
  }
  int *aux = (int*) calloc(maior+1,sizeof(int));
  for (size_t i = 0; i < total; i++) {
    aux[elementos[i]]++;
  }
  int contador = 0;
  for (size_t i = 0; i < maior+1; i++) {
    while (aux[i]) {
      elementos[contador] = i;
      aux[i]--;
      contador++;
    }
  }
  free(aux);
}
