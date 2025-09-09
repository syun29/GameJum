#include "Player.h"
#include "Block.h"

//アニメーション
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
static TexAnim _anim_death[]{
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
	ANIMDATA(_anim_idle),ANIMDATA(_anim_attack),ANIMDATA(_anim_death),ANIMDATA(_anim_hurt),
};
Player::Player(const CVector2D& pos)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos = pos;

	m_img.SetSize(128* 2,128* 2);
	m_img.SetCenter(64* 2, 64* 2);

	m_rect = CRect(-64* 2, -64* 2, 64* 2, 64* 2);
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Player::Update()
{
	m_img.UpdateAnimation();

	//操作
	const int move_speed = 4;
	if (HOLD(CInput::eUp)) {
		m_pos.y -= move_speed;
	}
	if (HOLD(CInput::eDown)) {
		m_pos.y += move_speed;
	}
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
	}
	if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
	}
	if (PUSH(CInput::eButton1)) {
		Base::Add(new Block(CVector2D(m_pos),4,3));
	}
}

void Player::Collision(Base* b)
{
}
