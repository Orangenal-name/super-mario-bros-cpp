#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

using namespace std;

class Player : public Entity
{
	private:
		float m_xVel;
		float m_yVel;
	public:
		Player(const string& textureFile, float i_x, float i_y, float i_w, float i_h);
		void update(bool keyU, bool keyD, bool keyL, bool keyR, float deltaTime);
		unsigned int m_abSize[2];
		float m_halfSize[2];
		float m_centrePos[2];
		float m_scale[2];
		bool m_collide;
		bool m_onGround;
};