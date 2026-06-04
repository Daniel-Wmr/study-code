#include <iostream>
#include <stdexcept>
#include <string>

class InvalidConfigException : public std::runtime_error
{
public:
    InvalidConfigException()
        : std::runtime_error("File is invalid."){}
};

class ConfigLoader
{
public:
void load(const std::string& filename) const;
};

void ConfigLoader::load(std::string filename) const
{
    if (filename.empty())
    {
        throw std::invalid_argument("Filename is empty.");
    }

    if (filename.size() < 4 ||
        filename.substr(filename.size() - 4) != ".cfg")
    {
        throw std::invalid_argument("File is not a CFG.");
    }

    if (filename == "missing.cfg")
    {
        throw std::runtime_error("File is invalid.");
    }

    if (filename == "invalid.cfg")
    {
        throw InvalidConfigException();

    }

    std::cout << "Configuration loaded successfully.\n";

}

int main()
{
    ConfigLoader loader;

    const std::string testFiles[] =
    {
        "",
        "test.txt",
        "missing.cfg",
        "invalid.cfg",
        "settings.cfg"
    };

    for (const auto& file : testFiles)
    {
        try
        {
            std::cout << "Loading: " << file << std::endl;
            loader.load(file);
        }
        catch (const std::exception& ex)
        {
            std::cout << "ERROR: " << ex.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "Unknown exception." << std::endl;
        }
    }

    return 0;
}