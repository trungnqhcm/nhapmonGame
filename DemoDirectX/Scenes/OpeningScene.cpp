#include "OpeningScene.h"
#include "DemoScene1.h"
#include "../GameDefines/GameDefine.h"
#include "../GameComponents/GameLog.h"
#include "../GameComponents/Sound.h"
#include "../GameControllers/SceneManager.h"

OpeningScene::OpeningScene()
{
    LoadContent();
}

void OpeningScene::LoadContent()
{
    //set mau backcolor cho scene o day la mau xanh
    mBackColor = 0x000000;

    Sound::getInstance()->loadSound("Resources/man1.wav", "man1");
    Sound::getInstance()->play("man1", true, 0);

	Sprite *image = new Sprite("Resources/OpeningPic.png");
	Sprite *title = new Sprite("Resources/OpeningTitle.png");
	Sprite *subtitle = new Sprite("Resources/OpeningSubTitle.png");


	image->SetPosition(GameGlobal::GetWidth() +100 , GameGlobal::GetHeight()/3);
	title->SetPosition(-150, GameGlobal::GetHeight()/2 + 150 );
	subtitle->SetPosition(GameGlobal::GetWidth()+250, GameGlobal::GetHeight()+250);

	mSpriteImg.push_back(image);
	mSpriteTitle.push_back(title);
	mSpriteSubtitle.push_back(subtitle);

}

void OpeningScene::Update(float dt)
{

	for (Sprite *child : mSpriteImg)
	{
		if (child->GetPosition().x > 150) {
			child->SetPosition(child->GetPosition() + D3DXVECTOR3(-10, 0, 0));
		}
		else
		{
			for (Sprite *child : mSpriteTitle) {
				if (child->GetPosition().x < GameGlobal::GetWidth() - 200) {
					child->SetPosition(child->GetPosition() + D3DXVECTOR3(15, 0, 0));
				}
				 else {
					for (Sprite *child : mSpriteSubtitle) {
						child->SetPosition(GameGlobal::GetWidth()-150, GameGlobal::GetHeight()-400);
					}
				};
			}
		}

	}


}

void OpeningScene::Draw()
{
	for (Sprite *child : mSpriteImg)
	{
		child->Draw();
	}
	for (Sprite *child : mSpriteTitle)
	{
		child->Draw();
	}
	for (Sprite *child : mSpriteSubtitle)
	{
		child->Draw();
	}
}

void OpeningScene::OnKeyDown(int keyCode)
{
	if (keyCode == VK_RETURN)
	{
		SceneManager::GetInstance()->ReplaceScene(new DemoScene1());
	}
}

void OpeningScene::OnKeyUp(int keyCode)
{
 
}

void OpeningScene::OnMouseDown(float x, float y)
{
}

