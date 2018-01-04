#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <fstream>

class Serializable
{
public:
    Serializable(){}
    virtual ~Serializable(){}

    virtual void serialize(std::ostream& stream) = 0;
    virtual void deserialize(std::istream& stream) = 0;
};

#endif // SERIALIZABLE_H