#pragma once
#include "Object.h"
class LeoPard :
	public Object
{
public:
	enum eMoveDirection
	{
		MoveToLeft, //chay tu phai sang trai
		MoveToRight, //chay tu trai sang phai
		None //dung im
	};

	LeoPard();
	~LeoPard();
	
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	
	void SetState(EnemyState* newState);

	void Update(float);
	
	RECT GetBound();
	
	void setFlipVertical(bool isFlip)
	{
		this->leopardAni->FlipVertical(isFlip);
	}
	
	Animation *leopardAni;

};

