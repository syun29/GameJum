#include "Result.h"
#include "Game/Score.h"

Result::Result()
	: Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Scene", CImage);
	m_font = COPY_RESOURCE("Result_Font", CImage);
	m_resultscore = COPY_RESOURCE("Score", CImage);
}

void Result::Draw()
{
		m_img.Draw();
	
		int i;
		int n = Score::m_score;
		for (i = 0; i < 4; i++, n /= 10) {
			int c = n % 10;
			m_resultscore.SetRect(c * 114, 0, c * 114 + 114, 114);
			m_resultscore.SetSize(200 ,200);
			m_resultscore.SetPos(1150 - 200 * i, 200);
			m_resultscore.Draw();
		}
	

}
