#include "Player.h"
#include "Block.h"
#include "Block_Gray.h"
#include "Field.h"
#include "Title/Result.h"

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
	,m_number(-1)
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
	//DrawRect();
	m_img.SetFlipH(m_flip);

	FONT_T()->Draw(10, 100, 1, 1, 1, "  Z   : 発射");
	FONT_T()->Draw(10, 150, 1, 1, 1, "  X :   消去");
	FONT_T()->Draw(10, 200, 1, 1, 1, "SPACE : 回転");
}

void Player::Update()
{
	m_img.UpdateAnimation();
	const int move_speed = 4;
	
	// ↓ 画面外に出ないようにした
	if (m_pos.x >= 0) {
		//左右操作
		if (PUSH(CInput::eRight)) {
			m_pos.x += 60;
		}
		if (PUSH(CInput::eLeft)) {
			m_pos.x -= 60;
		}
	}else {
		m_pos.x += 60;
	}
	// ↓ 画面外に出ないようにした
	if (m_pos.y >= 140) {
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
	if (m_pos.y > 620) {
		m_pos.y -= 60;
	}
	
	
	if (m_add)
	{
		if (PUSH(CInput::eButton6)) {
			Base::Add(new Block(CVector2D(m_pos), 0));
			m_add = false;
		}
		if (PUSH(CInput::eButton7)) {
			Base::Add(new Block(CVector2D(m_pos), 1));
			m_add = false;
		}
		if (PUSH(CInput::eButton8)) {
			Base::Add(new Block(CVector2D(m_pos), 2));
			m_add = false;
		}
		if (PUSH(CInput::eButton9)) {
			Base::Add(new Block(CVector2D(m_pos), 3));
			m_add = false;
		}
		if (PUSH(CInput::eButton10)) {
			Base::Add(new Block(CVector2D(m_pos), 4));
			m_add = false;
		}
		if (PUSH(CInput::eButton11)) {
			Base::Add(new Block(CVector2D(m_pos), 5));
			m_add = false;
		}
		if (PUSH(CInput::eButton12)) {
			Base::Add(new Block(CVector2D(m_pos), 6));
			m_add = false;
		}
		//if (Block* b = dynamic_cast<Block*>(Base::FindObject(eType_Block)))
		//{
		//	//if (b != nullptr) {
		//		if (PUSH(CInput::eButton2)) {
		//			b->SetKill();
		//		}
		//	//}
		//}
		/*int type = rand() % 6;
		Base::Add(new Block(CVector2D(m_pos), type));*/
		//m_add = false;
	}

}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Block_Gray:
		if (Base::CollisionCircle(this, b)) 
		{
			SetKill();
			//Base::Add(new Result());
		}
		break;
	}
	if (Block_Gray* b = dynamic_cast<Block_Gray*>(Base::FindObject(eType_Block_Gray))) {
		int t=b->GetTip(CVector2D(m_pos.x,m_pos.y-200));
		if (t != 0) {
			m_pos.x -= 60;
		}
	}
}
