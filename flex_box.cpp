#ifndef FLEX_BOX_HPP
#define FLEX_BOX_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "abstract_rectangle_shape.cpp"


class FlexBox : public sf::RectangleShape {
    private:
        sf::RectangleShape m_box;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        sf::RenderWindow& m_window;
        std::vector<AbstractRectangleShape*> m_container;
        int m_spacing = 4;
    public:
        FlexBox(sf::RenderWindow& window) : m_window(window) {}

        void setSpacing(int spacing) {
            m_spacing = spacing;
        }

        void setSize(sf::Vector2f size) {
            m_size = size;
        }

        void setPosition(sf::Vector2f position) {
            m_position = position;
        }

        void pushBack(AbstractRectangleShape* element) {
            m_container.push_back(element);
        }

        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const {
            int x_offset = 0;

            for (AbstractRectangleShape* element : m_container) {
                element->setPosition(sf::Vector2f(m_position.x + x_offset, m_position.y));

                x_offset += element->getSize().x + m_spacing;

                window.draw(*element, states);
            }
        }
};

#endif