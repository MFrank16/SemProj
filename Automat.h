//
// Created by Frank on 15/12/2021.
//

#ifndef SEMPROJ2_AUTOMAT_H
#define SEMPROJ2_AUTOMAT_H

#endif //SEMPROJ2_AUTOMAT_H
#include "LinkedList.h"
#include "CoinBuffer.h"
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <math.h>




class Exception {

public:
    Exception(const std::string& msg) : msg_(msg) {}
    ~Exception() {}

    std::string getMessage() const {return(msg_);}
private:
    std::string msg_;
};


class Automat{
private:
    static const int MAX_SIZE = 240;
    float customerMoney = 0;
    std::vector<LinkedList> My_Rows;
    std::vector<Magazine> Zasobniky;

    int Width;
    int Height;
    int Depth;
    std::string Code = "0000";
    std::string Classification = "default";
public:
    Automat(int width, int height, int depth, std::string code, std::string classification, int maxCoins);
    ~Automat();
    bool initializeRows();
    bool initializeMags(int maxCoins);

    bool putItem(Item item, int row);
    Item getItem(int row, int depth);
    Item getFirst(int row);
    int getAmountOfItems();
    std::vector<Magazine> getMags() { return Zasobniky; }
    int getRows();
    std::string getSize();


    bool cmpf(float A, float B, float epsilon = 0.005f);
    bool depositCoin(Coin coin);
    bool depositCoin(float value);
    bool addBalance(float value);
    void restockChange();
    void restockProducts();

    bool sellProduct(int row);
    bool dropSelected(int row);
    std::vector<Coin> GiveChange();
    int getAmountOfCoins(float type);
    void clearCustomerMoney() {customerMoney = 0;}
    float getCustomerMoney() { return customerMoney; }
};