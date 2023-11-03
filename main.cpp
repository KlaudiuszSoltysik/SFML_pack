#include "button.cpp"
#include "progress_bar.cpp"
#include "shape_container.cpp"

#include <SFML/Graphics.hpp>

#include <iostream>


/*
g++ *.cpp -o executeable -lsfml-graphics -lsfml-window -lsfml-system
./executeable
*/

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 540), "Test");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                } 
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}