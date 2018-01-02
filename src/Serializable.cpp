#include "Serializable.h"

Serializable::Serializable()
{
    //ctor
}

Serializable::~Serializable()
{
    //dtor
}

void Serializable::serialize(std::ostream& stream){}
void Serializable::deserialize(std::istream& stream){}
