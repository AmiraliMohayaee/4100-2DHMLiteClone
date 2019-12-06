#include "Player.h"
#include <iostream>
#include "InputManager.h"



Player::Player(glm::vec2 pos)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/RyuStand.png", "P1STAND");
	m_anim.SetTexture("P1STAND");
	m_anim.SetAnimationVelocity(20.0f);
	m_anim.SetSpriteDimension(136, 342);
	m_anim.SetTextureDimension(5, 1, 68, 171);
	m_anim.IsAnimationLooping() = true;

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/RyuPunch.png", "P1LP");
	m_lightP.SetTexture("P1LP");
	m_lightP.SetAnimationVelocity(10.0f);
	m_lightP.SetSpriteDimension(136, 342);
	m_lightP.SetTextureDimension(4, 1, 113, 171);

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/RyuWalking.png", "P1WALK");
	m_walk.SetTexture("P1WALK");
	m_walk.SetAnimationVelocity(30.0f);
	m_walk.SetSpriteDimension(136, 342);
	m_walk.SetTextureDimension(12, 1, 72, 171);

	m_bounds.SetDimension(136, 342);
	m_bounds.SetPosition(int(m_pos.x), int(m_pos.y));

	m_keys = TheInput::Instance()->GetKeyStates();

	m_pos = pos;

	//&m_player2;
}

void Player::Draw()
{
	//m_anim.Draw(int(m_pos.x), int(m_pos.y));
}

void Player::Update()
{
	//m_player2->Update();

		if (m_keys[SDL_SCANCODE_D])
		{
			m_pos.x += 10.0f;
			std::cout << "p1 moving right\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::NO_FLIP);
		}

		if (m_keys[SDL_SCANCODE_A])
		{
			m_pos.x -= 10.0f;
			std::cout << "p1 moving left\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::NO_FLIP);
		}

		if (m_keys[SDL_SCANCODE_F])
		{
			std::cout << "P1 lightpunch\n";
			m_lightP.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::NO_FLIP);
		}

		
		if (!TheInput::Instance()->IsKeyPressed())
		{
			m_anim.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::NO_FLIP);
		}

}

bool Player::IsAlive()
{
	return m_isAlive;
}

bool Player::IsAvtive()
{
	return false;
}

bool Player::IsVisible()
{
	return false;
}

void Player::IsAlive(bool flag)
{

}

void Player::IsAvtive(bool flag)
{
}

void Player::IsVisible(bool flag)
{
}

bool Player::IsColliding(GameObject& go)
{
	if (go.IsColliding(m_bounds))
	{
		std::cout << "Player 1 Colliding with p2" << std::endl;
		return true;
	}
	else
		return false;
}
