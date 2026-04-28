#include <iostream>
#include <string>
#include <iomanip>

constexpr int ZERO_INT = 0;
constexpr double ZERO_DOUBLE = 0.0;
constexpr double HUNDRED_DOUBLE = 100.0;

class Article {
private:
    const std::string name;
    double price;
    int stock;
    const std::string category;
    int id;

public:
    Article(const std::string name, double price,  int stock, const std::string category, int id) 
    : name(name), price(price), stock(stock), category(category), id(id)
    {}

    void setPrice(double price);
    void sell(int amount);
    void restock(int amount);
    void applyDiscount(double percent);
    const double getPrice();
    const bool isAvailable();
    const void printInfo();

};


void Article::setPrice(double price) {
    this->price = price;
}

void Article::sell(int amount) {
    if (amount <= ZERO_INT)
    {
        std::cout << "Your amount has to be greater than 0!" << std::endl;
        return;
    }
    else if (this->stock <= ZERO_INT || this->stock < amount)
    {
        std::cout << "There are not enough articles in the stock..." << std::endl;
        return;
    }

    this->stock -= amount;
}

void Article::restock(int amount) {
    if (amount <= ZERO_INT)
    {
        std::cout << "Your amount has to be greater than 0!" << std::endl;
        return;
    }
        
    this->stock += amount;
}

void Article::applyDiscount(double percent) {
    if (percent <= ZERO_DOUBLE || percent >= HUNDRED_DOUBLE)
    {
        std::cout << "Percentage invalid. Please enter a percentage between 0.0 and 100.0!" << std::endl;
        return;
    }
    this->price = this->price - this->price * (percent / 100);
}

const double Article::getPrice() {
    return this->price;
}

const bool Article::isAvailable() {
    if (this->stock > ZERO_INT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const void Article::printInfo() {
    std::cout << "Article: " << this->name << std::endl;
    std::cout << "Category: " << this->category << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Stock: " << this->stock << std::endl;
    std::cout << "ID: " << this->id << std::endl;
}

int main() {
    Article article ("Laptop", 999.99, 10, "Electronics", 101);

    article.sell(15);
    article.restock(-5);
    
    article.applyDiscount(150);

    if (article.isAvailable()) 
    {
        std::cout << "Article available" << std::endl;
    }
    
    article.printInfo();

    return 0;
}