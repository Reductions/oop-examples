#ifndef CARD_HPP
#define CARD_HPP

class card{
  char* _name;
  char* _desc;

public:
  //конструктор по подразбиране
  card();
  //конструктор с параметри
  card(const char* _name, const char* _desc);
  //копиращ конструктор и оператор за присвояване
  card(const card& other);
  card& operator=(const card& other);
  //местещ конструктор и местещ оператор за присвояване
  card(card&& other);
  card& operator=(card&& other);
  //деструктор
  ~card();

  //мутатори
  void set_name(const char* new_name);
  void set_desc(const char* new_desc);

  //аксесори
  const char* get_name() const;
  const char* get_desc() const;

  void print() const;

  //оператор за сравнение
  bool operator==(const card& other) const;
  bool operator!=(const card& other) const;

private:
  void _destroy();
  void _copy(const card& other);
  void _move(card& other);
};

#endif//CARD_HPP
