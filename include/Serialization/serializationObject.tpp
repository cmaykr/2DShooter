#include "serializationObject.hpp"

#include <string>
#include <sstream>
#include <iostream>

template <typename T>
T SerializationObject::readValue(std::string const& keyword) const
{
    auto it = parsedLines.find(keyword);

    if (it == parsedLines.end())
    {
        throw std::out_of_range("Keyword not found, letter should only be lowercase."); // TODO: Better error message
    }

    std::istringstream ss{it->second};

    T value{};
    ss >> value;


    return value;
}