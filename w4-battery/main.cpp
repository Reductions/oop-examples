#include <iostream>

#include "battery.hpp"

int main (){
  battery b(123, battery::country::Japan, 123.12123123);
  std::cout<<"At the beginning\n";
  b.print();
  b = b + 2.13521;
  std::cout<<"after b = b + 2.13521\n";
  b.print();
  b = 2.123 + b;
  std::cout<<"after b = 2.123 + b\n";
  b.print();
  std::cout<<b;
  return 0;
}
