//
// Created by Frank on 15/12/2021.
//

#include <iostream>
#include "Automat.h"


int main()
{
    Automat mojAutomat(5, 5, 3, "4199", "Bio", 50);
    mojAutomat.restockChange();
    mojAutomat.restockProducts();

    std::cout << mojAutomat.getSize() << " " << mojAutomat.getRows() << std::endl;
//    std::cout << mojAutomat.getMags().begin()->getCurr() * mojAutomat.getMags().begin()->getType();
    return 0;
}