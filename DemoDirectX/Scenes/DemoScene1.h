#pragma once

#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"
#include "../GameComponents/Animation.h"
#include "../GameComponents/GameMap.h"

class DemoScene1 : public Scene
{
public:
    DemoScene1();

    void Update(float dt);
    void LoadContent();
    void Draw();

protected:
    Animation *mPlayer;

    float mTimeCounter;
	GameMap *mMap;
};

