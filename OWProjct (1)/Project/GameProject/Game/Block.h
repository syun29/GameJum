#pragma once
#include "Base/Base.h"

class Block :public Base {
private:
	CImage m_img;
	int cnt;
public:
	Block();
	void Update();
	void Draw();
};