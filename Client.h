#pragma once

#include "Order.h"

class Balance{
public:
    void add_money(double money){
        if (money <= 0) throw std::runtime_error("only positive amount of money can be added");
        m_money += money;
    }
    bool spend_money(double money){
        if (money <= 0) throw std::runtime_error("only positive amount of money can be spent");
        if (money > m_money) return false;
        m_money -= money;
        return true;
    }
private:
    double m_money;
};

class Client{
public:
    void earn_money(double money){ m_balance.add_money(money);}
    bool pay_and_recieve_order(Order& order){
        if (m_balance.spend_money(order.get_cost())){
            order.clear();
            std::cout << "The order is recieved!" << std::endl;
            return true;
        }
        else{
            std::cout << "Not enough money to pay for order!" << std::endl;
            return false;
        }
    }
private:
    Balance m_balance;
};
