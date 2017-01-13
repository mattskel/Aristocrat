//
//  Kart.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Kart.hpp"

Kart::Kart() {}
Kart::~Kart() {}

void Kart::AddProduct(Product *product) {
    m_productList.push_back(product);
}

void Kart::RemoveProduct(Product *product) {
    m_productList.erase(std::remove(m_productList.begin(), m_productList.end(), product), m_productList.end());
}

void Kart::PrintProducts() {
    for (Product* product : m_productList) {
        std::cout<<product->GetDescription()<<std::endl;
    }
}
