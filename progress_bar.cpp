#include <SFML/Graphics.hpp>

#include <algorithm>
#include <iostream>


class ProgressBar : public sf::Drawable {
    private:
        sf::RectangleShape m_full;
        sf::RectangleShape m_empty;
        sf::RenderWindow& m_window;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        double m_progress;
        int m_thickness;
    public:
        ProgressBar(double progress, sf::RenderWindow& window) : m_progress(progress), m_window(window) {
            m_full.setFillColor(sf::Color::Magenta);
            m_empty.setOutlineColor(sf::Color::Magenta);
        }
        
        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const {
            window.draw(m_full, states);
            window.draw(m_empty, states);
        }

        void setProgress(double progress) {
            if (progress > 1.0 - 1e-10) {
                progress = 1.0;
            }

            m_progress = std::max(0.0, std::min(1.0, progress));

            setSize(m_size);
            setPosition(m_position);
        }

        void setSize(sf::Vector2f size) {
            m_size = size;
            m_thickness = m_size.y * 0.05;

            m_empty.setOutlineThickness(m_thickness);

            m_full.setSize(sf::Vector2f(m_size.x * m_progress, m_size.y));

            if (m_progress < 1.0) {
                m_empty.setSize(sf::Vector2f(m_size.x * (1 - m_progress) - m_thickness * 2, m_size.y - m_thickness * 2));
            } else {
                m_empty.setSize(sf::Vector2f(0, 0));
                m_empty.setOutlineThickness(0);
            }
            

            setPosition(m_position);
        }

        void setPosition(sf::Vector2f position) {
            m_position = position;

            m_full.setPosition(m_position);
            m_empty.setPosition(sf::Vector2f(m_position.x + m_full.getSize().x + m_thickness, position.y + m_thickness));
        }

        double& getProgress() {
            return m_progress;
        }
};


// ProgressBar::ProgressBar(double progress, sf::Vector2f size, sf::Vector2f position, sf::Color color) : progress(progress) {
//     full_size = sf::Vector2f(size.x * progress, size.y);
//     empty_size = sf::Vector2f(size.x * (1 - progress), size.y);
    
//     full = sf::RectangleShape(full_size);
//     empty = sf::RectangleShape(empty_size);

//     full.setPosition(position);
//     empty.setPosition(sf::Vector2f(position.x + full_size.x, position.y));

//     full.setFillColor(color);
//     empty.setFillColor(sf::Color::White);
// }

// ProgressBar::~ProgressBar() {
// }

// void ProgressBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//     window.draw(full, states);
//     window.draw(empty, states);
// }

// void ProgressBar::setSize(sf::Vector2f size) {
//     full_size = sf::Vector2f(size.x * progress, size.y);
//     empty_size = sf::Vector2f(size.x * (1 - progress), size.y);
    
//     full.setSize(full_size);
//     empty.setSize(empty_size);
// }

// void ProgressBar::setPosition(sf::Vector2f position) {
//     full.setPosition(position);
//     empty.setPosition(sf::Vector2f(position.x + full_size.x, position.y));
// }