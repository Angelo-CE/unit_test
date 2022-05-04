#include "card_struture.h"
#include <string>
using namespace std;

/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase card_struture
 * @author Angelo Ceciliano Ortega.
 * @version 1.0.
 *
 * Descripcion: Se encargar de conterner los datos de carta y de construirlo.
 */
class card_struture{
public:
    string type;
    int num;
    bool playing;
    card_struture(string i, int j){
        this->type = i;
        this->num = j;
        this->playing = false;
    }
    void card_play(){
        this->playing = true;
    }
    void card_out(){
        this->playing = false;
    }
};
