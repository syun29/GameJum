#pragma once
#include "Base/Base.h"

class Result : public Base
{
private:
	CImage m_img;
	CImage m_resultscore;
public:
	Result();
	void Draw()override;
};