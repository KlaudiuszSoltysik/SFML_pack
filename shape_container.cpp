#ifndef SHAPE_CONTAINER_HPP
#define SHAPE_CONTAINER_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "abstract_rectangle_shape.cpp"


class ShapeContainer : public AbstractRectangleShape {
    private:
        sf::RectangleShape m_box;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        sf::RenderWindow& m_window;
        std::vector<AbstractRectangleShape*> m_container;
        int m_spacing = 4;
        bool m_is_horizontal = true;
    public:
        ShapeContainer(sf::RenderWindow& window) : m_window(window) {}

        void setSpacing(int spacing) {
            m_spacing = spacing;
        }

        void setPosition(sf::Vector2f position) {
            m_position = position;
        }

        void setHorizontal(bool set) {
            m_is_horizontal = set;

            setSize();
        }

        void pushBack(AbstractRectangleShape* element) {
            m_container.push_back(element);

            setSize();
        }

        void setSize() {
            if (m_is_horizontal) {
                int container_width = 0;
                int max_height = m_container[0]->getSize().y;

                for (AbstractRectangleShape* element : m_container) {
                    sf::Vector2f size = element->getSize();

                    container_width += size.x;

                    if (size.y > max_height) {
                        max_height = size.y;
                    }
                }

                container_width += (m_container.size() - 1) * m_spacing;

                m_size.x = container_width;
                m_size.y = max_height;
            } else {
                int container_height = 0;
                int max_width = m_container[0]->getSize().x;

                for (AbstractRectangleShape* element : m_container) {
                    sf::Vector2f size = element->getSize();

                    container_height += size.y;

                    if (size.x > max_width) {
                        max_width = size.x;
                    }
                }

                container_height += (m_container.size() - 1) * m_spacing;

                m_size.x = max_width;
                m_size.y = container_height;
            }
            
        }

        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const {
            if (m_is_horizontal) {
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
            } else {
                int y_offset = 0;
                int max_width = m_container[0]->getSize().x;

                for (AbstractRectangleShape* element : m_container) {
                    int width = element->getSize().x;

                    if (width > max_width) {
                        max_width = width;
                    }
                }

                int baseline = max_width / 2 + m_position.x; 

                for (AbstractRectangleShape* element : m_container) {
                    sf::Vector2f size = element->getSize();

                    element->setPosition(sf::Vector2f(baseline - size.x / 2, m_position.y + y_offset));

                    y_offset += size.y + m_spacing;

                    window.draw(*element, states);
                }
            }
        }

        virtual void setSize(sf::Vector2f size) {}

        virtual sf::Vector2f getSize() {
            return m_size;
        }
};

#endif