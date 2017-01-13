//
//  main.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Branch.hpp"
#include "Customer.hpp"
#include "Product.hpp"
#include "Kart.hpp"

#include <iostream>


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Branch branchA = Branch();
    
    Customer customerA = Customer();
//    Customer customerB = Customer();
    
    std::cout<<customerA.GetID()<<std::endl;
//    std::cout<<customerB.GetID()<<std::endl;
    
    Product productA = Product(10.f, "TV");
//
    Kart *kartA = new Kart();
    
    customerA.SetKart(kartA);
    
    kartA->AddProduct(&productA);
    
    Kart *customerKart = customerA.GetKart();
    customerKart->PrintProducts();
    
    branchA.Checkout(&customerA);
    
    customerA.CheckOrderStatus();
    
    return 0;
}
