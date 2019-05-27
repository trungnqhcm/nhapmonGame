#ifndef _CENUM_H_
#define _CENUM_H_

enum Action
{
	Idle,
	Run_Right,
	Run_Left,
	Jump1,
	Jump2,
	Fight,
	Sit,
	SitAttack,
	Fall,
	Climb,
	Attack,
};

static enum ESceneState
{
	Menu_Scene,
	Game_Scene,
	EndGame_Scene
} EnumSceneState;


enum ObjectType
{
	None_Type,
	Item_Type,
	Enemy_Type,
	Other_Type
};

enum EKindStair
{
	UpRight,
	UpLeft,
	DownRight,
	DownLeft,
	None
};

enum EnumID
{
	//Weapon
	None_ID,
	//Action
	Ryu_ID,
	RyuRun_ID,
	RyuDeath_ID,
	RyuJump1_ID,
	RyuJump2_ID,
	RyuClimb_ID,
	RyuAttack_ID,
	RyuSit_ID,
	RyuSitAttack_ID,
	//Ground
	Ground1_ID,
	Stair_ID,
	Ground2_ID,
	//Enemy
	SwordMan_ID,
	RocketMan_ID,
	Banshee_ID,
	Boss_ID,
	//Items
	Hp_ID,
	GameScore_ID,
	Bullet_ID,
	Sword_ID,
	Fire_ID,
	Boomerang_ID,
	Explosion_ID
};


enum EStateCamera
{
	Update_Camera,
	NoUpdate_Camera
};

enum EState
{
	None_State,
	NoUpdate_State
};

enum ECollisionDirect
{
	Colls_None,
	Colls_Left,
	Colls_Right,
	Colls_Bot,
	Colls_Top
};

enum EKind
{
	EDynamic,
	EStatic,
	ESolid,
	EScene
};
#endif