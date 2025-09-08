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
static TexAnim _anim_deth[]{
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
	{5,4},
	{6,4},
	{7,4}
};
static TexAnim _anim_hurt[]{
	{0,4},
	{1,4},
	{2,4},
	{3,4}
};
TexAnimData _anim_data[]{
	ANIMDATA(_anim_idle),ANIMDATA(_anim_attack),ANIMDATA(_anim_deth),ANIMDATA(_anim_hurt),
};
Player::Player(const CVector2D& pos)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos = pos;
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Player::Update()
{
	m_img.UpdateAnimation();
}

void Player::Collision(Base* b)
{
}
