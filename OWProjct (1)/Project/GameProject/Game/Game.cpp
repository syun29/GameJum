#include "Game.h"
#include "Block_Gray.h"
#include "Player.h"
#include "Field.h"

Game::Game()
	:Base(eType_Scene)
	,m_cnt(0)
{
	Base::Add(new Player(CVector2D(200, 500), false));
	Base::Add(new Field());
	Base::Add(new Block_Gray(CVector2D(0, 200)));

	SOUND("BackMusic")->Play();
}

void Game::Update()
{
	/*if (m_cnt++ >= 120) {
		Base::Add(new Block_Gray(CVector2D(1860, 200)));
		m_cnt = 0;
	}*/
}
