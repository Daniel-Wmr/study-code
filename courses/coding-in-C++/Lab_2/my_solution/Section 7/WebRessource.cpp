#include <iostream>
#include <string>
#include <stdexcept>

#include "WebRessource.hpp"

WebRessource::WebRessource(const std::string& url, const std::string& content, const int ranking)
{
    if (url.rfind("https://", 0) != 0)
    {
        throw std::invalid_argument("URL must start with https://");
    }

    if (ranking < 0)
    {
        throw std::invalid_argument("Ranking must not be negative.");
    }

    this->url = url;
    this->content = content;
    this->ranking = ranking;
}

void WebRessource::setURL(const std::string& url)
{
    if (url.rfind("https://", 0) == 0)    {
        this->url = url;
    }
    else
    {
        std::cout << "Invalid URL! CANNOT SET NEW URL..." << std::endl; 
    }
}

std::string WebRessource::getURL() const
{
    return url;
}

void WebRessource::setContent(const std::string& content)
{
    this->content = content;
}

std::string WebRessource::getContent() const 
{
    return content;
}

void WebRessource::updateRanking()
{
    ranking += 5;
}

int WebRessource::getRanking() const 
{
    return ranking;
}

void WebRessource::printRessource() const 
{
    std::cout << "URL: " << url << std::endl;
    std::cout << "Ranking: " << ranking << std::endl;
    std::cout << "Popular: " << (isPopular() ? "Yes" : "No") << std::endl;
    std::cout << "Content: " << content << std::endl;
}

bool WebRessource::isPopular() const
{
    return ranking >= POPULARITY_THRESHOLD;
}