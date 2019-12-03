#include "Player2.h"
#include "InputManager.h"
#include <iostream>


Player2::Player2(glm::vec2 pos)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/SagatStand.png", "P2STAND");
	m_anim.SetTexture("P2STAND");
	m_anim.SetAnimationVelocity(20.0f);
	m_anim.SetSpriteDimension(176, 342);
	m_anim.SetTextureDimension(5, 1, 88, 125);
	m_anim.IsAnimationLooping() = true;

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/SagatPunch.png", "P2LP");
	m_lightP.SetTexture("P2LP");
	m_lightP.SetAnimationVelocity(20.0f);
	m_lightP.SetSpriteDimension(226, 342);
	m_lightP.SetTextureDimension(4, 1, 453, 133);

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/SagatWalk.png", "P2WALK");
	m_walk.SetTexture("P2WALK");
	m_walk.SetAnimationVelocity(20.0f);
	m_walk.SetSpriteDimension(176, 342);
	m_walk.SetTextureDimension(6, 1, 88, 131);

	m_aabb.SetDimension(226, 342);
	m_aabb.SetPosition(int(m_pos.x), int(m_pos.y));

	m_keys = TheInput::Instance()->GetKeyStates();

	m_pos = pos;
}

void Player2::Draw()
{

}

void Player2::Update()
{
	switch (1)
	{
	case 1:
		if (m_keys[SDL_SCANCODE_L])
		{
			m_pos.x += 10.0f;
			std::cout << "p1 moving right\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	case 2:
		if (m_keys[SDL_SCANCODE_J])
		{
			m_pos.x -= 10.0f;
			std::cout << "p1 moving left\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	case 3:
		if (m_keys[SDL_SCANCODE_H])
		{
			std::cout << "P1 lightpunch";
			m_lightP.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	case 4:
		if (!TheInput::Instance()->IsKeyPressed())
		{
			m_anim.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	default:
		break;
	}
}

bool Player2::IsAlive()
{
	return false;
}

bool Player2::IsAvtive()
{
	return false;
}

bool Player2::IsVisible()
{
	return false;
}

void Player2::IsAlive(bool flag)
{

}

void Player2::IsAvtive(bool flag)
{

}

void Player2::IsVisible(bool flag)
{

}
