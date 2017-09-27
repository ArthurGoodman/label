#pragma once

#include <string>

namespace label {

class Application {
public:
    Application(int argc, char **argv);

    void exec();

private:
    void parseArgs(int argc, char **argv);

private:
    bool m_verbose = false;
    bool m_action = true;

    std::string m_fileName = "data.json";
};

} // namespace label
