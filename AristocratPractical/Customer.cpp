//
//  Customer.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Customer.hpp"

int Customer::customerCount = 0;

Customer::Customer() {
    m_ID = customerCount;
    customerCount++;
}

Customer::~Customer() {}

// Responsible for making the payment
bool Customer::MakePayment(Order* order) {
    // Ultimately want this to check credit card details
    // Can the customer make the payment?
    // For now assume true
    
    // Set the status of the order to ORDERED
    order->SetStatus(Order::OrderStatus::ORDERED);
    
    m_orderList.push_back(order); // So the customer has a copy
    
    return true;
}

void Customer::CheckOrderStatus() {
    for (Order* order : m_orderList) {
        Order::OrderStatus orderStat = order->GetStatus();
        switch (orderStat) {
            case Order::OrderStatus::ORDERED:
            std::cout<<"ORDERED"<<std::endl;
            break;
            
            default:
            break;
        }
    }
}
