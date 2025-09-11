#include "Title.h"
#include "Game/Game.h"
Title::Title()
	:Base(eType_Title)
	,m_sizecnt(0,0)
	,m_alpha(0)
	,m_fontstate(0)
	,m_cnt(60*3)
{
	m_img = COPY_RESOURCE("Scene", CImage);
	m_font = COPY_RESOURCE("Title_Font", CImage);
	m_start = COPY_RESOURCE("Start", CImage);
}

void Title::Update()
{

	m_cnt--;
	if (m_cnt <= 0) {
		CVector2D pos(Utility::Rand(0.0f, 1900.f),
			Utility::Rand(0.0f, 0.0f));
		int type = rand() % 6;
		Base::Add(new TitleUI(pos, type));
		
		m_cnt = 60 * 3;
	}



	if (m_sizecnt.x< 1000)
	{
		m_sizecnt.x+=10;
	}
	if (m_sizecnt.y < 100)
	{
		m_sizecnt.y+=1;
	}
	if (PUSH(CInput::eButton5))
	{
		SetKill();
		Base::Add(new Game());
	}
}

void Title::Draw()
{
	switch (m_fontstate) {
	case 0:
		//if (PUSH(CInput::eButton1))
		m_fontstate++;
		break;
	case 1:
		//É∆â¡éZ
		m_alpha += 0.05f;
		if (m_alpha > DtoR(180)) {
			m_alpha = 0;
		}
		break;
	}
	//í èÌÇÃÉçÉSÇÃï`âÊ
	m_start.SetSize(450, 96);
	m_start.SetPos(750, 700);

	m_start.SetColor(1, 1, 1, 1);
	//m_start.Draw();

	//èdÇÀÇƒï`âÊ

	//sinÉJÅ[Éu
	m_start.SetColor(1, 1, 1, sin(m_alpha));
	m_start.Draw();

	m_font.SetSize(450+m_sizecnt.x, 50+m_sizecnt.y);
	m_font.SetPos(250, 483);
	m_start.SetPos(750, 700);
	m_img.Draw();
	m_font.Draw();
	m_start.Draw();
}

TitleUI::TitleUI(const CVector2D& pos,int type)
	: Base(eType_UI)
	,m_type(type)
{
	m_block[0] = COPY_RESOURCE("O_block", CImage);
	m_block[1] = COPY_RESOURCE("S_block", CImage);
	m_block[2] = COPY_RESOURCE("Z_block", CImage);
	m_block[3] = COPY_RESOURCE("J_block", CImage);
	m_block[4] = COPY_RESOURCE("L_block", CImage);
	m_block[5] = COPY_RESOURCE("T_block", CImage);
	m_block[6] = COPY_RESOURCE("I_block", CImage);

	m_pos = pos;
}

void TitleUI::Update()
{
	m_pos.y += 10.0f;
}

void TitleUI::Draw()
{
	m_block[m_type].SetPos(m_pos);
	m_block[m_type].Draw();
}
