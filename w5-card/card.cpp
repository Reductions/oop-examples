#include <iostream>
#include <cstring>

#include "card.hpp"

//всичко конструктори първо извикват този
card::card(): _name(nullptr), _desc(nullptr){}

//създавва карта с дадено име и описание
card::card(const char* name, const char* desc)
  :card()
{
  set_name(name);
  set_desc(desc);
}

//създава копие на друга карта
card::card(const card& other)
  :card()
{
  _copy(other);
}

//присвоява стойността от друга карта на текущата
card& card::operator=(const card& other)
{
  //проверяваме дали не правим присвояване от типа X = X
  //ако това не е варно прибягваме до почистване на паметта заделена
  //от текущата карта и копиране след това
  if(this != &other){
    _destroy();
    _copy(other);
  }
  return *this;
}

//създавме нова карта като преместваме паметта управлявана от друга кара в новата
card::card(card&& other)
  :card()
{
  _move(other);
}

//преместваме съдържанието на друга карата в текущата
card& card::operator=(card&& other)
{
  //проверяваме дали не правим преметване от типа X = move(X)
  //ако това не е варно прибягваме до почистване на паметта заделена
  //от текущата карта и преметването на другата
  if(this != &other){
    _destroy();
    _move(other);
  }
  return *this;
}

//изтриваме паметта заделена за картата
card::~card()
{
  _destroy();
}

//помощна функция за изтриване на паметта
void card::_destroy()
{
  delete[] _name;
  delete[] _desc;
}

//помощна функция за копиране
//предполага, че нама заделена памет от текущата карт
void card::_copy(const card& other)
{
  set_name(other._name);
  set_desc(other._desc);
}

//помощна функция за преместване
//предполага, че нама заделена памет от текущата карт
void card::_move(card& other){
  _name = other._name;
  _desc = other._desc;
  other._name = nullptr;
  other._desc = nullptr;
}

//оператор за сравняване на карти
bool card::operator==(const card& other) const{
  return strcmp(_name, other._name) && strcmp(_desc, other._desc);
}

//оператор за сравняване на карти
bool card::operator!=(const card& other) const{
  return !(*this == other);
}

//мутаторите първо изтриват паметта заделена до сега за полето
//след това правят всики полезни действия
void card::set_name(const char* new_name)
{
  delete[] _name;
  int name_len = strlen(new_name);
  _name = new char[name_len + 1];
  strcpy(_name, new_name);
}

void card::set_desc(const char* new_desc)
{
  delete[] _desc;
  int desc_len = strlen(new_desc);
  _desc = new char[desc_len + 1];
  strcpy(_desc, new_desc);
}

const char* card::get_name() const{
  return _name;
}


const char* card::get_desc() const{
  return _desc;
}

void card::print() const
{
  std::cout<<"name: "<<_name
           <<"\ndesc: "<<_desc
           <<"\n";
}
