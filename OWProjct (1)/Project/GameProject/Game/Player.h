#pragma once
#include "../Base/Base.h"

class Block;

class Player :public Base {
public:
	CImage m_img;
	bool m_flip;
	bool m_isNew;
	int m_number;
	int m_blockNo;
	Block* mp_block;
public:
	bool m_add;
	Player(const CVector2D& pos, bool flip);
	void Draw();
	void Update();
	void Collision(Base* b);

	
};
extern TexAnimData _anim_data[];