#include "paginator.h"
#include "dynamic_matrix.cpp"


/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase paginator
 * @author Angelo Ceciliano Ortega.
 * @version 1.0.
 *
 * Descripcion: Se encargar de brindar la carta solicitada y
 *  evalua la seleccion de las cartas.
 */
class paginator
{
public:
    dynamicmatrix matrix;
    int count = 0;
    int pageHit = 0, pageFault = 0;
    string firstCard;
    card_struture c1 = card_struture("", 0);
    card_struture c2 = card_struture("", 0);
    card_struture c3 = card_struture("", 0);
    card_struture c4 = card_struture("", 0);
    card_struture array_page[4] = {c1,c2,c3,c4};
  //constructor
  paginator(){
        this->matrix.create_board();
        this->shuffle();
        this->pageFault = pageFault;
        this->pageHit = pageHit;
        count = 0;
    }


  /**
   * Este metodo mostrara la memoria.
   */
  void getUsedMemory(){
         int id = getpid();
         string string("pmap ");
         string.append(to_string(id));
         string.append(" | tail -n 1 | awk '/[0-9]K/{print $2}'");
         char const *pchar = string.c_str();
         cout << id << endl;
         cout << system(pchar) << endl;
     }
  /**
   * Este metodo da la carta solicitada.
   * @param card_num
   * @return retorna la carta solicitada
   */
    string get_card(int card_num){
        this->count++;
        string cardType = find_card(card_num).type;
        if (count%2 != 0){
            this->firstCard = cardType;
        }
        return cardType;
    }
    /**
     * Este metodo baraja las cartas.
     */
    void shuffle(){
        this->matrix.cards_in_mem.clear();
        for(int i=0; i <4; i++){
            this->array_page[i] = this->matrix.random_card();
        }

    }
    /**
     *Busca si la carta esta en el array de cartas de referencia
     * @param card_num
     * @return retorna la carta solicitada o realiza un swap
     */
    card_struture find_card(int card_num){
        this->getUsedMemory();
        for(int i = 0; i < 4;i++){
            if(card_num == array_page[i].num){
                this->array_page[i].card_play();
                return array_page[i];
               pageHit += 1;
            }
        }
            return this->swap(card_num);
    }
    /**
     * Cambia la carta por la solicitada
     * @param card_number
     * @return retorna la carta solicitada
     */
   card_struture swap(int card_number){
        int location_i = this->matrix.card_location(card_number, true);
        int location_j = this->matrix.card_location(card_number, false);
        string new_card= this->matrix.acces_matrix(location_i, location_j);

        pageFault += 1;
        if(this->c1.playing == false){
            this->c1 = card_struture(new_card, card_number);
            this->c1.card_play();
            return c1;
        }else{
            this->c2 = card_struture(new_card, card_number);
            this->c2.card_play();
            return c2;
        }
        if(this->c3.playing == false){
            this->c3 = card_struture(new_card, card_number);
            this->c3.card_play();
            return c3;
        }else{
            this->c4 = card_struture(new_card, card_number);
            this->c4.card_play();
            return c4;
        }
    }
   /**
    * Compara las cartas
    * @param card
    * @return retorna string "1" si son iguales,
    * "0" si no son iguales, "x" si no se puede comparar.
    */
    string compare(string card){
        if (this->count%2 == 0){
            if(this->firstCard == card){
                    return "1";
            }else{
                return "0";
            }
        }
        return "x";
    }
    void reset(){
        /**
         * Se reinician las cartas para que sean jugables nuevamente.
         */
        for(int i = 0; i<4; i++){
            this->array_page[i].card_out();
        }

    }
};





