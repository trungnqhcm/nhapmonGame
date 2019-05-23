#pragma once
#include "EnemyData.h"
#include "Enemy.h"
#include <map>
using namespace std;

class NinjaState
{
public:

	virtual void Update(float dt);
	virtual void HandleKeyboard(map<int, bool> keys);
	virtual  EnemyAnimations::eEnemyStates GetState() = 0;
	~EnemyState();
protected:
	EnemyState(NinjaData* ninjaData);
	EnemyState();

	EnemyData* ninjaData;

};

