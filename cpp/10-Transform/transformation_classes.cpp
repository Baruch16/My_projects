#include "transformation_classes.hpp"

namespace st{

void Upper::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();
    while (it != end_it) {
        if (*it >= 97 && *it <= 122) {
            *it -= 32;
        }
        ++it;
    }
}

void Lower::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();
        while (it != end_it) {
            if (*it >= 65 && *it <= 90) {
                *it += 32;
            }
        ++it;
        }
}

void Shift::transform(std::string& str) const
  {
    for (char& c : str)
    {
      if (isalpha(c))
      {
        char base = islower(c) ? 'a' : 'A';
        c = (c - base + m_shift_distance_ + 26) % 26 + base;
      }
    }
  }


void Atbash::transform(std::string & str)const
{
    auto it = str.begin();
    while (it != str.end()) {
      char c = *it;
      if (c >= 'a' && c <= 'z') {
        *it = 'z' - (c - 'a');
      } else if (c >= 'A' && c <= 'Z') {
        *it = 'Z' - (c - 'A');
      }
      it++;
    }
  }

    


} // namespace st

