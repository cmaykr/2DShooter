#include "deSerialization.hpp"

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <stdexcept>

template <typename T>
T DeSerialization::readLine(std::string const& keyword) const
{
    // TODO: Make it not bad code.
    // Function should only read one line and return the lines value.
    // Currently reads the whole file.

    std::ifstream ifs{"resources/" + filename};

    std::vector<std::string> lines{};
    
    std::string line{};
    while (getline(ifs, line))
    {
        lines.push_back(line);
    }

    std::map<std::string, T> parsed{};

    std::for_each(lines.begin(), lines.end(),
    [&parsed](std::string const& line)
    {
        auto it = std::find(line.begin(), line.end(), ':');

        if (it == line.end())
        {
            throw std::out_of_range(": not found in line, check resource file.");
        }

        T value{};
        std::string key{};
        it++;
        std::copy(line.begin(), it, std::inserter(key, key.begin()));
        it++;
        std::copy(it, line.end(), std::inserter(value, value.begin()));

        parsed[key] = value;

        std::cout << key << " " << value << std::endl;
    }
    );


    ifs.close();

    return "parsed.begin()->second()";
}