/*#pragma once

#include <iostream>
#include <sstream>

class ProductInfo{
public:
    explicit ProductInfo(std::string info)noexcept : m_info(std::move(info)){};
     std::string get_info() const noexcept {return m_info;}
private:
    std::string m_info;
};

class Product{
public:
    explicit Product(ProductInfo& product_info) noexcept :m_product_info(product_info)  {};
    virtual std::string get_info() const = 0;
    virtual double get_cost() const noexcept = 0;
protected:
    ProductInfo& m_product_info;
};

class WeightProduct: public Product{
public:
    WeightProduct(ProductInfo product_info, double cost) noexcept
    :m_cost_per_kg(cost), Product(product_info){};
    double get_cost() const noexcept override {return m_cost_per_kg;};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info() << " : ";
        ss << m_cost_per_kg << " per kg";
        return ss.str();
    }
private:
    double m_cost_per_kg;
};

class AmountProduct: public Product{
public:
    AmountProduct(ProductInfo product_info, double cost) noexcept
    :m_cost_per_one(cost), Product(product_info){};
    double get_cost() const noexcept override {return m_cost_per_one;};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info() << " : ";
        ss << m_cost_per_one << " per kg";
        return ss.str();
    }
private:
    double m_cost_per_one;
};*/

#pragma once
#include <sstream>
#include <utility>
#include <vector>
#include <map>

class ProductInfo{
public:
    explicit ProductInfo(std::string info) noexcept: m_info(std::move(info)){};
    std::string get_info() const noexcept {return m_info;}
private:
    std::string m_info;
};

class Product{
public:
    explicit Product(ProductInfo& productInfo) noexcept: m_product_info(productInfo){};
    virtual std::string get_info() const = 0;
    virtual double get_cost() const noexcept = 0;
protected:
    ProductInfo& m_product_info;
};

class WeightProduct: public Product{
public:
    WeightProduct(ProductInfo& productInfo, double cost): m_cost_per_kg(cost),
                                                          Product(productInfo){};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info();
        ss << ": ";
        ss << m_cost_per_kg;
        ss << " per kg";
        return ss.str();
    }
    double get_cost() const noexcept override{
        return m_cost_per_kg;
    }
private:
    double m_cost_per_kg;
};

class AmountProduct: public Product{
public:
    AmountProduct(ProductInfo& productInfo, double cost): m_cost_per_one(cost),
                                                          Product(productInfo){};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info();
        ss << ": ";
        ss << m_cost_per_one;
        ss << " per one";
        return ss.str();
    }
    double get_cost() const noexcept override{
        return m_cost_per_one;
    }
private:
    double m_cost_per_one;
};