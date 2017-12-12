#ifndef SERVICE_GOOD_H
#define SERVICE_GOOD_H

#include <string>
#include <fstream>

class IDataReader
{
public:
    virtual ~IDataReader() {}
    virtual std::string read() = 0;
};

class FileReader : public IDataReader
{
public:
    FileReader(const std::string& path);
    std::string read() override;
private:
    std::ifstream in;
};

class StringReader : public IDataReader
{
public:
    StringReader(const std::string& text);
    std::string read() override;
private:
    std::string text;
    bool readed;
};

class ServiceGood
{
public:
    std::string process();
};

#endif // SERVICE_GOOD_H
