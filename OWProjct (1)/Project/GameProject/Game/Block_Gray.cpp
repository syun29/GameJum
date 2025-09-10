#include "Block_Gray.h"

static int stage_data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
};

Block_Gray::Block_Gray(const CVector2D& pos):Base(eType_Block_Gray)
{
	m_img = COPY_RESOURCE("block_gray", CImage);
	m_pos = pos;
	m_cnt = 0;
	b = 0;
	k = 0;
	m_kill_cnt = 0;
	memcpy(m_stage_data, stage_data, sizeof(stage_data));
}

void Block_Gray::Update()
{
	
	if (m_cnt++ >= 120) {
		Add_Block();
		m_cnt = 0;
	}
	
}

void Block_Gray::Draw()
{
	/*for (int i = 0;i < 9;i++) {
		if (m_block[i] == 1) {
			m_img.SetSize(60, 60);
			m_img.SetPos(m_pos.x, m_pos.y + 60 * i);
			m_img.Draw();
		}
	}*/
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 32;j++) {
			if (m_stage_data[i][j] == 0) continue;
			m_img.SetSize(60,60);
			m_img.SetPos(j * 60 , i * 60+m_pos.y);
			m_img.Draw();
		}
	}
}

void Block_Gray::Add_Block()
{
	for (int i = 0;i < 31;i++) {
		for (b=0;b < 9;b++) {

			m_stage_data[b][i] = m_stage_data[b][i+1];

		}
	}
	for (b=0;b < 9;b++) {

		m_stage_data[b][31] = rand() % 2;
	}
}

int Block_Gray::GetTip(const CVector2D& pos) {
	int col = pos.x / MAP_TIP_SIZE;
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
	int row = pos.y / MAP_TIP_SIZE;
	if (row < 0)row = 0;
	if (row > MAP_HEIGHT - 1)row = MAP_HEIGHT - 1;
	return GetTip(col, row);
}

int Block_Gray::GetTip(int col, int row) {
	return m_stage_data[row][col];
}

void Block_Gray::Check_Block()
{
	for (int i = 0;i < 31;i++) {
		bool kill = true;
		for (int j = 0;i < 9;j++) {
			if (m_stage_data[i][j] == 0) {
				kill = false;
			}
			if (kill) {
				m_stage_data[i][j] = 0;
			}
		}
	}
}

void Block_Gray::SetTip(int col, int row, int type)
{
	m_stage_data[row][col] = type;
}
