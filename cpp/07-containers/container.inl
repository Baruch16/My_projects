#include <iostream>
#include <array>
#include <cassert>
namespace co{


template <typename Container>
bool is_sorted(const Container &c) {
    typename Container::const_iterator first = c.begin();
    typename Container::const_iterator last = c.end();
    assert(first != last);
    for (typename Container::const_iterator i = first; i != last; ++i) {
        if (*i > *std::next(i)) {
            return false;
        }
    }
    return true;
}

template <typename Container, typename Compare>
bool is_sorted_obj(const Container &c, Compare comp) {
    typename Container::const_iterator first = c.begin();
    typename Container::const_iterator last = c.end();
    assert(first != last);
    for (typename Container::const_iterator i = first; i != last; ++i) {
        if (comp(*i, *std::next(i))) {
            return false;
        }
    }
    return true;
}

template <typename Container>
typename Container::iterator findFirstDuplicate(Container &container) {
  typename Container::iterator first = container.begin();
  typename Container::iterator last = container.end();

  for (typename Container::iterator i = first; i != last; ++i) {
    for (typename Container::iterator j = i; j != last; ++j) {
      if (*i == *j) {
        return i;
      }
    }
  }
  return last;
}


template <typename Container>
typename Container::iterator findFirstUnique(Container &container) {

  typename Container::iterator first = container.begin();
  typename Container::iterator last = container.end();
  for (typename Container::iterator  i = first; i != last; ++i) {
    bool is_unique = true;
    for (typename Container::iterator  j = first; j != last; ++j) {
      if (i != j && *i == *j) {
        is_unique = false;
        break;
      }
    }
    if (is_unique) {
      return i;
    }
  }
  return last;
}

}

