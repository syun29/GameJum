#include "Block_Gray.h"

Block_Gray::Block_Gray(const CVector2D& pos):Base(eType_Block)
{
	m_img = COPY_RESOURCE("block_gray", CImage);
	m_pos = pos;
	m_cnt = 0;
	b = 0;
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
}

void Block_Gray::Draw()
{
	for (int i = 0;i < 9;i++) {
		if (m_block[i] == 1) {
			m_img.SetSize(60, 60);
			m_img.SetPos(m_pos.x, m_pos.y + 60 * i);
			m_img.Draw();
		}
	}
}
