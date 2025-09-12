#include "Score.h"
#include "UI/UIBlock.h"

int Score::m_score = 0;

Score::Score()
	:Base(eType_Score)
	
{
	m_img = COPY_RESOURCE("Score", CImage);
}

void Score::AddScore(int score)
{
	m_score += score;
}

void Score::Update()
{
	/*if (PUSH(CInput::eButton2))
	{
		m_score++;
	}*/
}

void Score::Draw()
{
	int i;
	int n = m_score;
	for (i = 0; i < 4; i++, n /= 10) {
		int c = n % 10;
		m_img.SetRect(c * 114, 0, c * 114 + 114, 114);
		m_img.SetSize(100, 100);
		m_img.SetPos(800 - 114 * i, 100);
		m_img.Draw();
	}
}
