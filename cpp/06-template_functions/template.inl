#include <iostream>

namespace tp{


template <typename T>
size_t firstUnique(T* arr, size_t size)
{
	for (size_t i = 0; i < size ; ++i){
		bool isUnique = true;
		for (size_t j=0; j <size; ++j){
			if(i!=j && arr[i]==arr[j]){
				isUnique =false;
				break;
			}
		}
		
		if(isUnique){
			return i;
		}
	}
	std::cout<<"No uniques found";
	return -1;
}

template <typename T>
T smallest(T* arr, size_t size)
{
	T smallest =arr[0];
	for (size_t i =0;i<size;++i){
		if(arr[i]<smallest){
			smallest=arr[i];
		}
	}
	
	return smallest;
	
}

}
	
