#include "Block.h"

Block::Block(const CVector2D& pos)
	: Base(eType_Block)
{
	m_img = COPY_RESOURCE("Block_blue", CImage);
	m_pos = pos;
}

void Block::Update()
{
}

void Block::Draw()
{
	m_img.Draw();
}

void Block::Collision(Base* b)
{
}
