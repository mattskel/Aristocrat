//
//  Branch.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Branch.hpp"

Branch::Branch() {}
Branch::~Branch() {}
void Branch::Checkout(Customer *customer) {
    
    // Get the customers Kart
    Kart* kart = customer->GetKart();
    
    // Remove the items and create an order
//    std::vector<Product*> productList = kart->GetProductList();
    
    // The branch should be responsible for handling the orders
    // Create the order
//    Order* order = new Order(productList);
    
    
    // Payment
    // Calc the cost of the order
    // Charge to the customer credit card
    
    // The last thing we do is place the order on the list
//    if (customer->MakePayment(order)) {
//        m_orderList.push_back(order);
//    }
    
}

void Branch::PrintProductList() {
    for (Product *product : *m_productList) {
        std::cout<<product->GetDescription()<<std::endl;
        std::cout<<product->GetCost()<<std::endl;
    }
}

//void Branch::SetProductCost(int productIndex, float cost) {
//    m_productList[productIndex]->SetCost(cost);
//}