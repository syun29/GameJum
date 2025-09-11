#pragma once
#include "Base/Base.h"

class Score : public Base
{
private:
	CImage m_img;
	
public:
	int m_score;
	Score();
	void Update()override;
	void Draw()override;
};