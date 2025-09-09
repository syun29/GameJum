#include "Block.h"

#define MOVE_SPEED 0.02f

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
	,m_ang(DtoR(0.0f))
	,m_rotcnt(0)
{
	m_img[0] = COPY_RESOURCE("Block_blue", CImage);
	m_img[1] = COPY_RESOURCE("Block_yellow", CImage);
	m_img[2] = COPY_RESOURCE("Block_red", CImage);
	m_img[3] = COPY_RESOURCE("Block_cyan", CImage);
	m_img[4] = COPY_RESOURCE("Block_orange", CImage);
	m_img[5] = COPY_RESOURCE("Block_pink", CImage);
	m_img[6] = COPY_RESOURCE("Block_purple", CImage);
	memcpy(m_block_data, block_data[dataindex], sizeof(int) * 4 * 4);
	m_vec = (CVector2D(0, 0));
	m_pos = pos;
	m_rect = CRect(-30, -60, 30, 0);
	m_type = type;
	
}

void Block::Update()
{
	if (PUSH(CInput::eButton5))
	{
		if (m_rotcnt <= 3) {
			m_rotcnt += 1;
		}
		else {
			m_rotcnt = 0;
		}
		//m_ang += DtoR(15.0f);
	}

	if (m_rotcnt == 0)
	{
		m_block_data[0][1] = 1;
		m_block_data[1][1] = 1;
		m_block_data[2][1] = 1;
		m_block_data[2][2] = 1;
	}
	if (m_rotcnt == 1)
	{
		m_block_data[0][1] = 1;
		m_block_data[1][1] = 1;
		m_block_data[2][1] = 1;
		m_block_data[2][2] = 1;
	}
	m_vec.x += MOVE_SPEED;
	
	m_pos.x += m_vec.x;
}

void Block::Draw()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_block_data[i][j] == 0)continue;
			m_img[m_type].SetSize(60, 60);
			m_img[m_type].SetCenter(30,60);
			m_img[m_type].SetAng(m_ang);
			m_img[m_type].SetPos(m_pos + CVector2D(j * 60, i * 60));
			m_img[m_type].Draw();
			//DrawRect();
		}
	}
}




























void Block::Collision(Base* b)
{
	switch (b->m_type)
	{
	case eType_Block:
		CVector2D m_gray_pos = b->m_pos;
		int col = m_gray_pos.x / 60;
		if (col < 0)col = 0;
		if (col > 1920 - 1)col = 1920 - 1;
		int row = m_gray_pos.y / 60;
		if (row < 0)row = 0;
		if (row > 1080 - 1)row = 1080 - 1;
		if (row != 0 && col != 0) {
			m_vec.x = 0;
		}
		break;
	}
	
	






















}

