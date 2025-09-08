#pragma once
#include "Base/Base.h"

class Block : public Base
{
private:
	CImage m_img;

public:
	Block(const CVector2D& pos,int type);
	void Update()override;
	void Draw()override;
	void Collision(Base* b)override;
};