#include "drawer.hpp"
#include "SFML/Graphics.hpp"
#include "chrono"
#include "algorithm"

sf::Text clock(sf::Font& font, const sf::Vector2f& viewSize)
{
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm local = *std::localtime(&time);
    
    char time_text[9];
    std::strftime(time_text, sizeof(time_text), "%H:%M:%S", &local);
    auto content = std::string(time_text);
    
    sf::Text text;
    text.setFont(font);
    
    text.setString(content);
    text.setCharacterSize(std::min(viewSize.x, viewSize.y) / 12);
    text.setFillColor(sf::Color::White);
    
    auto bounds = text.getLocalBounds();
    
    text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    text.setPosition(viewSize.x / 2, viewSize.y / 2);
    
    return text;
}

Drawer::Drawer()
{
    this->MainFont = sf::Font();
    this->MainFont.loadFromFile("/usr/share/fonts/TTF/Roboto-Regular.ttf");
    this->ClockFont = sf::Font();
    this->ClockFont.loadFromFile("/usr/share/fonts/TTF/RobotoMono-Regular.ttf");
    
    this->Clock = sf::Clock();
    this->last = 0;
}

void Drawer::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    
    // DRAW!
    
    window.clear(sf::Color(0, 137, 156));
    window.draw(clock(this->ClockFont, window.getView().getSize()));
    
    window.display();
}
