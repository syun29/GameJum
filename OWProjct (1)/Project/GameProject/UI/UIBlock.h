#pragma once
#include "Base/Base.h"

class UIBlock : public Base
{
private:
	CImage m_img[7];
	CImage m_number[7];
public:
	UIBlock();
	void Update()override;
	void Draw()override;
};
