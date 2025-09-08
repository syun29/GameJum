#include "Block.h"
int block_data[7][4][4] = {
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},

	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},

	{
		0,1,0,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0,
	},

	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0
	},

	{
		0,0,0,0,
		0,0,1,1,
		0,1,1,0,
		0,0,0,0
	},

	{
		0,1,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,0,0
	},

	{
		0,0,1,0,
		0,0,1,0,
		0,1,1,0,
		0,0,0,0
	},

};
Block::Block(const CVector2D& pos,int type,int dataindex)
	: Base(eType_Block)
{
	m_img[0] = COPY_RESOURCE("Block_blue", CImage);
	m_img[1] = COPY_RESOURCE("Block_yellow", CImage);
	m_img[2] = COPY_RESOURCE("Block_red", CImage);
	m_img[3] = COPY_RESOURCE("Block_cyan", CImage);
	m_img[4] = COPY_RESOURCE("Block_orange", CImage);
	m_img[5] = COPY_RESOURCE("Block_pink", CImage);
	m_img[6] = COPY_RESOURCE("Block_purple", CImage);
	memcpy(m_block_data, block_data[dataindex], sizeof(int) * 4 * 4);

	m_pos = pos;
	m_type = type;
}

void Block::Update()
{
	
}

void Block::Draw()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_block_data[i][j] == 0)continue;
			m_img[m_type].SetSize(120, 120);
			m_img[m_type].SetPos(m_pos+CVector2D(j*120,i*120));
			m_img[m_type].Draw();
		}
	}
}

void Block::Collision(Base* b)
{
}

