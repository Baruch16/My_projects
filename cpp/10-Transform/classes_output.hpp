#ifndef CLASSES_OUTPUT_HPP
#define CLASSES_OUTPUT_HPP


#include <fstream>
#include <iostream>
#include <string>
#include "output.hpp"

namespace st{
class Cout : public Output
{
public:
    Cout() = default;
    void output(std::string const& str) override{std::cout << str << std::endl;}

};

class FileOutput : public Output
{
public:
    FileOutput(std::string const& file_name) : m_file(file_name) {}

    void output(const std::string& string) override
    {
        m_file << string << std::endl;
    }
      

private:
    std::ofstream m_file;
};

}

#endif
