#pragma once
#include <unordered_map>
#include "Animation.h"
class EnemyAnimation
{
public:
	EnemyAnimation();
	~EnemyAnimation();

	enum eEnemyStates
	{
		Idling,
		Running,
		Dead,

	};

	void AddAnimation(eEnemyStates state, const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);
	EnemyAnimation* GetInstance();
	unordered_map<eEnemyStates, Animation*> mAni;
	//int x = 0;
private:

	static EnemyAnimation* instance;

};

