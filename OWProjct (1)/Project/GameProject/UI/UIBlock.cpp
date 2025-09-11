#include "UIBlock.h"

UIBlock::UIBlock()
	:Base(eType_UI)
{
	m_img[0] = COPY_RESOURCE("O_block", CImage);
	m_img[1] = COPY_RESOURCE("I_block", CImage);
	m_img[2] = COPY_RESOURCE("T_block", CImage);
	m_img[3] = COPY_RESOURCE("Z_block", CImage);
	m_img[4] = COPY_RESOURCE("S_block", CImage);
	m_img[5] = COPY_RESOURCE("L_block", CImage);
	m_img[6] = COPY_RESOURCE("J_block", CImage);
	
	

	m_number[0] = COPY_RESOURCE("1", CImage);
	m_number[1] = COPY_RESOURCE("2", CImage);
	m_number[2] = COPY_RESOURCE("3", CImage);
	m_number[3] = COPY_RESOURCE("4", CImage);
	m_number[4] = COPY_RESOURCE("5", CImage);
	m_number[5] = COPY_RESOURCE("6", CImage);
	m_number[6] = COPY_RESOURCE("7", CImage);
}

void UIBlock::Update()
{
}

void UIBlock::Draw()
{
	for (int i = 0; i < 7; i++)
	{
		m_img[i].SetPos(75 +270 * i , 750);
		m_number[i].SetPos(100 + 270 * i, 1000);
		m_img[i].Draw();
		m_number[i].Draw();
	}
}
