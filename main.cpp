#include "button.cpp"
#include "progress_bar.cpp"
#include "flex_box.cpp"

#include <SFML/Graphics.hpp>

#include <iostream>


/*
g++ *.cpp -o executeable -lsfml-graphics -lsfml-window -lsfml-system
./executeable
*/

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 540), "Test");
    window.setFramerateLimit(60);

    //FlexBox box(window);
    sf::RectangleShape r1;
    r1.setFillColor(sf::Color::Magenta);

    sf::Font font;
    font.loadFromFile("caveat.ttf");

    sf::Text t1("-", font);

    Button b1(r1, t1, [](){std::cout << "-" << std::endl;}, window);
    b1.setSize(sf::Vector2f(200, 100));

    ProgressBar bar(0.5, window);
    bar.setSize(sf::Vector2f(100, 50));

    FlexBox box(window);
    box.pushBack(&b1);
    box.pushBack(&bar);
    box.pushBack(&b1);
    box.pushBack(&bar);
    box.setPosition(sf::Vector2f(100, 100));

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
        window.draw(box);
        window.display();
    }

    return 0;
}