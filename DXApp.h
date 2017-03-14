#pragma once
#define WIN32_LEAN_AND_MEan
#include <windows.h>
#include <string>
#include "DXUtil.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "Singleton.h"

class DXApp : public Singleton<DXApp>
{
public:
	DXApp ();
	virtual ~DXApp ();

public:
	virtual bool Init ( HINSTANCE hInst );
	void Begin ();
	void End ();
	virtual LRESULT MsgProc ( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

	void DrawDXText ( float x, float y, std::wstring text );

protected:
	bool InitWindow ();
	bool InitDirect3D ();

protected:
	// WIN32 ATTRIBUTES
	HWND					m_hAppWnd;
	UINT					m_Client;
	UINT					m_ClientWidth;
	UINT					m_ClientHeight;
	HINSTANCE				m_hAppInstance;
	std::string				m_AppTitle;
	DWORD					m_WndStyle;

	// DIRECT X ATRRIBUTES
	ID3D11Device*		 m_pDevice;
	ID3D11BlendState*     m_pBlendState;
	ID3D11DeviceContext* m_pImmediateCotext;
	IDXGISwapChain*		 m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;
	D3D_DRIVER_TYPE		 m_DriverType;
	D3D_FEATURE_LEVEL	 m_FeatureLevel;
	D3D11_VIEWPORT		 m_Viewport;

	std::unique_ptr<DirectX::SpriteBatch> m_SpriteBatch;
	std::unique_ptr<DirectX::SpriteFont>  m_SpriteFont;

public:
	DirectX::SpriteBatch* GetSpriteBatch () { return m_SpriteBatch.get (); }
	DirectX::SpriteFont*  GetSpriteFont () { return m_SpriteFont.get (); }
	ID3D11Device* GetDevice () { return m_pDevice; }
	ID3D11DeviceContext* GetContext () { return m_pImmediateCotext; }
	ID3D11BlendState* GetBlendState () { return m_pBlendState; }
	HWND GetHwnd () { return m_hAppWnd; }
	BYTE* GetPixel ( ID3D11Resource* sourTexture, float x, float y);
};