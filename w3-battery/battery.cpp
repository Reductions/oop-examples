#include "battery.hpp"
#include <iostream>

battery::battery(int id, country origin, double buy_price)
  : _id(id), _origin(origin), _buy_price(buy_price)
{
  _sell_price = (int)(_buy_price*110) / 100.0;
}

void battery::print() const
{
  std::cout<<"id: "<<_id
           <<"\norigin: "<<get_origin_by_name()
           <<"\nprice: "<<_buy_price
           <<"\nprice: "<<_sell_price<<std::endl;
}

double battery::get_sell_price() const
{
  return _sell_price;
}

const char* battery::get_origin_by_name() const
{
  switch (_origin){
  case country::Japan : return "Japan";
  case country::Germany : return "Germany";
  case country::China : return "China";
  case country::Tiwan : return "Tiwan";
  }
}

void battery::set_sell_price(double new_price)
{
  if(new_price >= _buy_price*0.9){
    _sell_price = ((int)(new_price*100) + 1) / 100.0;
  }
}
