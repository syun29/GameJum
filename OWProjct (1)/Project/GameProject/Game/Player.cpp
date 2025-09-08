#include "Player.h"

static TexAnim _anim_idle[]{
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
	{5,4}
};
static TexAnim _anim_attack[]{
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
	{5,4},
	{6,4},
	{7,4},
	{8,4},
	{9,4},
	{10,4},
	{11,4},
	{12,4},
	{13,4},
	{14,4}
};
TexAnimData _anim_data[]{
	ANIMDATA(_anim_idle),
};
Player::Player(const CVector2D& pos)
{
}

void Player::Draw()
{
}

void Player::Update()
{
}

void Player::Collision(Base* b)
{
}
