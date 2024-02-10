#ifndef LABEL_DRAWER_HPP
#define LABEL_DRAWER_HPP

#include "SFML/Graphics.hpp"
class Drawer
{
public:
    Drawer();
    void draw(sf::RenderWindow& window);
private:
    int last = 0;
    sf::Clock Clock;
    sf::Font MainFont;
    sf::Font ClockFont;
};

#endif //LABEL_DRAWER_HPP
