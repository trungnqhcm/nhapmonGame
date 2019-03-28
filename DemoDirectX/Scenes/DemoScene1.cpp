#include "DemoScene1.h"

DemoScene1::DemoScene1()
{
    LoadContent();
}

void DemoScene1::LoadContent()
{
    //set mau backcolor cho scene o day la mau den
    //mBackColor = 0x000000;

    mPlayer = new Animation("Resources/PLayer.png", 3, 1, 3, 0.15);
	mPlayer->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	mPlayer->SetScale(D3DXVECTOR2(0.125, 0.125));

	mMap = new GameMap("Resources/untitled.tmx");
}

void DemoScene1::Update(float dt)
{
	mMap->Update(dt);
	mPlayer->Update(dt);
	
}

void DemoScene1::Draw()
{
	mMap->Draw();
	mPlayer->Draw();
	
}
