#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Platform.hpp"
using namespace std;

Platform::Platform()
{
	m_xVel = 0.0f;
	m_yVel = 0.0f;
}
void Platform::init(const string& textureFile, float i_x, float i_y, float i_w, float i_h)
{

	m_scale[0] = 1;
	m_scale[1] = 1;

	m_texture.loadFromFile(textureFile);
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(i_w * i_h * 4);

	m_vertices[0].position = sf::Vector2f(i_x, i_y);
	m_vertices[1].position = sf::Vector2f(i_x + i_w, i_y);
	m_vertices[2].position = sf::Vector2f(i_x + i_w, i_y + i_h);
	m_vertices[3].position = sf::Vector2f(i_x, i_y + i_h);

	m_vertices[0].texCoords = sf::Vector2f(0, 0);
	m_vertices[1].texCoords = sf::Vector2f(i_w, 0);
	m_vertices[2].texCoords = sf::Vector2f(i_w, i_h);
	m_vertices[3].texCoords = sf::Vector2f(0, i_h);

	m_abSize[0] = m_vertices[1].position.x - m_vertices[0].position.x;
	m_abSize[1] = m_vertices[3].position.y - m_vertices[1].position.y;
	m_halfSize[0] = m_abSize[0] / 2;
	m_halfSize[1] = m_abSize[1] / 2;
}