#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <cstddef>
#include <array>

namespace co{

	
	
	template <typename Container>
	bool is_sorted(const Container &c) ;
	
	template <typename Container>
	bool is_sorted_obj(const Container &c) ;
	
	template <typename Container>
	typename Container::iterator findFirstDuplicate(Container &container);
	
	template <typename Container>
	typename Container::iterator findFirstUnique(Container &container);
	
	
	
}

#include "container.inl"
#endif
