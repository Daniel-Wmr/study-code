#include <algorithm>

#include "SearchEngine.hpp"

int SearchEngine::total_queries = 0;

SearchEngine::SearchEngine()
    : current_query(""){}

bool SearchEngine::searchInRessources()
{
    current_search_results.clear();

    if (!current_query.isValid())
    {
        std::cout << "Invalid query!" << std::endl;
        return false;
    }

    incTotalQueries();

    for (const auto& ressource : web_ressources)
    {
        if (ressource && 
            ressource->getContent().find(current_query.getQuery()) != std::string::npos)
            {
                updateCurrentSearchResults(ressource);
            } 
    }

    sortCurrentRessources();

    return !current_search_results.empty();
}

void SearchEngine::updateCurrentSearchResults(
    const std::shared_ptr<WebRessource>& ressource)
{
    current_search_results.push_back(ressource);
}

void SearchEngine::addWebRessource(const std::shared_ptr<WebRessource>& ressource)
{
    web_ressources.push_back(ressource);
}

void SearchEngine::removeWebRessource(const std::shared_ptr<WebRessource>& ressource)
{
    auto it = std::find(web_ressources.begin(), web_ressources.end(), ressource);

    if (it != web_ressources.end())
    {
        web_ressources.erase(it);
    }
    else
    {
        std::cout << "Deleting Web Ressource failed! Ressource not found..." << std::endl;
    }
}

void SearchEngine::setCurrentQuery(const SearchQuery& query)
{
    current_query = query;
}

SearchQuery SearchEngine::getCurrentQuery() const
{
    return current_query;
}

std::shared_ptr<WebRessource> SearchEngine::getWebRessource(const int index) const
{
    return web_ressources.at(index);
}

int SearchEngine::getSearchResultCount() const
{
    return current_search_results.size();
}

void SearchEngine::sortCurrentRessources()
{
    std::sort(current_search_results.begin(), 
            current_search_results.end(),
            [](const auto& a, const auto& b)
            {
                if (!a) return false;
                if (!b) return true;

                return a->getRanking() > b->getRanking();
            });
}

void SearchEngine::executeSearch()
{
    if (searchInRessources())
    {
        printRelevantRessources();
    }
    else
    {
        std::cout << "No matching ressource found..." << std::endl;
    }
}

void SearchEngine::printRelevantRessources() const
{
    int counter = 0;

    std::cout << "=== Relevant Resources ===" << std::endl;
    
    for (const auto& resource : current_search_results)
    {
        if (counter >= current_query.getMaxOutput())
        {
            return;
        }

        resource->printRessource();
        std::cout << std::endl;

        counter++;
    }
}

void SearchEngine::printInfo() const
{
    std::cout << "=== Search Engine Info ===" << std::endl;
    std::cout << "Total Queries since usage: " << getTotalQueries() << std::endl;
    std::cout << "Amount of Web Resources: " << web_ressources.size() << std::endl;
    std::cout << "Current query: " << current_query.getQuery() << std::endl;
    std::cout << "Maximum output of resources: " << current_query.getMaxOutput() << std::endl;
    std::cout << "Amount of current search solutions: " << current_search_results.size() << std::endl;
}

int SearchEngine::getTotalQueries()
{
    return total_queries;
}

void SearchEngine::incTotalQueries()
{
    total_queries++;
}