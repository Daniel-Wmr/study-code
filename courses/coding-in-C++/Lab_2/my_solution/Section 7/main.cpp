#include <iostream>
#include <memory>
#include <stdexcept>

#include "SearchEngine.hpp"
#include "SearchQuery.hpp"
#include "WebRessource.hpp"

int main()
{
    std::cout << "===== SEARCH ENGINE DEMO =====\n" << std::endl;

    SearchEngine engine;

    /*
     * Exception Demonstration
     */
    std::cout << "--- Exception Demonstration ---" << std::endl;

    try
    {
        auto invalidResource = std::make_shared<WebRessource>(
            "http://invalid-url.com",
            "Invalid URL example",
            50
        );
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Caught exception: "
                  << e.what()
                  << std::endl;
    }

    try
    {
        auto invalidRanking = std::make_shared<WebRessource>(
            "https://valid-url.com",
            "Negative ranking example",
            -10
        );
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Caught exception: "
                  << e.what()
                  << std::endl;
    }

    std::cout << std::endl;

    /*
     * Create Resources
     */
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

    /*
     * Add Resources
     */
    engine.addWebRessource(cppResource);
    engine.addWebRessource(searchResource);
    engine.addWebRessource(mixedCaseResource);
    engine.addWebRessource(lowRankResource);

    /*
     * Search #1
     */
    std::cout
        << "\n--- Query 1: programming (max 2 results) ---"
        << std::endl;

    engine.setCurrentQuery(SearchQuery("programming", 2));
    engine.executeSearch();

    /*
     * Search #2
     */
    std::cout
        << "\n--- Query 2: SEARCH (case insensitive) ---"
        << std::endl;

    engine.setCurrentQuery(SearchQuery("SEARCH", 3));
    engine.executeSearch();

    /*
     * Invalid Query
     */
    std::cout
        << "\n--- Query 3: whitespace only ---"
        << std::endl;

    engine.setCurrentQuery(SearchQuery("   ", 3));
    engine.executeSearch();

    /*
     * No Result Query
     */
    std::cout
        << "\n--- Query 4: no results ---"
        << std::endl;

    engine.setCurrentQuery(SearchQuery("python", 3));
    engine.executeSearch();

    /*
     * Max Output Test
     */
    std::cout
        << "\n--- Query 5: maxOutput = 1 ---"
        << std::endl;

    engine.setCurrentQuery(SearchQuery("programming", 1));
    engine.executeSearch();

    /*
     * Derived Attribute
     */
    std::cout
        << "\n--- Derived Attribute: Popularity ---"
        << std::endl;

    std::cout
        << cppResource->getURL()
        << " -> "
        << (cppResource->isPopular() ? "Popular" : "Not Popular")
        << std::endl;

    std::cout
        << searchResource->getURL()
        << " -> "
        << (searchResource->isPopular() ? "Popular" : "Not Popular")
        << std::endl;

    /*
     * out_of_range Exception
     */
    std::cout
        << "\n--- Out Of Range Demonstration ---"
        << std::endl;

    try
    {
        auto invalidAccess = engine.getWebRessource(999);
    }
    catch (const std::out_of_range& e)
    {
        std::cout
            << "Caught exception: "
            << e.what()
            << std::endl;
    }

    /*
     * Statistics
     */
    std::cout
        << "\n--- Search Engine Statistics ---"
        << std::endl;

    engine.printInfo();

    return 0;
}