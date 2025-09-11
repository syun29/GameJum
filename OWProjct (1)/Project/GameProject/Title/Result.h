#pragma once
#include "Base/Base.h"

class Result : public Base
{
private:
	CImage m_img;
	CImage m_font;
	CImage m_resultscore;
public:
	Result();
	void Update()override;
	void Draw()override;
};