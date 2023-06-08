// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "Automat.h"

using namespace ::testing;

//**************************************************************************

TEST(Initialization, BasicAutomat) {
    Automat mojAutomat(5, 5, 3, "4199", "Bio", 50);
    ASSERT_EQ(25, mojAutomat.getRows());
}
TEST(Initialization, BasicAutomatMinusovy) {
    Automat mojAutomat(-5, 5, 3, "4199", "Bio", 50);
    ASSERT_EQ(1, mojAutomat.getRows());
}
TEST(Initialization, BasicAutomatVelky) {
    Automat mojAutomat(8, 8, 8, "4199", "Bio", 50);
    ASSERT_EQ(1, mojAutomat.getRows());
}
TEST(Initialization, VypisVelkost) {
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    ASSERT_EQ("5:8:5", mojAutomat.getSize());
}
TEST(Initialization, VypisPocetPrvkov) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    ASSERT_EQ(10, mojAutomat.getAmountOfItems());
}
TEST(Initialization, VypisPocetPrvkovPoOdobrati) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.dropSelected(2);
    mojAutomat.dropSelected(2);
    mojAutomat.dropSelected(4);
    ASSERT_EQ(7, mojAutomat.getAmountOfItems());
}

TEST(Initialization, PredajBezVydaja) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(1);

    ASSERT_EQ(false, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajBezVydaja2) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(2);
    mojAutomat.depositCoin(1);

    ASSERT_EQ(false, mojAutomat.sellProduct(2));
    ASSERT_EQ(false, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajSVydajom) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.restockChange();
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(1);

    ASSERT_EQ(true, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajBezPenazi) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.restockChange();

    ASSERT_EQ(false, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajBezTovaru) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(1);
    ASSERT_EQ(false, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajBezTovaru2) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();

    ASSERT_EQ(false, mojAutomat.sellProduct(2));
}

TEST(Initialization, PredajSVydajomVela) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 100);
    for (int i = 0; i < 5; i++){
        mojAutomat.putItem(*item, 2);
        mojAutomat.putItem(*item, 4);
    }
    mojAutomat.restockChange();
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(2);


    ASSERT_EQ(true, mojAutomat.sellProduct(2));
}

TEST(Initialization, InicializaciaCelehoAutomatu) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();
    mojAutomat.restockProducts();

    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(1);
    mojAutomat.depositCoin(2);
    mojAutomat.depositCoin(2);


    ASSERT_EQ(200, mojAutomat.getAmountOfItems());
    ASSERT_EQ(true, mojAutomat.sellProduct(1));
    ASSERT_EQ(false, mojAutomat.sellProduct(2)); //Customer uz nema peniaze na tieto produkty
    ASSERT_EQ(false, mojAutomat.sellProduct(3));
}

TEST(Initialization, InicializaciaInternychPenazi) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();

    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(2));
    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(1));
    ASSERT_EQ(12, mojAutomat.getAmountOfCoins(0.50));
    ASSERT_EQ(20, mojAutomat.getAmountOfCoins(0.20));
    ASSERT_EQ(25, mojAutomat.getAmountOfCoins(0.10));
    ASSERT_EQ(0, mojAutomat.getCustomerMoney());
}

TEST(Initialization, PridavaniePenaziCustomerovi) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();

    mojAutomat.depositCoin(0.50);
    mojAutomat.depositCoin(0.20);
    mojAutomat.depositCoin(0.20);
    mojAutomat.depositCoin(2);
    mojAutomat.depositCoin(1);


    ASSERT_EQ(11, mojAutomat.getAmountOfCoins(2));
    ASSERT_EQ(11, mojAutomat.getAmountOfCoins(1));
    ASSERT_EQ(13, mojAutomat.getAmountOfCoins(0.50));
    ASSERT_EQ(22, mojAutomat.getAmountOfCoins(0.20));
    ASSERT_EQ(25, mojAutomat.getAmountOfCoins(0.10));
    ASSERT_TRUE(mojAutomat.cmpf(3.90, mojAutomat.getCustomerMoney()));
}

TEST(Initialization, PridavanieMinciCustomerovi) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();
    Coin *coin1 = new Coin(2);
    Coin *coin2 = new Coin(1);
    Coin *coin3 = new Coin(0.50);
    Coin *coin4 = new Coin(0.20);

    mojAutomat.depositCoin(*coin3);
    mojAutomat.depositCoin(*coin4);
    mojAutomat.depositCoin(*coin4);
    mojAutomat.depositCoin(*coin1);
    mojAutomat.depositCoin(*coin2);


    ASSERT_EQ(11, mojAutomat.getAmountOfCoins(2));
    ASSERT_EQ(11, mojAutomat.getAmountOfCoins(1));
    ASSERT_EQ(13, mojAutomat.getAmountOfCoins(0.50));
    ASSERT_EQ(22, mojAutomat.getAmountOfCoins(0.20));
    ASSERT_EQ(25, mojAutomat.getAmountOfCoins(0.10));
    ASSERT_TRUE(mojAutomat.cmpf(3.90, mojAutomat.getCustomerMoney()));
}

