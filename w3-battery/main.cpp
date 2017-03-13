#include <iostream>

#include "battery.hpp"

int main (){
  battery b(123, battery::country::Japan, 123.12123123);
  b.print();
  b.set_sell_price(100.123);
  b.print();
  return 0;
}
