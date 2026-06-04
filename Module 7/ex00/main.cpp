#include "whatever.hpp"

// class test
// {
// private:
//     int _nbr;

// public:
//     test(int nbr);
//     ~test();
//     bool operator>(test &other);
//     bool operator<(test &other);
//     int getNum(void);
// };
// test::test(int nbr) : _nbr(nbr) {}
// test::~test() {}
// bool test::operator>(test &other) { return this->_nbr > other._nbr; }
// bool test::operator<(test &other) { return this->_nbr < other._nbr; }
// int test::getNum() { return _nbr; }

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // prueba

    // test prueba1 = test(2);
    // test prueba2 = test(7);
    // std::cout << "min( prueba1, prueba2 ) = " << ::min(prueba1, prueba2).getNum() << std::endl;
    // std::cout << "max( prueba1, prueba2 ) = " << ::max(prueba1, prueba2).getNum() << std::endl;

    return 0;
}