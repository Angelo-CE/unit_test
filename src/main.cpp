//
// Created by angelo on 03/05/22.
//

#include "main.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "paginator.cpp"

using namespace std;

int main(){
    paginator matrix;
    string card = matrix.get_card(1);
    cout<<card<<endl;


    return 0;


};