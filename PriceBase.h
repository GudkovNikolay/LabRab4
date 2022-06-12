#pragma once

#include <map>
#include <string>
#include "Product.h"

class PriceBase {
public:
    PriceBase(const PriceBase&) = delete; // конструктор копирования удалён
    PriceBase& operator = (const PriceBase&) = delete; // оператор = удалён
    static PriceBase& Instance() { // Использует отложенную инициализацию
        static PriceBase instance; // тут сработает дефолтный конструктор
        return instance;
    }
    WeightProduct& get_product_weight_price(const std::string& Name) {
        return m_products_weight_price.at(Name);
    }
    AmountProduct& get_product_amount_price(const std::string& Name)  {
        return m_products_amount_price.at(Name);
    }
protected:
    PriceBase() = default; // дефолтный конструктор скрыт
private:
    std::map<std::string, ProductInfo> m_products_info = {
            { "Apple", ProductInfo("Green sweet apple") },
            { "Nuts", ProductInfo("Macadamia nut") },
            { "Pencil", ProductInfo("Red pencil with rubber") },
            { "Chair", ProductInfo("Wooden chair with armrests") },
    };
    std::map<std::string, WeightProduct> m_products_weight_price = {
            {"Apple", WeightProduct(m_products_info.at("Apple"), 11.3)},
            {"Nuts", WeightProduct(m_products_info.at("Nuts"), 34.2)}
    };
    std::map<std::string, AmountProduct> m_products_amount_price = {
            { "Pencil", AmountProduct(m_products_info.at("Pencil"), 5.7) },
            { "Chair", AmountProduct(m_products_info.at("Chair"), 75) },
    };
};
