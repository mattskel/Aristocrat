//
//  Item.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include "Product.hpp"

#include <stdio.h>
#include <iostream>

class Item {
private:
    Product* m_productReference;
protected:
    float m_profitMargin;
    float m_exchangeRate;
    float m_salePrice;
public:
    Item();
    Item(float exchangeRate);
    Item(Product* productReference, float exchangeRate);
    virtual ~Item();
    void SetProductReference(Product* productReference);
    void SetExchangeRate(float exchangeRate) {m_exchangeRate = exchangeRate;}
    void SetProfitMargin(float profitMargin) {m_profitMargin = profitMargin;}
    void CalcSalePrice();
    float GetSalePrice() {return m_salePrice * m_exchangeRate;}
    void PrintDetails();
};

#endif /* Item_hpp */
