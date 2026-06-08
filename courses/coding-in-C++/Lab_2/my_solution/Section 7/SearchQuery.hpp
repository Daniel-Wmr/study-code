#ifndef SEARCH_QUERY_HPP
#define SEARCH_QUERY_HPP

#include <iostream>
#include <string>

#include "WebRessource.hpp"

class SearchQuery
{
private:
    static constexpr int DEFAULT_MAX_OUTPUT = 3;

    std::string query;
    int max_output;

public:
    SearchQuery(const std::string& query);
    SearchQuery(const std::string& query, int max_output);

    void setQuery(const std::string& query);
    std::string getQuery() const;
    void setMaxOutput(const int max_output);
    int getMaxOutput() const;

    bool isValid() const;

    ~SearchQuery() = default;
};


#endif