//
// Created by Frank on 22/12/2021.
//

#include "CoinBuffer.h"

Coin::Coin(float value)
        :Value(value)
{
    //Nothing Here...
}

Magazine::Magazine(float type)
        :Type(type), MaxCoins(50)
{
    //Nothing Here...
}

Magazine::Magazine(float type, int maxCoins)
        :Type(type), MaxCoins(maxCoins)
{
    //Nothing Here...
}

void Magazine::pushBack(Coin coin) {
    Zasobnik.push_back(coin);
    Current++;
}












