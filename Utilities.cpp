#include "Utilities.hpp"


Utilities::Utilities()
{

}

Utilities::~Utilities()
{

}


int Utilities::randInt(const int lower_bound, const int upper_bound)
{
    static std::random_device rd;
    static std::mt19937 rng{rd()};

    return std::uniform_int_distribution<int>{lower_bound, upper_bound}(rng);
}