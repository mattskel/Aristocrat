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
    std::vector<Item*> itemList = kart->GetItemList();
    
    // The branch should be responsible for handling the orders
    // Create the order
    Order* order = new Order(itemList);
    order->CalcOrderTotal();
    
    
    // Payment
    // ChargeCustomer()
    
    // The last thing we do is place the order on the list
//    if (customer->MakePayment(order)) {
//        m_orderList.push_back(order);
//    }
    
}

Order* Branch::Checkout(Kart* kart) {
    
    // Remove the items from the Kart
//    std::vector<Item*> itemList = kart->GetItemList();
    std::vector<KartItem*> kartItemList = kart->GetKartItemList();
    
    // Create an order from the itemList
    Order* order = new Order(kart->GetKartItemList());
    order->CalcSubTotal();
    order->CalcDiscount();
    order->CalcOrderTotal();
    
    // Set the Branch instance
    order->SetBranch(this);
    
    // Place order on list
    m_orderList.push_back(order);
    
    // Return the order
    return order;
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

void Branch::PrepareOrders() {
    for (Order* order : m_orderList) {
        if (order->GetStatus() == Order::OrderStatus::ORDERED) {
            order->SetStatus(Order::OrderStatus::READY_FOR_DELIVERY);
        }
    }
}

void Branch::DeliverOrders() {
    for (Order* order : m_orderList) {
        if (order->GetStatus() == Order::OrderStatus::READY_FOR_DELIVERY) {
            order->SetStatus(Order::OrderStatus::DELIVERED);
        }
    }
}