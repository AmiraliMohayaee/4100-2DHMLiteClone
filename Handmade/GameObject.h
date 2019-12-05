#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm.hpp>
#include "AABB.h"


class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0 {};

	virtual void Draw() = 0;
	virtual void Update() = 0;


public:
	bool IsAlive();
	bool IsAvtive();
	bool IsVisible();

	void IsAlive(bool flag);
	void IsAvtive(bool flag);
	void IsVisible(bool flag);

	bool IsColliding(AABB& otherObject);
	AABB GetCollision();

protected:
	glm::vec2 m_pos;
	glm::vec2 m_scale;
	double m_angle;
	
	bool m_isVisible;
	bool m_isActive;
	bool m_isAlive;

	AABB m_bounds;
};

#endif 