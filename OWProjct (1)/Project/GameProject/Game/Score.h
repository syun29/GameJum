#pragma once
#include "Base/Base.h"

class Score : public Base
{
private:
	CImage m_img;
	
public:
	static int m_score;
	Score();
	void AddScore(int score);
	void Update()override;
	void Draw()override;
};