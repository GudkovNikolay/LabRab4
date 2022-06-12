
#include "Product.h"
#include "Position.h"
#include "Order.h"
#include "Client.h"
#include "PriceBase.h"

int main() {
    /*PriceBase& price_base = PriceBase::Instance();

    Order order;
    std::cout << std::boolalpha << order.empty() << std::endl;

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(price_base.get_product_weight_price("Apple"), 0.5)));
    order.add_position(std::make_unique<AmountPosition>(AmountPosition(price_base.get_product_amount_price("Pencil"), 2)));

    order.get_info();

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(price_base.get_product_weight_price("Apple"), 1.5)));

    order.get_info();

    Client Ivan;*/

    PriceBase& priceBase = PriceBase::Instance();

    Order order;
    std::cout << std::boolalpha << order.empty() << std::endl;

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(
            priceBase.get_product_weight_price("Apple"), 0.5)));
    order.add_position(std::make_unique<AmountPosition>(AmountPosition(
            priceBase.get_product_amount_price("Pencil"), 2)));

    order.get_info();

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(
            priceBase.get_product_weight_price("Apple"), 1.5)));

    order.get_info();

    Client Ivan;
    Ivan.pay_and_recieve_order(order);

    Ivan.earn_money(500);
    Ivan.pay_and_recieve_order(order);
    return 0;
}
