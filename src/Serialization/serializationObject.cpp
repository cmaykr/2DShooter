#include "Serialization/serializationObject.hpp"

#include <fstream>
#include <algorithm>

SerializationObject::SerializationObject(std::string const& _filename)
    : filename(_filename)
{
    std::ifstream ifs{"resources/" +  filename};

    std::string line{};

    while (getline(ifs, line))
    {
        auto it = std::find(line.begin(), line.end(), ':');

        if (it == line.end())
        {
            throw std::out_of_range(": not found in line, check resource file."); // TODO: Better error message
        }

        std::string key{line.begin(), it};
        std::string value{++it, line.end()};

        parsedLines[key] = value;
    }
}