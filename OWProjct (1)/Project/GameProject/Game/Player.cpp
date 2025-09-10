#include "Player.h"
#include "Block.h"
#include "Field.h"

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
Player::Player(const CVector2D& pos, bool flip)
	:Base(eType_Player)
	,m_add(true)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	m_flip = flip;

	m_img.SetSize(128* 2,128* 2);
	m_img.SetCenter(64* 2, 64* 2);

	m_rect = CRect(-64* 2, -64* 2, 64* 2, 64* 2);
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	m_img.SetFlipH(m_flip);
}

void Player::Update()
{
	m_img.UpdateAnimation();
	const int move_speed = 4;
	
	// ↓ 画面外に出ないようにした
	if (m_pos.x >= 0) {
		//左右操作
		if (HOLD(CInput::eRight)) {
			m_pos.x += move_speed;
		}
		if (HOLD(CInput::eLeft)) {
			m_pos.x -= move_speed;
		}
	}else {
		m_pos.x += 0.1;
	}
	// ↓ 画面外に出ないようにした
	if (m_pos.y >= 200) {
		//上下操作
		 if (PUSH(CInput::eUp)) {
			m_pos.y -= 60;
		 }
		if (PUSH(CInput::eDown)) {
			m_pos.y += 60;
		}
	}else {
		 m_pos.y += 60;
	}
	if (m_pos.y > 740) {
		m_pos.y -= 60;
	}
	
	
	if (m_add)
	{
		int type = rand() % 6;
		Base::Add(new Block(CVector2D(m_pos), type));
		m_add = false;
	}

}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Block:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			SetKill();
		}
		break;
	}
}
