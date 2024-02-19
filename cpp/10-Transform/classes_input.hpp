#ifndef CLASSES_INPUT_HPP
#define CLASSES_INPUT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "input.hpp"

namespace st{

class String : public Input  
{
public:
    
    String(std::string& str):m_string(str){}
    std::string Get_string() override {return m_string;}

private:
    std::string m_string;

};

class Cin: public Input  
{
public:
    
    Cin(){std::getline(std::cin, m_string);}
    std::string Get_string() override {return m_string;}

private:
    std::string m_string;

};

class FileInput : public Input
{
public:
    FileInput(const std::string& file_name) {std::ifstream file(file_name); std::getline(file, m_string);} 

    std::string Get_string() override
    {   
        return m_string;
    }

private:
    std::string m_string;
};
}
#endif
