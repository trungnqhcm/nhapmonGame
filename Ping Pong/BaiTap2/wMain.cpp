#include "Framework.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lCmdLine, int lCmdShow)
{
	FrameWork *fw = new FrameWork();
	if (fw->Initialize())
		fw->Run();
	
	delete fw;

	return 0;
}
