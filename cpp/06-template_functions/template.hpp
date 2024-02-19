#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <cstddef>

namespace tp{
	
	template <typename T>
	size_t firstUnique(T* arr, size_t size);
	
	template <typename T>
	T smallest(T* arr, size_t size);
	

}
#include "template.inl"

#endif
