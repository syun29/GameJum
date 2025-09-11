#include "Title.h"
#include "Game/Game.h"
Title::Title()
	:Base(eType_Title)
	,m_sizecnt(0,0)
	,m_alpha(0)
	,m_fontstate(0)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_font = COPY_RESOURCE("Title_Font", CImage);
	m_start = COPY_RESOURCE("Start", CImage);
}

void Title::Update()
{
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
