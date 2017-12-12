#include "servicebad.h"

#include <fstream>
#include <sstream>

std::string ServiceBad::process(const std::string& path)
{
    std::ifstream in(path);
    std::string cmd;
    std::stringstream ss;
    int a, b;
    in >> cmd >> a >> b;
    if (cmd == "sum") {
        ss << a + b;
    } else {
        ss << "Error";
    }

    return ss.str();
}
