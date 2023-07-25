#pragma once

#include <string>

class DeSerialization
{
public:
    DeSerialization(std::string const& filename);
    virtual ~DeSerialization() = default;

    virtual void DeSerialize() const;

    /// @brief Reads one line from a chosen file.
    /// @tparam Type Should be the type the value on the line is.
    /// @param keyword Which word in the file the function will search for to read in the value.
    /// @return The value on the same line the keyword is on. 
    template <typename T>
    T readLine(std::string const& keyword) const;
private:
    std::string filename;
};

#include "deSerialization.tpp"