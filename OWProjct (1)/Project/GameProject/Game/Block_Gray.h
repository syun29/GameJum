#pragma once
#include "Base/Base.h"

class Block_Gray :public Base {
private:
	CImage m_img;
	int m_cnt;
	int m_block[9] = { 0,0,0,0,0,0,0,0,0 };
	int b;
public:
	Block_Gray(const CVector2D& pos);
	void Update();
	void Draw();
};