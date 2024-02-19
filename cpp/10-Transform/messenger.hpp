#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <string>
#include <iostream>
#include "transform.hpp"
#include "input.hpp"
#include "classes_output.hpp"

namespace st {

Output& string_transform(Input& in, Transform& tr, Output& os)
{   
    std::string str = in.Get_string();
    tr.transform(str);   
    os.output(str);
    return os;
}


} // namespace st

#endif