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
Order::~Order() {}