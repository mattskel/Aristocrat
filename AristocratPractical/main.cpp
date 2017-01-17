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

#include <iostream>

std::vector<Product*> productList;
int PopulateProductList();  // Forward declare

int main(int argc, const char * argv[]) {
    // insert code here...
    
    PopulateProductList();
    
    // Test SetProductCost for Branch class
    AustraliaBranch* ausBranch = new AustraliaBranch();
    NZBranch* nzBranch = new NZBranch();
    
    ausBranch->SetProductList(&productList);
    nzBranch->SetProductList(&productList);
    
//    ausBranch->PrintProductList();
    
    ausBranch->SetExchangRate(0.75f);
    
    // TEST ITEM CLASS
    Item* item = new Item(productList[0], 0.75);
    item->PrintDetails();
    
    std::vector<Item*> itemList;
    itemList.push_back(item);
    
    // TEST ORDER
    Order* order = new Order(itemList);
    if (order->GetStatus() == Order::OrderStatus::ORDERED) {
        std::cout<<"ORDERED"<<std::endl;
    }
    
    // TEST KART
    Kart* kart = new Kart();
    kart->AddItem(item);
    kart->PrintItems();
    
    // SET CUSTOMER KART
    // ADD ITEMS
    std::cout<<"SET CUSTOMER KART"<<std::endl;
    Customer* customer = new Customer();
    customer->SetKart(new Kart);
    std::cout<<"ADD ITEMS"<<std::endl;
    customer->GetKart()->AddItem(item);
    std::cout<<"PRINT ITEMS"<<std::endl;
    customer->GetKart()->PrintItems();
    
    // TEST SYSTEM
    std::cout<<"\n////////////////////////////\n// TEST_SYSTEM"<<std::endl;
    System* system = new System(0.75f, System::TheatreCategory::ENTRY);
    system->AddProductReference(productList[0]);
    system->AddProductReference(productList[2]);
    system->AddProductReference(productList[4]);
    system->AddProductReference(productList[17]);
    system->PrintDetails();
    
    // TEST POLYMORPHISM OF ITEM
    std::cout<<"\n////////////////////////////\n// TEST_POLYMORPHISM"<<std::endl;
    itemList.clear();
    itemList.push_back(system);
    itemList.push_back(new Item(productList[18], 0.75f));
    for (Item* item : itemList) {
        if (System* system = dynamic_cast<System*>(item)) {
            system->PrintDetails();
        }
        else {
            item->PrintDetails();
        }
    }
    
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
