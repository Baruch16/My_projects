#ifndef OUTPUT_HPP
#define OUtPUT_HPP

#include<string>
namespace st{

class Output
{ 
    public:
    virtual ~Output()=default;
    virtual void output(const std::string& string)=0;



};

}

#endif