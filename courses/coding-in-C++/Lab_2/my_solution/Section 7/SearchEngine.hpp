#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "SearchQuery.hpp"
#include "WebRessource.hpp"

class SearchEngine
{
private:
    static int total_queries;

    std::vector<std::shared_ptr<WebRessource>> web_ressources;
    std::vector<std::shared_ptr<WebRessource>> current_search_results;

    SearchQuery current_query;

    bool searchInRessources();
    void updateCurrentSearchResults(const std::shared_ptr<WebRessource>& ressource);

public:
    SearchEngine();

    void addWebRessource(const std::shared_ptr<WebRessource>& ressource);
    void removeWebRessource(const std::shared_ptr<WebRessource>& url);
    
    void setCurrentQuery(const SearchQuery& query);
    SearchQuery getCurrentQuery() const;
    std::shared_ptr<WebRessource> getWebRessource(const int index) const;
    int getSearchResultCount() const;
    void sortCurrentRessources();
    
    void executeSearch();
    void printRelevantRessources() const;

    void printInfo() const;

    static int getTotalQueries();
    static void incTotalQueries();

    ~SearchEngine() = default;
};


#endif