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

#include <stdio.h>
#include <vector>
#include <iostream>

class Kart {
private:
    std::vector<Product*> m_productList;
public:
    Kart();
    ~Kart();
    void AddProduct(Product* product);
    void RemoveProduct(Product* product);
    std::vector<Product*> GetProductList() {return m_productList;}
    void PrintProducts();
};

#endif /* Kart_hpp */
