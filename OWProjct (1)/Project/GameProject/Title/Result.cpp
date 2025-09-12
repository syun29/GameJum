#include "Result.h"
#include "Game/Score.h"
#include "Title.h"

Result::Result()
	: Base(eType_Scene)
	, m_alpha(0)
	, m_fontstate(0)
{
	m_img = COPY_RESOURCE("Scene", CImage);
	m_font = COPY_RESOURCE("Result_Font", CImage);
	m_resultscore = COPY_RESOURCE("Score", CImage);
}

void Result::Update()
{
	if (PUSH(CInput::eButton5))
	{
		KillAll();
		Base::Add(new Title());
	}
}

void Result::Draw()
{
	
	//switch (m_fontstate) {
	//case 0:
	//	//if (PUSH(CInput::eButton1))
	//	m_fontstate++;
	//	break;
	//case 1:
	//	//θ加算
	//	m_alpha += 0.05f;
	//	if (m_alpha > DtoR(180)) {
	//		m_alpha = 0;
	//	}
	//	break;
	//}

	m_font.SetSize(450, 96);
	m_font.SetPos(750, 700);

	//m_font.SetColor(1, 1, 1, 1);
	//m_font.Draw();

	////重ねて描画

	////sinカーブ
	//m_font.SetColor(1, 1, 1, sin(m_alpha));
	//m_font.Draw();
	m_img.Draw();
	if (Score* s = dynamic_cast<Score*>(Base::FindObject(eType_Score))) {
		int i;
		int n = s->m_score;
		for (i = 0; i < 4; i++, n /= 10) {
			int c = n % 10;
			m_resultscore.SetRect(c * 114, 0, c * 114 + 114, 114);
			m_resultscore.SetSize(200, 200);
			m_resultscore.SetPos(1150 - 200 * i, 200);
			m_resultscore.Draw();
		}
	}
		m_font.Draw();

}
