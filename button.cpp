#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

#include "abstract_rectangle_shape.cpp"


class Button : public AbstractRectangleShape {
    private:
        sf::RectangleShape m_rectangle;
        sf::Text m_text;
        std::function<void()> m_on_click;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        sf::RenderWindow& m_window;
    public:
        Button(sf::RectangleShape rectangle, sf::Text text, std::function<void()> on_click, sf::RenderWindow& window) : m_rectangle(rectangle), m_text(text), m_on_click(on_click), m_window(window) {}

        virtual void setSize(sf::Vector2f size) {
            m_size = size;

            m_rectangle.setSize(m_size);
            m_text.setCharacterSize(m_size.y * 0.8);
            
            m_text.setPosition(sf::Vector2f(m_position.x + ((m_size.x - m_text.getGlobalBounds().width) / 2), m_position.y));
        }

        virtual void setPosition(sf::Vector2f position) {
            m_position = position;

            m_rectangle.setPosition(m_position);
            m_text.setPosition(sf::Vector2f(m_position.x + ((m_size.x - m_text.getGlobalBounds().width) / 2), m_position.y));
        }

        void setRectangle(sf::RectangleShape rectangle) {
            m_rectangle = rectangle;
        }

        void setText(sf::Text text) {
            m_text = text;
        }

        void setOnClick(std::function<void()> on_click) {
            m_on_click = on_click;
        }

        sf::RectangleShape& getRectangle() {
            return m_rectangle;
        }

        sf::Text& getText() {
            return m_text;
        }

        virtual sf::Vector2f getSize() {
            return m_size;
        }

        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const {
            window.draw(m_rectangle, states);
            window.draw(m_text, states);
        }

        void checkOnClick() {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(m_window);

            if (mouse_position.x >= m_position.x && mouse_position.x <= m_position.x + m_size.x && mouse_position.y >= m_position.y && mouse_position.y <= m_position.y + m_size.y) {
                m_on_click();
            }
        }
};

#endif