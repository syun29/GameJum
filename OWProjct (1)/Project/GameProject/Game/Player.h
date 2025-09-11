#pragma once
#include "../Base/Base.h"

class Player :public Base {
public:
	CImage m_img;
	bool m_flip;
	int m_number;
public:
	bool m_add;
	Player(const CVector2D& pos, bool flip);
	void Draw();
	void Update();
	void Collision(Base* b);

	
};
extern TexAnimData _anim_data[];