#pragma once

#include "Position.h"
#include <vector>
//#include <algorithm>
//#include <numeric>

class Client;

class Order{
    friend Client;
public:
    void add_position(std::unique_ptr<Position>&& ptr_pos){
        auto i = std::find(m_ptr_positions.begin(), m_ptr_positions.end(), ptr_pos);
        if (i == m_ptr_positions.end()) {
            m_ptr_positions.push_back(std::move(ptr_pos));
        }
        else {
            m_ptr_positions.erase(i);
            m_ptr_positions.insert(i, std::move(ptr_pos));
        }
    }
    double get_cost() const noexcept{
        double cost = 0;
        for (auto& i: m_ptr_positions){
            cost += i->get_cost();
        }
        return cost;
    };
    void get_info() const{
        for (auto& i: m_ptr_positions){
            std::cout << i->get_ptr_product()->get_info() << std::endl;
            std::cout << "\tQuantity: " << i->get_quantity() << std::endl;
            std::cout << "\tCost: " << i->get_cost() << std::endl;
        }
        std::cout << "Total cost: " << get_cost() << std::endl;
    }
    bool empty() const noexcept {
        return m_ptr_positions.empty();
    }
private:
    void clear(){m_ptr_positions.clear();}
    std::vector<std::unique_ptr<Position>> m_ptr_positions;
};
