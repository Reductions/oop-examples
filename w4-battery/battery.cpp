#include "battery.hpp"
#include <iostream>

battery::battery(int id, country origin, double buy_price)
  : _id(id), _origin(origin), _buy_price(buy_price)
{
  _sell_price = (int)(_buy_price*110) / 100.0;
}

void battery::print() const
{
  std::cout<<"---\nid: "<<_id
           <<"\norigin: "<<get_origin_by_name()
           <<"\nbuying price: "<<_buy_price
           <<"\nselling price: "<<_sell_price
           <<"\n---"<<std::endl;
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

// new for week 4
double battery::profit() const
{
  return _sell_price - _buy_price;
}

// създаваме ново копие на батерията и променяме него
battery battery::operator+(double additional_price) const
{
  battery new_battery = *this;
  new_battery.set_sell_price(_sell_price + additional_price);
  return new_battery;
}

// за втория вариан на оператора ще изпозваме първия
battery operator+(double additional_price, battery& given_battery)
{
  return given_battery + additional_price;
}

battery battery::operator++()
{
  set_sell_price(_sell_price + 0.01);
  return *this;
}

battery battery::operator++(int)
{
  battery battery_to_return = *this;
  ++*this;
  return battery_to_return;
}

battery::operator double() const
{
  return profit();
}
