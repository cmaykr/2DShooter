#pragma once

#include <string>
#include <map>

// INFO: Should this class be able to read from a stream instead of a file?

class SerializationObject
{
public:
    SerializationObject(std::string const& filename);
    virtual ~SerializationObject() = default;

protected:
    virtual void deSerialize() = 0;
    /// @brief Reads one line from a chosen file.
    /// @tparam Type Should be the type the value on the line is.
    /// @param keyword Which word in the file the function will search for to read in the value.
    /// @return The value on the same line the keyword is on. 
    template <typename T>
    T readValue(std::string const& keyword) const;
private:
    std::string filename;
    std::map<std::string, std::string> parsedLines{};
};

#include "serializationObject.tpp"