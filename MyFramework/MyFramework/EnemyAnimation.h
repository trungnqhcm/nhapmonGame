#pragma once
#include <unordered_map>
#include "Animation.h"
class EnemyAnimation
{
public:
	EnemyAnimation();
	~EnemyAnimation();

	enum eNinjaStates
	{
		Idling,
		Running,
		Dead,

	};

	void AddAnimation(eNinjaStates state, const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);
	EnemyAnimation* GetInstance();
	unordered_map<eNinjaStates, Animation*> mAni;
	//int x = 0;
private:

	static EnemyAnimation* instance;

};

