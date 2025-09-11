#pragma once
#include "Base/Base.h"

#define MAP_WIDTH 32
#define MAP_HEIGHT 9
#define MAP_TIP_SIZE 60

class Block_Gray :public Base {
private:
	CImage m_img;
	int m_cnt;
	int m_time_cnt;
	int t;
	int b;
	int m_kill_cnt;
	int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Block_Gray(const CVector2D& pos);
	void Update();
	void Draw();
	void Add_Block();
	int GetTip(const CVector2D& pos);
	int GetTip(int col, int row);
	void Check_Block();
	void SetTip(int col, int row, int type);
	void SetTip(const CVector2D& pos,int type);
};