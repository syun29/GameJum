#include "Block.h"

Block::Block(const CVector2D& pos,int type)
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
	m_img.SetSize(120, 120);
	m_img.Draw();
}

void Block::Collision(Base* b)
{
}