TEST(Initialization, PridavanieKredituCustomerovi) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();
    mojAutomat.addBalance(0.50);
    mojAutomat.addBalance(1);
    mojAutomat.addBalance(2);
    mojAutomat.addBalance(0.20);
    mojAutomat.addBalance(0.20);

    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(2));
    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(1));
    ASSERT_EQ(12, mojAutomat.getAmountOfCoins(0.50));
    ASSERT_EQ(20, mojAutomat.getAmountOfCoins(0.20));
    ASSERT_EQ(25, mojAutomat.getAmountOfCoins(0.10));
    ASSERT_TRUE(mojAutomat.cmpf(3.90, mojAutomat.getCustomerMoney()));
}

TEST(Initialization, PridaniePrivelaMinci) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockChange();
    for (int i = 0; i < 24; i++){
        mojAutomat.depositCoin(0.10);
    }
    ASSERT_TRUE(mojAutomat.depositCoin(0.10));
    ASSERT_FALSE(mojAutomat.depositCoin(0.10));
    ASSERT_FALSE(mojAutomat.depositCoin(0.10));

    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(2));
    ASSERT_EQ(10, mojAutomat.getAmountOfCoins(1));
    ASSERT_EQ(12, mojAutomat.getAmountOfCoins(0.50));
    ASSERT_EQ(20, mojAutomat.getAmountOfCoins(0.20));
    ASSERT_EQ(50, mojAutomat.getAmountOfCoins(0.10));
    ASSERT_TRUE(mojAutomat.cmpf(2.50, mojAutomat.getCustomerMoney()));
}

TEST(Initialization, VkladDoPlneho) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockProducts();
    ASSERT_FALSE(mojAutomat.putItem(*item, 1));
    ASSERT_FALSE(mojAutomat.putItem(*item, 2));
    ASSERT_FALSE(mojAutomat.putItem(*item, 3));
    ASSERT_FALSE(mojAutomat.putItem(*item, 4));
    ASSERT_FALSE(mojAutomat.putItem(*item, 5));

    ASSERT_EQ(200, mojAutomat.getAmountOfItems());
}

TEST(Initialization, VkladDoPrazdneho) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    ASSERT_TRUE(mojAutomat.putItem(*item, 1));
    ASSERT_TRUE(mojAutomat.putItem(*item, 2));
    ASSERT_TRUE(mojAutomat.putItem(*item, 3));
    ASSERT_TRUE(mojAutomat.putItem(*item, 4));
    ASSERT_TRUE(mojAutomat.putItem(*item, 5));

    ASSERT_EQ(5, mojAutomat.getAmountOfItems());
}

TEST(Initialization, VyberZPrazdneho) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);

    ASSERT_FALSE(mojAutomat.dropSelected(1));
    ASSERT_FALSE(mojAutomat.dropSelected(2));
    ASSERT_FALSE(mojAutomat.dropSelected(3));

    ASSERT_EQ(0, mojAutomat.getAmountOfItems());
}

TEST(Initialization, VyberZPlneho) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);
    mojAutomat.restockProducts();
    ASSERT_TRUE(mojAutomat.dropSelected(1));
    ASSERT_TRUE(mojAutomat.dropSelected(2));
    ASSERT_TRUE(mojAutomat.dropSelected(3));

    ASSERT_EQ(197, mojAutomat.getAmountOfItems());
}

TEST(Initialization, AddMinusovyKredit) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);

    ASSERT_FALSE(mojAutomat.addBalance(-0.50));
    ASSERT_FALSE(mojAutomat.addBalance(-1));
    ASSERT_FALSE(mojAutomat.addBalance(-0.20));

    ASSERT_EQ(0, mojAutomat.getCustomerMoney());
}

TEST(Initialization, AddPlusovyKredit) {
    Item *item = new Item('P', "koka-kola",'p',2);
    Automat mojAutomat(5, 8, 5, "4199", "Bio", 50);

    ASSERT_TRUE(mojAutomat.addBalance(0.50));
    ASSERT_TRUE(mojAutomat.addBalance(1));
    ASSERT_TRUE(mojAutomat.addBalance(0.20));

    ASSERT_TRUE(mojAutomat.cmpf(1.70, mojAutomat.getCustomerMoney()));
}