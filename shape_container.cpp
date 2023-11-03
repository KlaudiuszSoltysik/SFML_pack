#ifndef SHAPE_CONTAINER_HPP
#define SHAPE_CONTAINER_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "abstract_rectangle_shape.cpp"


class ShapeContainer : public sf::RectangleShape {
    private:
        sf::RectangleShape m_box;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        sf::RenderWindow& m_window;
        std::vector<AbstractRectangleShape*> m_container;
        int m_spacing = 4;
    public:
        ShapeContainer(sf::RenderWindow& window) : m_window(window) {}

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
            int max_height = m_container[0]->getSize().y;

            for (AbstractRectangleShape* element : m_container) {
                int height = element->getSize().y;

                if (height > max_height) {
                    max_height = height;
                }
            }

            int baseline = max_height / 2 + m_position.y; 

            for (AbstractRectangleShape* element : m_container) {
                sf::Vector2f size = element->getSize();

                element->setPosition(sf::Vector2f(m_position.x + x_offset, baseline - size.y / 2));

                x_offset += size.x + m_spacing;

                window.draw(*element, states);
            }
        }
};

#endif