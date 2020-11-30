#pragma once

/**
  * @brief
  *  Шаблон функции print_ip
  *  Принимаемые типы данных:
  *  char
  *  int
  *  vector
  *  list
  *  string
  *
  * @see https://ru.cppreference.com/w/cpp/types/enable_if
  */

#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <string>
#include <sstream>
#include <type_traits>
#include <algorithm>


template<typename>
struct is_list_or_vec : std::false_type{};

template<typename T, typename ... Args>
struct is_list_or_vec<std::vector<T, Args...>>:std::true_type{};

template<typename T, typename ... Args>
struct is_list_or_vec<std::list<T, Args...>>:std::true_type{};

/**
 * @brief
 * Конвертирует std::vector или std::list в строку, разделяет элементы точками.
 *
 * @param t std::vector или std::list, который необходимо отконвертировать
 *
 * @return
 * std::string строка, полученная в результате перевода
 */
template<
        typename VecOrList,
        class = typename std::enable_if<is_list_or_vec<VecOrList>::value>::type
>
std::string print_ip(const VecOrList& t)
{
    std::stringstream result;
    for (auto i = t.cbegin(); i != t.cend(); i++ )
    {
        if (i != t.cbegin())
        {
            result << ".";
        }
        result << *i;
    }
    return result.str();
}

/**
 * @brief
 * Конвертирует std::integral в std::string
 * К std::integral относятся целочисленные типы, в том числе char и bool
 *
 * @param ip integral для конвертации
 *
 * @return
 * std::string результат конвертации в строку
 */
template<typename Integral, class = typename std::enable_if<std::is_integral<Integral>::value>::type>
std::string print_ip(Integral ip) {
    std::stringstream res;
    unsigned char* octetPointer = (unsigned char*)(&ip);  // Read max 255 value for once, because of unsigned char
    for(size_t i = 0; i < sizeof(ip); i++){
        int octet = *(octetPointer + sizeof(ip) - i - 1);
        if(i != 0){
            res << ".";
        }
        res << octet;
    }
    return res.str();
}

template <typename Str>
struct is_string: std::false_type{};

template <>
struct is_string<std::string>: std::true_type{};

/**
 * @brief
 * Возвращает переданную строку, не изменяя ее
 *
 * @param str Строка, которую необходимо вернуть
 *
 * @return
 * std::string исходная строка
 */
template<typename Str, class = typename std::enable_if<is_string<Str>::value>::type>
std::string print_ip(Str & str){
    return std::string(str);
}