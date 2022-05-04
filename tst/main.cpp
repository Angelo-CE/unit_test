//
// Created by angelo on 03/05/22.
//

#include "main.h"
TEST(PaginatorTest, PaginatorRequest){
class MockPaginator : public paginator{
public:
    MOCK_METHOD1(get_card, string(int card_num))
};
//No se pudo importar la libreria :(
MockClient mockObject;
EXPECT_CALL(mockObject, connect("Names"))
.Times(1);
}

int main(){


}