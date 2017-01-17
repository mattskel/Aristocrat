//
//  System.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 17/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "System.hpp"

#include <math.h>

System::System() : Item() {}
System::System(float exchangeRate, TheatreCategory category) : Item(exchangeRate) {
    m_theatreCategory = category;
}
System::~System() {}

void System::AddProductReference(Product* productReference) {
    m_productReferenceList.push_back(productReference);
}

void System::CalcSalePrice() {
    m_salePrice = 0.0f;
    for (Product* reference : m_productReferenceList) {
        m_salePrice += reference->GetCost() / (1.0f-m_profitMargin);
    }
}

void System::PrintDetails() {
    PrintCategory();
    for (Product* reference : m_productReferenceList) {
        std::cout<<reference->GetDescription() + "\t$";
        std::cout<<ceilf(reference->GetCost() / m_exchangeRate * 100) / 100<<std::endl;
    }
}

void System::PrintCategory() {
    switch (m_theatreCategory) {
        case TheatreCategory::ENTRY:
        std::cout<<"ENTRY"<<std::endl;
        break;
        case TheatreCategory::INTERMEDIATE:
        std::cout<<"INTERMEDIATE"<<std::endl;
        break;
        case TheatreCategory::CINEMATIC:
        std::cout<<"CINEMATIC"<<std::endl;
        break;
        
        default:
        break;
    }
}