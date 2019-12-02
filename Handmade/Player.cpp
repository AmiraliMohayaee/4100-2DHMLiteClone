#include "Player.h"

Player::Player(glm::vec2 pos)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Ryu.png", "P1STAND");
	m_anim.SetTexture("P1STAND");
	m_anim.SetAnimationVelocity(20.0f);
	m_anim.SetSpriteDimension(100, 250);
	m_anim.SetTextureDimension(8, 1, 127, 250);
	m_anim.IsAnimationLooping() = true;	// blow up forever

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Ryu.png", "P1LP");
	m_lightP.SetTexture("P1LP");


	m_pos = pos;
}

void Player::Draw()
{
	m_anim.Draw(int(m_pos.x), int(m_pos.y));
}

void Player::Update()
{
	m_anim.Draw(int(m_pos.x), int(m_pos.y), 0.0, Sprite::HORIZONTAL);

	//if (m_keys[SDL_SCANCODE_D])
	//{
	//	posX += 20.0f;
	//	std::cout << "moving right\n";
	//	//m_player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
	//}
	//else if (m_keys[SDL_SCANCODE_A])
	//{
	//	posX -= 20.0f;
	//	std::cout << "moving left\n";
	//	//m_player.Draw(int(posX), 400, 0.0, Sprite::NO_FLIP);
	//}
	//else
	//{
	//	//m_player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
	//}
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
