//
//  Item.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Item.hpp"
//#include <iostream>
#include <math.h>

Item::Item() {
    m_exchangeRate = 1.0f;
}

Item::Item(float exchangeRate) {
    m_exchangeRate = exchangeRate;
    m_profitMargin = 0.0f;
}

Item::Item(Product* productReference, float exchangeRate) {
    m_productReference = productReference;
    m_exchangeRate = exchangeRate;
    m_profitMargin = 0.0f;
    m_salePrice = m_productReference->GetCost() / m_exchangeRate;    // Initialise sale price to cost
}

Item::~Item() {}

void Item::SetProductReference(Product* productReference) {
    m_productReference = productReference;
}

void Item::CalcSalePrice() {
    m_salePrice = m_productReference->GetCost() / (1.0f-m_profitMargin);
}

void Item::PrintDetails() {
//    std::cout<<"HELLO"<<std::endl;
    std::cout<<m_productReference->GetDescription()<<std::endl;
    std::cout<<ceilf(m_salePrice * 100) / 100<<std::endl;
}
