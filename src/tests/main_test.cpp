#include "main_test.h"
#include "ip_print.h"
#include "moc_main_test.cpp"

void TestMain::TestVersion() { QCOMPARE((int)version().find("0.0."), 0); }

void TestMain::TestPrint()
{
    char char_value = -1;
    std::string expectedResult = "255";
    QCOMPARE(print_ip(char_value), expectedResult);
    short short_value = 0;
    expectedResult = "0.0";
    QCOMPARE(print_ip(short_value), expectedResult);
    int int_value = 2130706433;
    expectedResult = "127.0.0.1";
    QCOMPARE(print_ip(int_value), expectedResult);
    long long long_value = 8875824491850138409;
    expectedResult = "123.45.67.89.101.112.131.41";
    QCOMPARE(print_ip(long_value), expectedResult);
    std::vector vector_value = {1,2,3};
    expectedResult = "1.2.3";
    QCOMPARE(print_ip(vector_value), expectedResult);
    std::list list_value = {1,2,3};
    expectedResult = "1.2.3";
    QCOMPARE(print_ip(list_value), expectedResult);
    std::string str_value = "trololo";
    expectedResult = "trololo";
    QCOMPARE(print_ip(str_value), expectedResult);
}