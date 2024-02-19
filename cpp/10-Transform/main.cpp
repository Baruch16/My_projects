#include <iostream>
#include<string>
#include<fstream>
#include "transformation_classes.hpp"
#include"messenger.hpp"
#include"classes_input.hpp"


using namespace st;

void test_upper_cout_string(){

     std::string input_str="hello world";
     String stri(input_str);
     Upper upper_transformer;
     Cout out;
     std::cout << "After upper transformation: ";
     string_transform(stri, upper_transformer, out);
     std::cout << std::endl;
}

void test_upper_cout_cin(){

    std::cout<<"Please enter the desired string"<<std::endl;
    Cin stri;
    Upper upper_transformer;
    Cout out;
    std::cout << "After upper transformation: ";
    string_transform(stri, upper_transformer, out);
    std::cout << std::endl;
}


void test_lower_cout_cin(){
    std::cout<<"Please enter the desired string"<<std::endl;
    Cin stri;
    Lower lower_transformer;
    Cout out;
    std::cout << "After lower transformation: ";
    string_transform(stri, lower_transformer, out);
    std::cout << std::endl;

}

void test_upper_cout_fin(){

    std::string name="we";
    FileInput inp(name);
    Upper upper_transformer;
    Cout out;
    std::cout << "After upper transformation of file" <<" "<<name <<":";
    string_transform(inp, upper_transformer, out);
    std::cout << std::endl;
}


void test_upper_fout_fin(){
    std::string name="we";
    FileInput inp(name);
    Upper upper_transformer;
    FileOutput output("output.txt");
    string_transform(inp,upper_transformer,output);
    std::cout<<std::endl;
}


void test_shift_cout_string(){

    std::string input_str="abcdefg";
    String stri(input_str);
    Cout out;
    Shift shifter;
    std::cout << "Before sift:" <<" " << input_str<<std::endl;
    std::cout << "After shift ";
    string_transform(stri,shifter, out);
    std::cout << std::endl;
}

void test_atbash_cout_string(){

    std::string input_str="abcdefghijklmnopqrstuvwxyz";
    String stri(input_str);
    Cout out;
    Atbash atbash;
    std::cout << "Before Atbash:" <<" " << input_str<<std::endl;
    std::cout << "After Atbash ";
    string_transform(stri,atbash, out);
    std::cout << std::endl;
}
int main()
{   
     
    test_upper_cout_string();
    test_upper_cout_cin();
    test_lower_cout_cin();
    test_upper_cout_fin();
    test_upper_fout_fin();
    test_shift_cout_string();
    test_atbash_cout_string();
    
    return 0;
}

