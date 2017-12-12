#include "servicegood.h"

#include <sstream>

#include "Zone.h"
#include "supply.h"

using namespace CppInject;
extern Zone globalZone;

FileReader::FileReader(const std::string& path)
    : in(path)
{
}

std::string FileReader::read()
{
    std::string text;
    in >> text;
    return text;
}

StringReader::StringReader(const std::string &text)
    : text{text}
    , readed{false}
{
}

std::string StringReader::read()
{
    if (readed) {
        return std::string{};
    }

    readed = true;
    return text;
}

std::string ServiceGood::process()
{
    IDataReader* reader = supply<IDataReader>::fetch(globalZone);
    std::string cmd;
    std::stringstream ss;
    std::stringstream in;
    int a, b;
    in << reader->read();
    in >> cmd >> a >> b;
    if (cmd == "sum") {
        ss << a + b;
    } else {
        ss << "Error";
    }

    return ss.str();
}
