#include <fcbyk/utils.hpp>
using namespace std;

int main() {

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