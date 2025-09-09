#pragma once
#include "Base/Base.h"

class Block : public Base
{
private:
	CImage m_img[7];
	int m_block_data[4][4];
	int m_type;
	float m_ang;
	int m_rotcnt;
public:
	Block(const CVector2D& pos, int type,int dataindex);
	void Update()override;
	void Draw()override;
	void Collision(Base* b)override;
};