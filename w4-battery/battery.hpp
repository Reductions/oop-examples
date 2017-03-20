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

  //other functions
  double profit() const;

  //print methods
  void print() const;

  //operators

  // operator+
  // Когато операторът е дефиниран в клас, то първият му аргумент
  // винаги е инстанция от този клас, затова задаваме само втория
  // параметър.
  battery operator+(double additional_price) const;

  // operator++
  // префиксен оператор променя обекта и връща променения обект
  battery operator++();

  // operator++(int)
  // суфиксен оператор променя обекта, но връща старата му стойност
  battery operator++(int);

  // operator double()
  // Оператор за преобразуване. В нашия случай преобразуване ще дава
  // печалбата при евентуална продажба на тази цена
  operator double() const;
private:
  int _id;
  country _origin;
  double _buy_price;
  double _sell_price;
};

// Когато искаме да направим оператор чиито първи параметър не е инстанция от
// класа, който дефинираме, то опреаторът трябва да дефиниран извън класа.
battery operator+(double additional_price, battery& battery);

#endif//BATTERY_HPP
