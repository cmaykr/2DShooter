#include "deSerialization.hpp"

#include <string>
#include <sstream>

template <typename T>
T DeSerialization::readValue(std::string const& keyword) const
{
    // TODO: Make it not bad code.
    // Function should only read one line and return the lines value.
    // Currently reads the whole file.

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