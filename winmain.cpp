#include "Stdafx.h"
#include "DXApp.h"
#include "MainGame.h"

// ���� ���� �ʱ�ȭ
int GameLoop ();
int WINAPI WinMain ( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{
	// ���̷�Ʈ �ʱ�ȭ
	DXApp::GetInst ()->Init ( hInstance );

	// ���� ����
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
