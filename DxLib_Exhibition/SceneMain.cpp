#include "game.h"
#include "SceneMain.h"
#include "SceneGameOver.h"
#include "SceneClear.h"

void SceneMain::init()
{
	m_player.init();
	m_enemy.init(m_player);
	m_torch.init(m_player);
}

SceneBase* SceneMain::update()
{
	m_player.update();
	m_player.shot(m_enemy);
	m_enemy.update(m_player);
	m_torch.update(m_enemy);

	if (m_enemy.deadCount == 10)
	{
		return (new SceneClear);
	}

	if (m_player.pHP <= 0)
	{
		return (new SceneGameOver);
	}
	 
	return this;
}

void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
	m_torch.draw();
}