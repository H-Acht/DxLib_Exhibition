#include "game.h"
#include "SceneMain.h"

void SceneMain::init()
{
	m_player.init();
	m_enemy.init();
	m_torch.init();
}

SceneBase* SceneMain::update()
{
	m_player.update(m_enemy);
	m_enemy.update(m_player);
	m_torch.update();

	return this;
}

void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
	m_torch.draw();
}