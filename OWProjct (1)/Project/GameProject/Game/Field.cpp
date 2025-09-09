#include "Field.h"

Field::Field():Base(eType_Field)
{
	m_sky = COPY_RESOURCE("Sky",CImage);
}

void Field::Draw()
{
	m_sky.Draw();
}
