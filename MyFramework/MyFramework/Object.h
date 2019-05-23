#pragma once
#include "GameGlobal.h"
#include "Animation.h"
#include "Sprite.h"

class Object:public Sprite
{
public:
	Object();
	~Object();

	enum ObjectTypes
	{
		Ninja,
		Enemy,
		None,
	};

	ObjectTypes Tag; //Tag de nhan dien loai object

	virtual void moveTo(Object *des); // object di chuyen  den vi tri cua object khac ( des )

	virtual void moveTo(Object* des, int v);

	virtual RECT GetBound();

	virtual void Reset(D3DXVECTOR2 pos);
	virtual void SetPosition(float x, float y);

	virtual void SetPosition(D3DXVECTOR2 pos);

	virtual void SetPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR2 pos);

	virtual void AddPosition(float x, float y);

	virtual void SetWidth(int width);

	virtual int GetWidth();

	virtual void SetHeight(int height);

	virtual int GetHeight();

	virtual float GetVx();

	virtual void SetVx(float vx);

	virtual void AddVx(float vx);

	virtual float GetVy();

	virtual void SetVy(float vy);

	virtual void AddVy(float vy);

	virtual D3DXVECTOR3 GetPosition();

	virtual void Update(float dt);

	virtual int getX() {
		return x;
	}

	virtual int getY()
	{
		return y;
	}

	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	bool isVisible;
protected:

	//duoc goi khi set position cua object, dung cho ke thua
	virtual void OnSetPosition(D3DXVECTOR3 pos);

	//vi tri tam position x va y
	float x, y;

	//phan toc vx, vy
	float vx, vy;

	//size cua entity
	float width, height;

};

