#include "Block.h"

Block::Block(const CVector2D& pos,int type)
	: Base(eType_Block)
{
	m_img[0] = COPY_RESOURCE("Block_blue", CImage);
	m_img[1] = COPY_RESOURCE("Block_yellow", CImage);
	m_img[2] = COPY_RESOURCE("Block_red", CImage);
	m_img[3] = COPY_RESOURCE("Block_cyan", CImage);
	m_img[4] = COPY_RESOURCE("Block_orange", CImage);
	m_img[5] = COPY_RESOURCE("Block_pink", CImage);
	m_img[6] = COPY_RESOURCE("Block_purple", CImage);

	m_pos = pos;
	m_type = type;
}

void Block::Update()
{
}

void Block::Draw()
{
	//for (int i = 0; i < 7; i++) {
		m_img[m_type].SetSize(120, 120);
		m_img[m_type].SetPos(m_pos);
		m_img[m_type].Draw();
	//}
}

void Block::Collision(Base* b)
{
}

