#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
namespace st
{
class Input
{
public:
    virtual ~Input() = default;
    virtual std::string Get_string() = 0;
};
}
#endif