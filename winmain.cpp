#include "Stdafx.h"
#include "DXApp.h"
#include "MainGame.h"

// 메인 게임 초기화
int GameLoop ();
int WINAPI WinMain ( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{
	// 다이렉트 초기화
	DXApp::GetInst ()->Init ( hInstance );

	// 게임 루프
	return GameLoop ();
}
int GameLoop ()
{
	// MAIN MESSAGE
	MSG msg = { 0 };

	static DWORD time = GetTickCount ();


	while (WM_QUIT != msg.message)
	{
		if (PeekMessage ( &msg, NULL, NULL, NULL, PM_REMOVE ))
		{
			TranslateMessage ( &msg );
			DispatchMessage ( &msg );
		}
		else
		{
			if (GetTickCount () > time + 10)
			{
				time = GetTickCount ();
				
				DXApp::GetInst ()->Begin ();
				SCENEMANAGER->Run ();
				DXApp::GetInst ()->End ();
			}
		}
	}

	return static_cast<int>( msg.wParam );
}
