#include <iostream>
#include <memory>

#include "SearchEngine.hpp"
#include "SearchQuery.hpp"
#include "WebRessource.hpp"

int main()
{
    SearchEngine engine;

    auto cppResource = std::make_shared<WebRessource>(
        "https://cpp-tutorial.com",
        "C++ programming tutorial for beginners",
        80
    );

    auto searchResource = std::make_shared<WebRessource>(
        "https://search-engine.com",
        "Search engine ranking and web resource indexing",
        95
    );

    auto mixedCaseResource = std::make_shared<WebRessource>(
        "https://oop-example.com",
        "Object Oriented PROGRAMMING with classes and objects",
        70
    );

    auto lowRankResource = std::make_shared<WebRessource>(
        "https://basic-programming.com",
        "Basic programming examples and simple exercises",
        40
    );

    engine.addWebRessource(cppResource);
    engine.addWebRessource(searchResource);
    engine.addWebRessource(mixedCaseResource);
    engine.addWebRessource(lowRankResource);

    std::cout << "\n--- Query 1: programming, max 2 results ---\n";
    engine.setCurrentQuery(SearchQuery("programming", 2));
    engine.executeSearch();

    std::cout << "\n--- Query 2: SEARCH, max 3 results ---\n";
    engine.setCurrentQuery(SearchQuery("SEARCH", 3));
    engine.executeSearch();

    std::cout << "\n--- Query 3: invalid whitespace query ---\n";
    engine.setCurrentQuery(SearchQuery("   ", 3));
    engine.executeSearch();

    std::cout << "\n--- Query 4: no matching results ---\n";
    engine.setCurrentQuery(SearchQuery("python", 3));
    engine.executeSearch();

    std::cout << "\n--- Query 5: maxOutput = 1 ---\n";
    engine.setCurrentQuery(SearchQuery("programming", 1));
    engine.executeSearch();

    std::cout << "\n--- Derived attribute test: popularity ---\n";
    std::cout << cppResource->getURL()
              << " popular: "
              << (cppResource->isPopular() ? "yes" : "no")
              << std::endl;

    std::cout << searchResource->getURL()
              << " popular: "
              << (searchResource->isPopular() ? "yes" : "no")
              << std::endl;

    std::cout << "\n--- Static query counter / engine info ---\n";
    engine.printInfo();

    return 0;
}