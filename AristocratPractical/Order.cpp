//
//  Order.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Order.hpp"

Order::Order() {}

Order::Order(std::vector<Product*> productList) {
    m_productList = productList;
    m_orderStatus = OrderStatus::ORDERED;
}

Order::Order(std::vector<Item*> itemList) {
    m_itemList = itemList;
    m_orderStatus = OrderStatus::ORDERED;
}

Order::~Order() {}

void Order::PrintStatus() {
    switch (m_orderStatus) {
        case OrderStatus::ORDERED:
        std::cout<<"ORDERED"<<std::endl;
        break;
        case OrderStatus::READY_FOR_DELIVERY:
        std::cout<<"READY_FOR_DELIVERY"<<std::endl;
        break;
        case OrderStatus::DELIVERED:
        std::cout<<"DELIVERED"<<std::endl;
        break;
        
        default:
        break;
    }
}