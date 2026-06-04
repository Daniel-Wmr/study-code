#include <iostream>
#include <stdexcept>

class ConfigLoader
{
public:
void load(std::string filename) const;
};

void ConfigLoader::load(std::string filename) const
{
    if (filename.empty())
    {
        throw std::invalid_argument("Filename is empty.");
    }

    
}

int main()
{

    return 0;
}