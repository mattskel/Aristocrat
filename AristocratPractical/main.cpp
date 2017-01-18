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
#include "AustraliaBranch.hpp"
#include "NZBranch.hpp"
#include "System.hpp"
#include "KartItem.hpp"

#include <iostream>

std::vector<Product*> productList;
int PopulateProductList();  // Forward declare

int main(int argc, const char * argv[]) {
    // insert code here...
    
    PopulateProductList();
    
    // TEST COMPONENT
    std::cout<<"\n////////////////////////////\n// TEST_COMPONENT"<<std::endl;
    
    Component* cableComponent = new Component(0.75f, 0.0f);
    cableComponent->SetProductReference(productList[18]);
    cableComponent->CalcSalePrice();
    cableComponent->PrintDetails();
    
    // TEST AUS BRANCH
    std::cout<<"\n////////////////////////////\n// TEST_AUS_BRANCH"<<std::endl;
    
    // Create new Aus Branch
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    ausBranch->PrintItemList();
    
    // TEST KART ITEM
    std::cout<<"\n////////////////////////////\n// TEST_KART_ITEM"<<std::endl;
    Item* item = ausBranch->GetItemList()[0];
    KartItem* kartItem = new KartItem(item, 5);
    kartItem->PrintKartItem();
    
    // TEST KART
    std::cout<<"\n////////////////////////////\n// TEST_KART"<<std::endl;
    Kart* kart = new Kart();
    kart->AddKartItem(item, 5);
    kart->AddKartItem(ausBranch->GetItemList()[3], 2);
    kart->PrintKartItems();
    
    // TEST CHECKOUT KART
    std::cout<<"\n////////////////////////////\n// TEST_CHECKOUT_KART"<<std::endl;
//    Kart* kart = new Kart();
//    kart->AddItem(new Item(1, productList[18], 0.75f));
//    kart->PrintItems();
//    kart->AddItem(system);
//    kart->PrintItems();
//    customer->GetKart()->PrintItems();
    
//    customer = new Customer();
//    customer->SetKart(kart);
//    ausBranch->Checkout(customer);
    
//    order = new Order(kart->GetItemList());
//    order->CalcOrderTotal();
//    order->PrintOrder();
    
    std::cout<<"\n////////////////////////////\n// END"<<std::endl;
    std::cout<<"\n";
    
    return 0;
}

int PopulateProductList () {
    
//    std::vector<Product*> productList;
    productList.push_back(new Product(400.0f, "32\" Samsung Plasma TV"));
    productList.push_back(new Product(400.0f, "32\" Sony Plasma TV"));
    productList.push_back(new Product(150.0f, "400Watts LG Amplifier/AV Receiver"));
    productList.push_back(new Product(50.0f, "2-channel Panasonic speakers"));
    productList.push_back(new Product(50.0f, "2-channel Samsung speakers"));
    productList.push_back(new Product(900.0f, "Song LCD TV"));
    productList.push_back(new Product(900.0f, "Sony LCD TV"));
    productList.push_back(new Product(300.0f, "500Watts Yamaha Amplifier/AV Receiver"));
    productList.push_back(new Product(300.0f, "500Watts Kenwood Amplifier/AV Receiver"));
    productList.push_back(new Product(120.0f, "5-channel Sony speakers"));
    productList.push_back(new Product(110.0f, "5-channel Samsung speakers"));
    productList.push_back(new Product(1800.0f, "60\" LED TV"));
    productList.push_back(new Product(1600.0f, "55\" LED TV"));
    productList.push_back(new Product(950.0f, "650Watts Onkyo Amplifier/AV Receiver"));
    productList.push_back(new Product(950.0f, "650Watts Onkyo Amplifier/AV Receiver"));
    productList.push_back(new Product(1500.0f, "7-channel Bose speaker system"));
    productList.push_back(new Product(1500.0f, "7-channel Bose speaker system"));
    productList.push_back(new Product(80.0f, "Sony Blu-ray Player"));
    productList.push_back(new Product(5.0f, "HDMI Cables"));
    productList.push_back(new Product(200.0f, "Universal remote"));
    productList.push_back(new Product(120.0f, "Wireless headphones"));

    return 0;
}
