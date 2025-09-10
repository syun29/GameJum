#pragma once
#include "Base/Base.h"

#define MAP_WIDTH 32
#define MAP_HEIGHT 9

class Block_Gray :public Base {
private:
	CImage m_img;
	int m_cnt;
	int b;
	int k;
	int m_kill_cnt;
	int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Block_Gray(const CVector2D& pos);
	void Update();
	void Draw();
	void Add_Block();
};