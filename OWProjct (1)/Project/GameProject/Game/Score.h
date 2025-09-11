#pragma once
#include "Base/Base.h"

class Score : public Base
{
private:
	CImage m_img;
	int m_score;
public:
	Score();
	void Update()override;
	void Draw()override;
};