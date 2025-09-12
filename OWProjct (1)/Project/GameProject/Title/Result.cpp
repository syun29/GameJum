#include "Result.h"
#include "Game/Score.h"
#include "Title.h"

Result::Result()
	: Base(eType_Scene)
	, m_alpha(0.0f)
	, m_fontstate(0)
	, m_cnt(0)
	, m_blockcnt(60*3)
	,m_drawscore(0)
{
	m_img = COPY_RESOURCE("Scene", CImage);
	m_font = COPY_RESOURCE("Result_Font", CImage);
	m_resultscore = COPY_RESOURCE("Score", CImage);
}

void Result::Update()
{
	
	m_cnt++;
	if (PUSH(CInput::eButton5)&&m_cnt>=60)
	{
		KillAll();
		Base::Add(new Title());
		Score::m_score = 0;
		m_cnt = 0;
	}

	m_blockcnt--;
	if (m_blockcnt <= 0) {
		CVector2D pos(Utility::Rand(0.0f, 1900.f),
			Utility::Rand(0.0f, 0.0f));
		int type = rand() % 6;
		int ang = rand() % 4;
		Base::Add(new TitleUI(pos, type,90*ang));

		m_blockcnt = 60 * 3;
	}

	m_drawscore++;
	if (m_drawscore > Score::m_score)
	{
		m_drawscore = Score::m_score;
	}
}

void Result::Draw()
{
	
	switch (m_fontstate) {
	case 0:
		//if (PUSH(CInput::eButton1))
		m_fontstate++;
		break;
	case 1:
		//θ加算
		m_alpha += 0.05f;
		if (m_alpha > DtoR(180)) {
			m_alpha = 0;
		}
		break;
	}

	m_font.SetSize(450, 96);
	m_font.SetPos(750, 700);
	
	//m_font.Draw();
	m_img.Draw();
	m_font.SetColor(1, 1, 1, 0.8);
	m_font.Draw();
	////重ねて描画

	////sinカーブ
	m_font.SetColor(1, 1, 1, sin(m_alpha));
	m_font.Draw();
	//if (Score* s = dynamic_cast<Score*>(Base::FindObject(eType_Score))) {
		int i;
		int n = m_drawscore;
		for (i = 0; i < 4; i++, n /= 10) {
			int c = n % 10;
			m_resultscore.SetRect(c * 114, 0, c * 114 + 114, 114);
			m_resultscore.SetSize(200, 200);
			m_resultscore.SetPos(1150 - 200 * i, 200);
			m_resultscore.Draw();
		}
	//}
		

}
