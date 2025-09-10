#pragma once
#include "Base/Base.h"

class Title : public Base
{
private:
	CImage m_img;
	CImage m_font;
	CImage m_start;
	CVector2D m_sizecnt;
public:
	Title();
	void Update()override;
	void Draw()override;
};