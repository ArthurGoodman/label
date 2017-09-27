#include "application.hpp"

#include <iostream>
#include <stdexcept>

#include "algorithm.hpp"

namespace label {

Application::Application(int argc, char **argv) {
    parseArgs(argc, argv);
}

void Application::exec() {
    if (m_action)
        Algorithm::run(m_fileName, m_verbose);
}

void Application::parseArgs(int argc, char **argv) {
    if (argc <= 1)
        return;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--input" || arg == "-i") {
            i++;

            if (i == argc)
                throw std::runtime_error("input file name expected");

            m_fileName = argv[i];
        } else if (arg == "--verbose" || arg == "-v") {
            m_verbose = true;
        } else if (arg == "--help" || arg == "-h") {
            m_action = false;

            std::cout << "This is help." << std::endl;
        } else {
            throw std::runtime_error("invalid command line option '" + arg + "'");
        }
    }
}

} // namespace label
