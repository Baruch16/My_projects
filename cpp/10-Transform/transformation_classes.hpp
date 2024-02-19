#ifndef TRANSFORMATION_CLASSES_HPP
#define TRANSFORMATION_CLASSES_HPP

#include "iostream"
#include "transform.hpp"

namespace st
{

class Upper : public Transform
{
public:
  void transform(std::string &str) const override;
};

class Lower : public Transform
{
public:
  void transform(std::string &str) const override;
};

class Shift : public Transform
{
public:

  Shift()
  {
    std::cout << "Enter the number of letters to shift: ";
    std::cin >> m_shift_distance_;
  }

  explicit Shift(int8_t shift) : m_shift_distance_(shift) {}

  void transform(std::string &str) const override;

private:
  int m_shift_distance_;
};


class Atbash :public Transform
{
public:
  void transform(std::string &str) const override;


};

} // namespace st
#endif