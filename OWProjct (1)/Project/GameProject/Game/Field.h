#pragma once
#include "./Base/Base.h"

class Field :public Base {
private:
	CImage m_sky;
public:
	Field();
	void Draw();
};
