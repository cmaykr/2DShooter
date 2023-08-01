#pragma once

#include "serializationObject.hpp"

#include <string>

class PlayerData : public SerializationObject
{
public:
    PlayerData(std::string const& filename);

    void deSerialize() override;

    double speed() const;
private:
    double _speed{};

};