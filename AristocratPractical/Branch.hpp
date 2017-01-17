//
//  Branch.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Branch_hpp
#define Branch_hpp

#include "Kart.hpp"
#include "Customer.hpp"
#include "Order.hpp"

#include <stdio.h>
#include <vector>

class Branch {
private:
//    std::vector<Kart*> m_kartList;  // Not sure we are going to need this
    std::vector<Order*> m_orderList;
    std::vector<Product*>* m_productList;
    float m_exchangeRate;
public:
    Branch();
    ~Branch();
    void Checkout(Customer *customer);
    void SetProductList(std::vector<Product*>* productList) {m_productList = productList;}
    void PrintProductList();
//    void SetProductCost(int productIndex, float cost);
    void SetExchangRate(float exchangeRate) {m_exchangeRate = exchangeRate;}
};

#endif /* Branch_hpp */
