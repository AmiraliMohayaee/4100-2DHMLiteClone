#include "GameObject.h"

bool GameObject::IsAlive()
{
	return m_isAlive;
}

bool GameObject::IsAvtive()
{
	return m_isActive;
}

bool GameObject::IsVisible()
{
	return m_isVisible;
}

void GameObject::IsAlive(bool flag)
{
	m_isAlive = flag;
}

void GameObject::IsAvtive(bool flag)
{
	m_isActive = flag;
}

void GameObject::IsVisible(bool flag)
{
	m_isVisible = flag;
}

GameObject::GameObject()
{
	m_pos = glm::vec2(0.0f);
	m_scale = glm::vec2(1.0f);
	m_angle = 0.0;

	m_isVisible = true;
	m_isActive = true;
	m_isAlive = true;
}
