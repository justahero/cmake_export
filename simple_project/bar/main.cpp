#include <iostream>
#include <foo/foo.h>

int main(int argc, char* argv[]) {
    std::cout << "Sum of 2 + 2 = " << Foo::add(2, 2) << std::endl;
    return 0;
}