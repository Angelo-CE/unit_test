#include "dynamic_matrix.h"

#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include  <sstream>
#include <card_struture.cpp>
using namespace std;

/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase dynamicmatrix
 * @author Angelo Ceciliano Ortega.
 * @version 1.0.
 *
 * Descripcion: Crea la matrix con los id's al azar.
 */
class dynamicmatrix
{

public:
vector<int> cards_in_mem;
int matrix[5][6];
/**
 * Se crea el tablero y contiene la lista de la cartas,Aca se generan las cartas de contendra la matrix,
 */

   void create_board(){

        int A = 0,B = 0,C = 0,D = 0, E = 0, F = 0, G = 0;
        int i = 30;
        vector<string> board;
        vector<string> types = {"A", "B", "C", "D", "E","F","G"};
         srand(time(NULL));
        while (i > 0) {
            string randomType = types[rand() % types.size()];
            if(randomType == "A" and A < 4){
                board.push_back("A");
                A +=1;
                i -= 1;
            }
            if(randomType == "B" and B < 4){
                board.push_back("B");
                A +=1;
                i -= 1;
            }
            if(randomType == "C" and C < 4){
                board.push_back("C");
                A +=1;
                i -= 1;
            }
            if(randomType == "D" and D < 4){
                board.push_back("D");
                A +=1;
                i -= 1;
            }
            if(randomType == "E" and E < 4){
                board.push_back("E");
                A +=1;
                i -= 1;
            }
            if(randomType == "F" and F < 4){
                board.push_back("F");
                A +=1;
                i -= 1;
            }
            if(randomType == "G" and G < 2){
                board.push_back("G");
                A +=1;
                i -= 1;
            }
        }
        write_in_matrix();
        fill_matrix(board);
        }

   /**
    * Se generan los numeros en la matrix
    */
   void write_in_matrix(){
       int count = 1;
       for(int i=0; i<5; i++){
           for(int j=0; j<6; j++){
               this->matrix[i][j] = count;
               count++;
           }
       }
   }
   /**
    * Escribe el contenido de tabla en un .txt para facilitar su manejo
    * @param types
    */
   void fill_matrix(vector<string> types) {

       ofstream file;
       file.open("matrix.txt");
       for (int i = 0; i < 5; i++) {
           if(i == 0){

           }else{
               file << "\n";
           }
           for (int j = 0, r = 0; j < 6; j++, r++) {
               file << types[r] << " ";            
           }
       }
       file.close();
   }
   /**
    * Desde aca se accede a la matrix.txt para obtener cada carta por separado
    * @param i, j posicion de la matrix
    * @return return el tipo de carta.
    */
   string acces_matrix(int i, int j){
       //
       //
       string word, line;
       int select_line = i + 1;

       ifstream file("matrix.txt");
       int a = 1;
       while (getline(file, line))
       {
           if(a == select_line){
               istringstream ss(line);
               for (int b=0; b<j+1; b++){
                   ss >> word;
               }
               break;
           }
           a++;
       }
       return word;
   }
   /**
    * saca la locacion de
    * @param card_num, FoS se refiere a la posicion a buscar
    * @return posicion de i o j.
    */
   int card_location(int card_num, bool FoS) {
       for (int i = 0; i < 5; i++) {
           for (int j = 0; j < 6; j++) {
               if (this->matrix[i][j] == card_num) {
                   if (FoS) {
                       return i;
                   } else {
                       return j;
                   }
               }
           }
       }
       return 0;
   }
   /**
    * Allar la carta en memoria
    * @param element
    * @return resultado de la busqueda
    */
   bool container(const int & element)
   {
       //
       bool result = false;
       for (auto & x : this->cards_in_mem)
       {
           if (x == element)
           {
               result = true;
               break;
           }
       }
       return result;
   }

   /**
    * Genera una carta random
    * @return carta ramdon
    */

   card_struture random_card(){
       int i, j;
       srand(time(NULL));
       i = rand() %4;
       j = rand() %5;
       card_struture card = card_struture(this->acces_matrix(i,j), this->matrix[i][j]);
       return card;
   }

};















