#pragma once
#include "Base/Base.h"

class Score : public Base
{
private:
	CImage m_img;
public:
	Score();
	void Update()override;
	void Draw()override;
};