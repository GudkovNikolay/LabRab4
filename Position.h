#pragma once

#include "Product.h"

class Position{
public:
    Position(Product&& product) = delete;
    explicit Position(Product& product) noexcept: m_ptr_product(&product){}
    const Product* get_ptr_product() const noexcept { return m_ptr_product;}
    virtual double get_cost() const noexcept = 0;
    virtual double get_quantity() const noexcept = 0;
protected:
    const Product* m_ptr_product;
};

class AmountPosition: public Position{
public:
    AmountPosition(AmountProduct& product, size_t amount) noexcept:m_amount(amount), Position(product) {};
    double get_cost() const noexcept override {return m_ptr_product->get_cost() * m_amount;}
    double get_quantity() const noexcept override {return m_amount;};
private:
    size_t m_amount;
};

class WeightPosition: public Position{
public:
    WeightPosition(WeightProduct& product, double weight) noexcept:m_weight(weight), Position(product) {};
    double get_cost() const noexcept override {return m_ptr_product->get_cost() * m_weight;}
    double get_quantity() const noexcept override {return m_weight;};

private:
    double m_weight;
};

bool operator == (std::unique_ptr<Position>& obj1, std::unique_ptr<Position>& obj2)   {return obj1->get_ptr_product()->get_info() == obj2->get_ptr_product()->get_info();}