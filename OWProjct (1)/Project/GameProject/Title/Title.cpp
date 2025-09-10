#include "Title.h"
#include "Game/Game.h"
Title::Title()
	:Base(eType_Title)
	,m_sizecnt(0,0)
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
	m_font.SetSize(450+m_sizecnt.x, 50+m_sizecnt.y);
	m_font.SetPos(250, 483);
	m_start.SetPos(750, 700);
	m_img.Draw();
	m_font.Draw();
	m_start.Draw();
}
