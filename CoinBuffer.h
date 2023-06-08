//
// Created by Frank on 22/12/2021.
//

#ifndef SEMPROJ2_COINBUFFER_H
#define SEMPROJ2_COINBUFFER_H

#endif //SEMPROJ2_COINBUFFER_H
#include <iostream>
#include <vector>

class Coin{
public:
    Coin(float value);

    float getValue(){ return Value; }
    void setValue(float value) { Value = value; }

private:
    float Value;
};

class Magazine{
public:
    Magazine(float type);
    Magazine(float type, int maxCoins);

    float getType() const { return Type;}
    int getMax() const { return MaxCoins; }
    int getCurr() const { return Current; }
    void setCurr() { Current++;}
    std::vector<Coin> getCoins() { return Zasobnik;}
    void pushBack(Coin coin);

private:
    std::vector<Coin> Zasobnik;
    float Type;
    int MaxCoins;
    int Current = 0;
};

