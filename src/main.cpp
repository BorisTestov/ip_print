#include "version.h"
#include <iostream>
#include <map>
#include "ip_print.h"

int main() {
  std::cout << "Current version: " << version() << std::endl;

    char char_value = -1;
    std::cout << print_ip(char_value) << std::endl;
    short short_value = 0;
    std::cout << print_ip(short_value) << std::endl;
    int int_value = 2130706433;
    std::cout << print_ip(int_value) << std::endl;
    long long long_value = 8875824491850138409;
    std::cout << print_ip(long_value) << std::endl;
    std::vector vector_value = {1,2,3};
    std::cout << print_ip(vector_value) << std::endl;
    std::list list_value = {1,2,3};
    std::cout << print_ip(list_value) << std::endl;
    std::string str_value = "trololo";
    std::cout << print_ip(str_value) << std::endl;
  return 0;
}
