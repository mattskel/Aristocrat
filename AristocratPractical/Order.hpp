//
//  Order.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include "Product.hpp"

#include <stdio.h>
#include <vector>

enum class OrderStatus;

class Order {
public:
    enum class OrderStatus {
        ORDERED,
        READY_FOR_DELIVERY,
        DELIVERED
    };
private:
    OrderStatus m_orderStatus;
    std::vector<Product*> m_productList;
    float m_discount;
public:
    Order();
    Order(std::vector<Product*> productList);
    ~Order();
    OrderStatus GetStatus() {return m_orderStatus;}
};

#endif /* Order_hpp */
