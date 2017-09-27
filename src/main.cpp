#include <iostream>
#include <stdexcept>

#include "application.hpp"

int main(int argc, char **argv) {
    try {
        label::Application app(argc, argv);
        app.exec();
    } catch (const std::runtime_error &e) {
        std::cout << "runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Something bad happened..." << std::endl;
    }

    return 0;
}
