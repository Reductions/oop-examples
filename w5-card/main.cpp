#include <iostream>
#include <cstring>
#include "card.hpp"


int main(){
  card c("Slon", "Golem slon");
  auto x = c;
  std::cout<<( x != c )<<"\n";
  c.print();
  x.print();
}
