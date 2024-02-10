#include <iostream>
#include "SFML/Graphics.hpp"
#include "drawer.hpp"

int main()
{
    sf::RenderWindow window;
    
    const char* window_id = std::getenv("XSCREENSAVER_WINDOW"); 
    
    if (window_id)
    {
        int handle = atoi(window_id);
        window.create(handle);
    }
    else
    {
        window.create(sf::VideoMode(1280, 720), "yep");
    }
    window.setFramerateLimit(15);
    
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/TTF/Roboto-Regular.ttf");
    
    auto drawer = new Drawer();
    
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }
        
        drawer->draw(window);
    }
}
