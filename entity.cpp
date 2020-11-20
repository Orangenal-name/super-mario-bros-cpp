#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace std;

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = m_transform;

	states.texture = &m_texture;

	target.draw(m_vertices, states);
}