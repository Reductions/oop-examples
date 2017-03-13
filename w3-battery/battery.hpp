#ifndef BATTERY_HPP
#define BATTERY_HPP

class battery
{
public:

  enum class country {
    Japan,
    Germany,
    China,
    Tiwan
  };

  //constructor
  battery(int id, country origin, double buy_price);

  //accesors
  int get_id() const;
  const char* get_origin_by_name() const;
  double get_sell_price() const;

  //mutators
  void set_sell_price(double new_price);

  //print methods
  void print() const;

private:
  int _id;
  country _origin;
  double _buy_price;
  double _sell_price;
};

#endif//BATTERY_HPP
