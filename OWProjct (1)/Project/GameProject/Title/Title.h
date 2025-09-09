#pragma once
#include "Base/Base.h"

class Title : public Base
{
private:
	CImage m_img;
	CImage m_font;
public:
	Title();
	void Update()override;
	void Draw()override;
};