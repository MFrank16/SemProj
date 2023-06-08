README
DOKUMENTACIA PROJEKTU AUTOMAT NA MINCE NA NAPOJE

Hlavna class automat:
Obsahuje incializacne metody
initializeRows a initializeMags, ktore su pouzite v konstruktore na vytvorenie radov a zasobnikov v automate
pomocou linked listu a coin bufferu.

Metody putItem, getItem, getFirst vkladaju/vracaju z linked listu item.
Metoda getAmountOfItems vracia hodnotu kolko sa v automate nachadza itemov.
getMags vracia referenciu na zasobniky kde sa ukladaju peniaze.
getRows vracia pocet radov v automate.
getSize vracia stringovu podobu velkosti automatu.

cmpf, metoda na porovnavanie hodnoty s presnostou.
depositCoin ma viacero tvarov, bud vklada podla hodnoty alebo podla mince. Vklada mincu do zasobnika na mince, a zvysuje customerove peniaze.
addBalance iba zvysuje customerove peniaze.
restockChange - naplni prvotne automat drobnymi na vydaj, vytvori mince v zasobnikoch.
restockProducts - naplni prvotne automat tovarom na predaj.

sellProduct - pokusi sa predat produkt v danom row. hlada a ak existuje a customer ma dost penazi na dany produkt tak ho preda.
dropSelected - vytiahne produkt z linkedlistu.
Givechange - na zaklade vlozenych penazi a zostatkoveho kreditu sa pokusi vratit drobne.
getAmountOfCoins - vrati momentalny pocet minci v danom zasobniku.
getCustomerMoney - vrati hodnotu aku ma zakaznik na ucte.

Classa LinkedList:
Konstruktor vytvori hlavu linked listu
Pushback vytvori novy Node a vlozi do neho item, ten potom pripoji na sucasny linked list dopredu, teda sa zachovava postupnost (to je feature, nie bug, postupnost je vzdy zachovana aj v real automate, nepridavame do stredu.)
getDepth vracia hlbku linkedlistu.
getHead vracia referenciu na hlavu linked listu

Coinbuffer:
vytvara vektor zasobnik, ktory bude obsahovat objekty coin, aby potom vedel realisticky vydavat realne mince.
Coin ma dve metody, setValue a getValue.

Magazine:
getType vracia typ minci na ktory je tento zasobnik definovany (vieme si predstavit ako odkladaci priestor pre mince isteho druhu, teda vieme kedy musime manualne doplnit iste mince na vydaj a nie je to pomiesane)
getMax vracia maximalny pocet minci v tomto zasobniku
getCurr vracia momentalny pocet minci v tomto zasobniku
getCoins vracia referenciu na tento zasobnik
pushback tlaci do zasobniku dalsiu mincu a inkrementuje pocet