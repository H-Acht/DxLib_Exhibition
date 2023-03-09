#pragma once
#include "SceneBase.h"

class SceneRule : public SceneBase
{
public:
	SceneRule();
	virtual ~SceneRule();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;
};