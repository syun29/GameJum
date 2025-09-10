#include "Block.h"

#define MOVE_SPEED 0.2f

int block_data[7][4][4][4] = {
	//O��
	{
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	},
	//I��
	{
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},
	{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0
	},
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},
	{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0
	},
	},
	//T��
	{
	{
		0,1,0,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0,
	},
	{
		0,1,1,1,
		0,0,1,0,
		0,0,0,0,
		0,0,0,0,
	},
	{
		0,0,0,1,
		0,0,1,1,
		0,0,0,1,
		0,0,0,0,
	},
	{
		0,0,0,0,
		0,0,1,0,
		0,1,1,1,
		0,0,0,0,
	},
	},
	//Z��
	{
	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,1,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0

	},
	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,1,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0
	},
	},
	//S��
	{
	{
		0,0,0,0,
		0,0,1,1,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,1,0,0,
		0,1,1,0,
		0,0,1,0,
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
		0,1,1,0,
		0,0,1,0,
		0,0,0,0
	},
	},
	//L��
	{
	{
		0,1,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		1,1,1,0,
		1,0,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,1,0
	},
	{
		0,0,0,0,
		0,0,1,0,
		1,1,1,0,
		0,0,0,0
	},
	},
	//J��
	{
	{
		0,0,1,0,
		0,0,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,0,0,
		0,1,1,1,
		0,0,0,0
	},
	{
		0,1,1,0,
		0,1,0,0,
		0,1,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,1,
		0,1,0,0,
		0,0,0,0
	},
	}
};
Block::Block(const CVector2D& pos, int dataindex)
	: Base(eType_Block)
	, m_ang(DtoR(0.0f))
	, m_rotcnt(0)
	,m_type(dataindex)
{
	m_img[0] = COPY_RESOURCE("Block_blue", CImage);
	m_img[1] = COPY_RESOURCE("Block_yellow", CImage);
	m_img[2] = COPY_RESOURCE("Block_red", CImage);
	m_img[3] = COPY_RESOURCE("Block_cyan", CImage);
	m_img[4] = COPY_RESOURCE("Block_orange", CImage);
	m_img[5] = COPY_RESOURCE("Block_pink", CImage);
	m_img[6] = COPY_RESOURCE("Block_purple", CImage);
	memcpy(m_block_data, block_data[dataindex][0], sizeof(int) * 4 * 4);
	m_vec = (CVector2D(0, 0));
	m_pos = pos;
	m_rect = CRect(-30, -60, 30, 0);
	

}

void Block::Update()
{
	if (PUSH(CInput::eButton5))
	{
		if (m_rotcnt + 1 == 4)
		{
			m_rotcnt = -1;
		}
		if (m_rotcnt < 4) 
		{
			m_rotcnt += 1;
		}
		
		Rotation();
	}

	

	m_pos.x += MOVE_SPEED;
}

void Block::Draw()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_block_data[i][j] == 0)continue;
			m_img[m_type].SetSize(60, 60);
			m_img[m_type].SetCenter(30, 60);
			m_img[m_type].SetAng(m_ang);
			m_img[m_type].SetPos(m_pos + CVector2D(j * 60, i * 60));
			m_img[m_type].Draw();
			//DrawRect();
		}
	}
}

void Block::Rotation()
{
	memcpy(m_block_data, block_data[m_type][m_rotcnt], sizeof(int) * 4 * 4);

















}

void Block::Collision(Base* b)
{
	switch (b->m_type)
	{
	case eType_Block_Gray:
		CVector2D m_g_pos = b->m_pos;
		CRect m_g_rect;
		int i = 0;
		if (m_pos.y > 200 && m_pos.y <= 260) {
			i = 0;
			m_g_rect = b->m_gray_rect[0];
		}
		else if (m_pos.y > 260 && m_pos.y <= 320) {
			i = 1;
			m_g_rect = b->m_gray_rect[1];
		}
		else if (m_pos.y > 320 && m_pos.y <= 380) {
			i = 2;
			m_g_rect = b->m_gray_rect[2];
		}
		else if (m_pos.y > 380 && m_pos.y <= 440) {
			i = 3;
			m_g_rect = b->m_gray_rect[3];
		}
		else if (m_pos.y > 440 && m_pos.y <= 500) {
			i = 4;
			m_g_rect = b->m_gray_rect[4];
		}
		else if (m_pos.y > 500 && m_pos.y <= 560) {
			i = 5;
			m_g_rect = b->m_gray_rect[5];
		}
		else if (m_pos.y > 560 && m_pos.y <= 620) {
			i = 6;
			m_g_rect = b->m_gray_rect[6];
		}
		else if (m_pos.y > 620 && m_pos.y <= 680) {
			i = 7;
			m_g_rect = b->m_gray_rect[7];
		}
		else if (m_pos.y > 680 && m_pos.y <= 740) {
			i = 8;
			m_g_rect = b->m_gray_rect[8];
		}
		
		CRect rect1 = CRect(
			m_pos.x + m_rect.m_left,
			m_pos.y + m_rect.m_top,
			m_pos.x + m_rect.m_right,
			m_pos.y + m_rect.m_bottom);

		CRect rect2 = CRect(
			m_g_pos.x + m_g_rect.m_left,
			m_g_pos.y + m_g_rect.m_top,
			m_g_pos.x + m_g_rect.m_right,
			m_g_pos.y + m_g_rect.m_bottom);

		if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
			rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top) {
			m_pos.x -= MOVE_SPEED;
			if(m_block[i]==0) m_block[i] = 1;
		}
			
			
	}























	
}

