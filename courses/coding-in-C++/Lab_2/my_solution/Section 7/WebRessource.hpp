#ifndef WEB_RESSOURCE_HPP
#define WEB_RESSOURCE_HPP

#include <iostream>
#include <string>

constexpr int START_POS_URL_CHECK = 0;
constexpr int AMOUNT_SYM_URL_CHECK = 8;

class WebRessource
{
private:
    static constexpr int POPULARITY_THRESHOLD = 80;

    std::string url;
    std::string content;
    int ranking;

public:
    WebRessource(const std::string& url, const std::string& content, const int ranking);

    void setURL(const std::string& url);
    std::string getURL() const;
    void setContent(const std::string& content);
    std::string getContent() const;
    void updateRanking();
    int getRanking() const;

    void printRessource() const;

    bool isPopular() const;

    ~WebRessource() = default;
};


#endif