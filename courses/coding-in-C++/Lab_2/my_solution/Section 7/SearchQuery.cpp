#include <algorithm>

#include "SearchQuery.hpp"

SearchQuery::SearchQuery(const std::string& query)
    : query(query)
{
    this->max_output = DEFAULT_MAX_OUTPUT;
}

SearchQuery::SearchQuery(const std::string& query, const int max_output)
    : query(query), max_output(max_output){}

void SearchQuery::setQuery(const std::string& query)
{
    this->query = query;
}

std::string SearchQuery::getQuery() const
{
    return query;
}

void SearchQuery::setMaxOutput(const int max_output)
{
    if (max_output > 0)
    {
        this->max_output = max_output;
    }
    else
    {
        std::cout << "Invalid max_output valid! Setting to default..." << std::endl;
        this->max_output = DEFAULT_MAX_OUTPUT;
    }
}

int SearchQuery::getMaxOutput() const
{
    return max_output;
}

bool SearchQuery::isValid() const
{
    return query.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}