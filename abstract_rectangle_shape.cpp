#ifndef ABSTRACT_RECTANGLE_SHAPE_HPP
#define ABSTRACT_RECTANGLE_SHAPE_HPP

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <iostream>


class AbstractRectangleShape : public sf::RectangleShape {
    public:
        AbstractRectangleShape() {}
        ~AbstractRectangleShape() {}
        virtual void setSize(sf::Vector2f size) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual sf::Vector2f getSize() = 0;
};

#endif