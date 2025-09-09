#pragma once
#include "../Base/Base.h"

class Player :public Base {
public:
	CImage m_img;
public:
	Player(const CVector2D& pos);
	void Draw();
	void Update();
	void Collision(Base* b);

	
};
extern TexAnimData _anim_data[];