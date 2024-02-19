#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <string>


namespace st {

class Transform 
{
public:
    virtual ~Transform() = default;

    virtual void transform(std::string& str) const = 0;
};




}

#endif