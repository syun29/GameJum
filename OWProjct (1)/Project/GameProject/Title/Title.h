#pragma once
#include "Base/Base.h"

class Title : public Base
{
private:
	CImage m_img;
	CImage m_font;
	CImage m_start;

	//CVector2D m_sizecnt;
	float m_alpha;
	int m_fontstate;
	int m_cnt;

	float m_move;
	float m_speed;
	float m_movescale;
	int m_width;			//‰æ‘œ‚Ì‰¡•
	int m_height;			//‰æ‘œ‚Ìc•

public:
	Title();
	void Update()override;
	void Draw()override;
};

class TitleUI : public Base
{
	CImage m_block[7];
	int m_type;
	int m_ang;
public:
	TitleUI(const CVector2D& pos,int type,int ang);
	void Update()override;
	void Draw()override;
};