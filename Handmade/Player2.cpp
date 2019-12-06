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

	m_bounds.SetDimension(226, 342);
	m_bounds.SetPosition(int(m_pos.x), int(m_pos.y));

	m_keys = TheInput::Instance()->GetKeyStates();

	m_pos = pos;
	
	//&m_player1;
}

void Player2::Draw()
{
	//m_anim.Draw();
}

void Player2::Update()
{

		if (m_keys[SDL_SCANCODE_L])
		{
			m_pos.x += 10.0f;
			std::cout << "p2 moving right\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	
		if (m_keys[SDL_SCANCODE_J])
		{
			m_pos.x -= 10.0f;
			std::cout << "p2 moving left\n";
			m_walk.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
		}

	
		if (m_keys[SDL_SCANCODE_H])
		{
			std::cout << "P2 lightpunch\n";
			m_lightP.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
			//m_player1->IsColliding(m_player2->GetCollision());
		}
		
	
		if (!TheInput::Instance()->IsKeyPressed())
		{
			m_anim.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);
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

bool Player2::IsColliding(GameObject& go)
{
	if (go.IsColliding(m_bounds))
	{
		std::cout << "Player 2 Colliding with p1" << std::endl;
		return true;
	}
	else
		return false;
}
