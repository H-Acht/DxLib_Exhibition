#include "game.h"
#include "SceneMain2.h"
#include "SceneGameOver.h"
#include "SceneClear.h"

void SceneMain2::init()
{
	m_player.init();
	m_enemy.init(m_player);
	m_torch.init(m_player);
}

SceneBase* SceneMain2::update()
{
	m_player.update(m_enemy);
	m_enemy.update2(m_player);
	m_torch.update(m_enemy);

	if (m_enemy.deadCount == 20)
	{
		return (new SceneClear);
	}

	if (m_player.pHP <= 0)
	{
		return (new SceneGameOver);
	}

	return this;
}

void SceneMain2::draw()
{
	m_player.draw();
	m_enemy.draw();
	m_torch.draw();
}