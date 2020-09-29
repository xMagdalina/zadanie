#include <iostream>

#include <stdio.h>

#include <string.h>

#include <fstream>

#include <cstdlib>
using namespace std;
int cmp_rosnaco( const void * e1, const void * e2) {
  string * s1 = (string * ) e1;
  string * s2 = (string * ) e2;
  if( *s1 < *s2 ) 
    return -1;
  else if( *s1 == *s2 ) return 0;
   else if( *s1 > *s2 ) return 1;
}

int cmp_malejaco( const void * e1, const void * e2) {
  string * s1 = (string * ) e1;
  string * s2 = (string * ) e2;
  if( *s1 < *s2 ) 
    return 1;
  else if( *s1 == *s2 ) return 0;
   else if( *s1 > *s2 ) return -1;
}

int cmp_dlugosc( const void * e1, const void * e2) {
  string * s1 = (string * ) e1;
  string * s2 = (string * ) e2;
  if( s1->length() < s2->length() ) 
    return 1;
  else if( s1->length() == s2->length() ) return 0;
   else if( s1->length() > s2->length() ) return -1;
}

class Csort {
	string tmp;
  string wyrazy[100];
  ifstream plik;
  ofstream plik2;
  int ilosc, i;
  int ilosc_przeczytana;
  public:
    void otworz() {
    	cout<< "wyswietl";
      plik.open("plik.txt");
      i = 0; 
	  while(!plik.eof())
	  
    	{
    	getline(plik,tmp);
    	wyrazy [i] = tmp;
    	cout<< "wyswietl1: "<< wyrazy [i] << endl;
    	++i; 
    	ilosc_przeczytana = i;
    	if (i>99)
    		break; 
      	}
  }
      void wypisz() {
      	
      	cout<< "cos";
        qsort(wyrazy, ilosc_przeczytana, sizeof(string), cmp_malejaco);
        for (i = 0; i <ilosc_przeczytana; i++)
          cout << i << ": " << wyrazy[i] << endl;
          
          qsort(wyrazy, ilosc_przeczytana, sizeof(string), cmp_rosnaco);
        for (i = 0; i <ilosc_przeczytana; i++)
          cout << i << ": " << wyrazy[i] << endl;
          
          qsort(wyrazy, ilosc_przeczytana, sizeof(string), cmp_dlugosc);
        for (i = 0; i <ilosc_przeczytana; i++)
          cout << i << ": " << wyrazy[i] << endl;
      }
      void zamknij() {
        plik.close();
      }
    };
  int main(int argc, char ** argv) {
    Csort s;
    s.otworz();
    s.wypisz();
    s.zamknij();
    return 0;
  }
  

