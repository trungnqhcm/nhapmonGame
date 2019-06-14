#include "SceneGame.h"

#define GRID Grid::getInstance()
bool isLoadStage = false;

SceneGame::SceneGame(void) : Scene(ESceneState::Game_Scene)
{
	camera = new CCamera();
	bg = NULL;
	grid = GRID;
	_levelNow = 1;
	_loadLevel = false;
	_score = 0;
	_lifes = 10;
}

void SceneGame::LoadLevel(int level)
{
	ResetLevel(); 
	switch (level)
	{
	case 1:
	{
		camera->viewport.y = 420;
		//camera->viewport.x = 1023;
		bg = new Background(level);
		ryu = new Ryu(200, 140);
	}
	break;
	
	case 2:
	case 3:
	{
		camera->viewport.y = 420;
		//camera->viewport.x = 1023;
		bg = new Background(level);
		//ryu->_action = Action::Idle;
		ryu = new Ryu(90, 300);
	}
	break;
	default:
		break;
	}
}

void SceneGame::LoadStage(int level)
{
	switch (level)
	{
	case 1:
	{
		qGameObject = new QGameObject("Resources\\Maps\\Stage3.1-GameObj.txt");
		if (!isLoadStage)
		{
			grid->addObject(qGameObject->_staticObject);
			grid->addObject(qGameObject->_dynamicObject);
		}
	}
	break;
	case 2:
	case 3:
	{
		qGameObject = new QGameObject("Resources\\Maps\\Stage3.3-GameObj.txt");
		if (!isLoadStage)
		{
			grid->addObject(qGameObject->_staticObject);
			grid->addObject(qGameObject->_dynamicObject);
		}
	}
	break;
	}
	camera->SetSizeMap(bg->getWidth(), 0);
}

void SceneGame::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int deltaTime)
{
	if (_levelNow > 0)
	{
		if (ryu->posX > bg->getWidth() - 100 && _levelNow < 3)
		{
			_levelNow++;
			LoadResources(G_Device);
			ryu->sprite->SelectIndex(0);
			ryu->_action = Action::Idle;
			isLoadStage = false;
		}
		if (ryu->ryuLife == 0)
		{
			LoadResources(G_Device);
			ryu->sprite->SelectIndex(0);
			ryu->_action = Action::Idle;
			isLoadStage = false;
		}
		//Xu ly scene
		//--------------Over time-------------------
		//if (_gameScore->getTimer() <= 0)
			//sceneState = ESceneState::Menu_Scene;
		list<GameObject*> lstObjectsHaveToWork;
		vector<GameObject*> allObjectsHaveToWork = grid->getObjectActive(camera);
		std::copy(allObjectsHaveToWork.begin(), allObjectsHaveToWork.end(), std::back_inserter(lstObjectsHaveToWork));
		//*(qGameObject->_dynamicObject) = allObjectsHaveToWork;
		for (size_t i = 0; i < allObjectsHaveToWork.size(); i++)
		{
			allObjectsHaveToWork[i]->Update(deltaTime);
			allObjectsHaveToWork[i]->Update(deltaTime, ryu->getPos());
			ryu->Collision(lstObjectsHaveToWork, deltaTime, true);
			allObjectsHaveToWork[i]->Collision(lstObjectsHaveToWork, deltaTime);
		}

		G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		ryu->Update(deltaTime);
		camera->UpdateCamera(ryu->posX);

		bg->Draw(camera);
		for (size_t i = 0; i < allObjectsHaveToWork.size(); i++)
		{
			allObjectsHaveToWork[i]->Draw(camera);
		}
		//qGameObject->Draw(camera);
		ryu->Draw(camera);
		G_SpriteHandler->End();

	}
}

void SceneGame::ProcessInput(int keyCode)
{
	switch (keyCode)
	{
	case DIK_RIGHT:
		ryu->TurnRight();
		break;
	case DIK_LEFT:
		ryu->TurnLeft();
		break;	
	default:
		ryu->Stop();
		break;
	}
}


void SceneGame::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));

	D3DXCreateSprite(d3ddv, &G_SpriteHandler);

	HRESULT res = D3DXCreateSprite(d3ddv, &G_SpriteHandler);


	if (_levelNow != 0)
	{
		LoadLevel(_levelNow);
		LoadStage(_levelNow);
		isLoadStage = true;
	}
}

void SceneGame::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_Z:
		ryu->Jump();
		break;
	case DIK_X:
		ryu->Attack(false);
		break;
	case DIK_DOWN:
		ryu->Sit();
		break;
	}
}

SceneGame::~SceneGame(void)
{
	if (camera != NULL)
		delete camera;
}
void SceneGame::ResetLevel()
{
	if (bg != NULL)
		delete bg;
	if (qGameObject != NULL)
		delete qGameObject;
}