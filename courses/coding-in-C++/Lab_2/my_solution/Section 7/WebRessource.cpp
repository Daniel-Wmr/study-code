#include <iostream>
#include <string>

#include "WebRessource.hpp"

WebRessource::WebRessource(const std::string& url, const std::string& content, const int ranking)
    : url(url), content(content), ranking(ranking){}

void WebRessource::setURL(const std::string& url)
{
    if (url.substr(START_POS_URL_CHECK, AMOUNT_SYM_URL_CHECK) == "https://")
    {
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
    std::cout << "Content: " << content << std::endl;
}

bool WebRessource::isPopular() const
{
    return ranking >= POPULARITY_THRESHOLD;
}