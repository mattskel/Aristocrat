//
//  Kart.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Kart_hpp
#define Kart_hpp

#include "Product.hpp"
#include "Item.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>

class Kart {
private:
//    std::vector<Product*> m_productList;
    std::vector<Item*> m_itemList;
public:
    Kart();
    ~Kart();
    
//    void AddProduct(Product* product);
//    void RemoveProduct(Product* product);
//    std::vector<Product*> GetProductList() {return m_productList;}
//    void PrintProducts();
    
    void AddItem(Item* item);
    void RemoveItem(Item* item);
    std::vector<Item*> GetItemList() {return m_itemList;}
    void PrintItems();
};

#endif /* Kart_hpp */
