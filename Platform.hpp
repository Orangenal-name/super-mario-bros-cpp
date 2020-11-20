#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

using namespace std;

class Platform : public Entity
{
private:
	float m_xVel;
	float m_yVel;
public:
	Platform();
	void init(const string& textureFile, float i_x, float i_y, float i_w, float i_h);
	unsigned int m_abSize[2];
	float m_halfSize[2];
	float m_centrePos[2];
	float m_scale[2];
	bool m_collide;
};