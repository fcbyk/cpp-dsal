#include <fcbyk/utils.hpp>
#include <fcbyk/algo.hpp>
#include <iostream>
using namespace std;

int main() {

    cout << fcbyk::highPrecisionSubtract("1000","9999");

    return 0;
}

int test_print() {

    fcbyk::print({1,32,43,23});
    cout << endl;
    fcbyk::print("wwww\naaa\n");

    fcbyk::println(42);
    fcbyk::println(3.14);
    fcbyk::println(true);
    fcbyk::println("Hello");
    fcbyk::println( {'a', 'b', 'c'});
    fcbyk::println("Value:", 42, "is valid");

    return 0;
}