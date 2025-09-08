#include "Block.h"

Block::Block():Base(eType_Block){
	m_img = COPY_RESOURCE("block_gray", CImage);
	m_pos = CVector2D(1800, 200);
	cnt = 0;
}

void Block::Update(){
	cnt++;
	//2•b‚²‚Æ‚É¶‚ÖˆÚ“®
	if (cnt >= 120) {
		m_pos.x += -32;
		cnt = 0;
	}
}

void Block::Draw(){
	for (int i = 0;i < 9;i++) {
		m_img.SetSize(32, 32);
		m_img.SetPos(m_pos.x, m_pos.y + 32 * i);
		m_img.Draw();
	}
}
