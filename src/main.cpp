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
#include <complex>
#include "paginator.cpp"
#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../lib/googletest/googlemock/include/gmock/gmock.h"
#include "../lib/googletest/googletest/include/gtest/gtest-assertion-result.h"
using namespace std;

int main(int argc, char **argv){
    paginator matrix;
    string card = matrix.get_card(1);
    cout<<card<<endl;
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();


};