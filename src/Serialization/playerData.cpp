#include "Serialization/playerData.hpp"

PlayerData::PlayerData(std::string const& filename)
    : SerializationObject(filename)
{

}

void PlayerData::deSerialize()
{
    _speed = readValue<double>("speed");
}

double PlayerData::speed() const
{
    return _speed;
}