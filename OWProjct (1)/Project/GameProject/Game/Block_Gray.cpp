#include "Block_Gray.h"

Block_Gray::Block_Gray(const CVector2D& pos):Base(eType_Block_Gray)
{
	m_img = COPY_RESOURCE("block_gray", CImage);
	m_pos = pos;
	m_cnt = 0;
	b = 0;
	k = 0;
	m_kill_cnt = 0;
}

void Block_Gray::Update()
{
	for (b;b < 9;b++) {
		m_block[b] = rand() % 2;
	}
	if (m_cnt++ >= 120) {
		m_pos.x -= 60;
		m_cnt = 0;
	}
	if (m_block[k] == 1) {
		m_kill_cnt++;
		k++;
	}
	else {
		m_kill_cnt = 0;
		k = 0;
	}
	if (m_kill_cnt == 9) {
		SetKill();
	}
}

void Block_Gray::Draw()
{
	for (int i = 0;i < 9;i++) {
		if (m_block[i] == 1) {
			m_img.SetSize(60, 60);
			m_img.SetPos(m_pos.x, m_pos.y + 60 * i);
			m_gray_rect[i] = CRect(0, 60 * i, 60, 60 + 60 * i);
			//Block_Gray::DrawRect(i);
			m_img.Draw();
		}
	}
}

void Block_Gray::DrawRect(int num){
	CRect rect = CRect(
		m_pos.x + m_gray_rect[num].m_left,
		m_pos.y + m_gray_rect[num].m_top,
		m_pos.x + m_gray_rect[num].m_right,
		m_pos.y + m_gray_rect[num].m_bottom);
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
}
