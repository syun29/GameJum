#include "Result.h"
#include "Game/Score.h"
#include "Title.h"

Result::Result()
	: Base(eType_Scene)
	, m_alpha(0.0f)
	, m_fontstate(0)
	, m_cnt(0)
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
}

void Result::Draw()
{
	
	switch (m_fontstate) {
	case 0:
		//if (PUSH(CInput::eButton1))
		m_fontstate++;
		break;
	case 1:
		//�Ɖ��Z
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
	////�d�˂ĕ`��

	////sin�J�[�u
	m_font.SetColor(1, 1, 1, sin(m_alpha));
	m_font.Draw();
	//if (Score* s = dynamic_cast<Score*>(Base::FindObject(eType_Score))) {
		int i;
		int n = Score::m_score;
		for (i = 0; i < 4; i++, n /= 10) {
			int c = n % 10;
			m_resultscore.SetRect(c * 114, 0, c * 114 + 114, 114);
			m_resultscore.SetSize(200, 200);
			m_resultscore.SetPos(1150 - 200 * i, 200);
			m_resultscore.Draw();
		}
	//}
		

}
