#pragma once
#include "Base/Base.h"

class Player;

class Block : public Base
{
private:
	CImage m_img[7];
	int m_block_data[4][4];
	int m_type;
	int m_rotcnt;
	bool m_flag;
	Player* mp_player;
	
public:
	bool m_move;
	Block(const CVector2D& pos,int dataindex);
	void Update()override;
	void Draw()override;
	void Rotation();
	void Reset(int dataindex);
	void Collision(Base* b)override;
};