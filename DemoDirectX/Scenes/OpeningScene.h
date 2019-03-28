#pragma once

#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"
#include "../GameComponents/Animation.h"
#include "../GameComponents/GameMap.h"
#include "../GameComponents/Camera.h"
#include "../GameComponents/GameDebugDraw.h"
#include "../GameObjects/Player/Player.h"

class OpeningScene : public Scene
{
public:
    OpeningScene();

    void Update(float dt);
    void LoadContent();
    void Draw();

    void OnKeyDown(int keyCode);
    void OnKeyUp(int keyCode);
    void OnMouseDown(float x, float y);

protected:
	std::vector<Sprite*> mSpriteImg;
	std::vector<Sprite*> mSpriteTitle;
	std::vector<Sprite*> mSpriteSubtitle;
	float mTimeCounter;
};

