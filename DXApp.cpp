#include "stdafx.h"

#include "DXApp.h"
#include "SimpleMath.h"

namespace
{
	// USED TO FORWARD MSGS TO USER DEFINED PROC FUNCTION
	DXApp* g_pApp = nullptr;
	// ㅎㅇ
}


DXApp::DXApp ()
{
}

LRESULT DXApp::MsgProc ( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage ( 0 );
		return 0;

	default:
		return DefWindowProc ( hwnd, msg, wParam, lParam );
	}
}

void DXApp::DrawDXText ( float x, float y, std::wstring text )
{
	m_SpriteFont->DrawString ( m_SpriteBatch.get (), text.c_str (), DirectX::SimpleMath::Vector2 ( x, y ));
}


LRESULT CALLBACK MainWndProc ( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	if (g_pApp) return g_pApp->MsgProc ( hwnd, msg, wParam, lParam );
	else return DefWindowProc ( hwnd, msg, wParam, lParam );
}

DXApp::~DXApp ()
{
	// CLEANUP DIRECT3D
	if (m_pImmediateCotext) m_pImmediateCotext->ClearState ();

	Memory::SafeRelease ( m_pRenderTargetView );
	Memory::SafeRelease ( m_pSwapChain );
	Memory::SafeRelease ( m_pImmediateCotext );
	Memory::SafeRelease ( m_pBlendState );
	Memory::SafeRelease ( m_pDevice );
}


bool DXApp::Init (HINSTANCE hInst)
{
	m_hAppInstance = hInst;
	m_hAppWnd = NULL;
	m_ClientWidth = WIN_WIDTH;
	m_ClientHeight = WIN_HEIGHT;
	m_AppTitle = "앙~빅";
	m_WndStyle = WS_OVERLAPPEDWINDOW;

	m_pDevice = nullptr;
	m_pImmediateCotext = nullptr;
	m_pRenderTargetView = nullptr;
	m_pSwapChain = nullptr;

	if (!InitWindow ())
		return false;

	if (!InitDirect3D ())
		return false;

	// 스프라이트 배치 초기화
	m_SpriteBatch.reset ( new DirectX::SpriteBatch ( m_pImmediateCotext ) );

	// 폰트 초기화
	m_SpriteFont.reset ( new DirectX::SpriteFont ( m_pDevice, L"font/godic.spritefont" ) );
	return true;
}


bool DXApp::InitWindow ()
{
	WNDCLASSEX wcex;
	ZeroMemory ( &wcex, sizeof ( WNDCLASSEX ) );
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof ( WNDCLASSEX );
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = m_hAppInstance;
	wcex.lpfnWndProc = MainWndProc;
	wcex.hIcon = LoadIcon ( NULL, IDI_APPLICATION );
	wcex.hCursor = LoadCursor ( NULL, IDC_ARROW );
	wcex.hbrBackground = (HBRUSH)GetStockObject ( NULL_BRUSH );
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "DXAPPWNDCLASS";
	wcex.hIconSm = LoadIcon ( NULL, IDI_APPLICATION );

	if (!RegisterClassEx ( &wcex ))
	{
		OutputDebugString ( "\nFAILED TO CREATE WINDOW CLASS\n\n\n\n\n" );
		return false;
	}


	RECT r = { 0, 0, static_cast<LONG>(m_ClientWidth), static_cast<LONG>(m_ClientHeight) };
	AdjustWindowRect ( &r, m_WndStyle, FALSE );
	UINT width = r.right - r.left;
	UINT height = r.bottom - r.top;
	UINT x = GetSystemMetrics ( SM_CXSCREEN ) / 2 - width / 2;
	UINT y = GetSystemMetrics ( SM_CYSCREEN ) / 2 - height / 2;


	m_hAppWnd = CreateWindow ( wcex.lpszClassName, m_AppTitle.c_str (), m_WndStyle,
		x, y, width, height, NULL, NULL, m_hAppInstance, NULL );
	if (!m_hAppWnd)
	{
		OutputDebugString ( "\nFAILED TO CREATE WINDOW CLASS\n\n\n\n\n" );
		return false;
	}

	ShowWindow ( m_hAppWnd, SW_SHOW );

	g_pApp = this;

	return true;
}

bool DXApp::InitDirect3D ()
{

	UINT createDeviceFlags = 0;

#ifdef DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // DEBUG

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	
	UINT numDriverTypes = ARRAYSIZE ( driverTypes );

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3
	};

	UINT numFeatureLevels = ARRAYSIZE ( featureLevels );
	
	DXGI_SWAP_CHAIN_DESC swapDesc;
	ZeroMemory ( &swapDesc, sizeof ( DXGI_SWAP_CHAIN_DESC ) );
	swapDesc.BufferCount = 1; // double buffered
	swapDesc.BufferDesc.Width = m_ClientWidth;
	swapDesc.BufferDesc.Height = m_ClientHeight;
	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.OutputWindow = m_hAppWnd;
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapDesc.Windowed = TRUE;
	swapDesc.SampleDesc.Count = 1;
	swapDesc.SampleDesc.Quality = 0;
	swapDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // alt+enter fullscreen

	HRESULT result;
	for (DWORD i = 0; i < numDriverTypes; ++i)
	{
		result = D3D11CreateDeviceAndSwapChain ( NULL, driverTypes[i], NULL, createDeviceFlags,
			featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &swapDesc, &m_pSwapChain, &m_pDevice,
			&m_FeatureLevel, &m_pImmediateCotext );

		if (SUCCEEDED ( result ))
		{
			m_DriverType = driverTypes[i];
			break;
		}

	}

	if (FAILED ( result ))
	{
		OutputDebugString ( "FAILED TO CREATE DEVICE AND SWAP CHAIN" );
		return false;
	}

	/// CREATE RENDER TARGET VIEW
	ID3D11Texture2D* m_pBackBufferTex = nullptr;
	m_pSwapChain->GetBuffer ( NULL, __uuidof( ID3D11Texture2D ), reinterpret_cast<void**>( &m_pBackBufferTex ) );
	m_pDevice->CreateRenderTargetView ( m_pBackBufferTex, nullptr, &m_pRenderTargetView );

	// BIND RENDER TARGET VIEW
	m_pImmediateCotext->OMSetRenderTargets ( 1, &m_pRenderTargetView, nullptr );

	//VIEWPORT CREATION
	m_Viewport.Width = static_cast<float>( m_ClientWidth );
	m_Viewport.Height = static_cast<float>( m_ClientHeight );
	m_Viewport.TopLeftX = 0;
	m_Viewport.TopLeftY = 0;
	m_Viewport.MinDepth = 0.0f;
	m_Viewport.MaxDepth = 1.0f;

	// BIND VIEWPORT
	m_pImmediateCotext->RSSetViewports ( 1, &m_Viewport );

	// 블렌드 스테이트
	D3D11_BLEND_DESC blendDesc;

	ZeroMemory ( &blendDesc, sizeof ( blendDesc ) );
	blendDesc.AlphaToCoverageEnable = false;
	blendDesc.IndependentBlendEnable = false;
	blendDesc.RenderTarget[0].BlendEnable = true;
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
	blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	m_pDevice->CreateBlendState ( &blendDesc, &m_pBlendState );


	return true;
}

BYTE* DXApp::GetPixel (ID3D11Resource* sourTexture, float x, float y)
{
	ID3D11Resource* destTexture = NULL;

	D3D11_BOX srcBox;
	srcBox.left = x;
	srcBox.right = srcBox.left + 1;
	srcBox.top = y;
	srcBox.bottom = srcBox.top + 1;
	srcBox.front = 0;
	srcBox.back = 1;

	m_pImmediateCotext->CopySubresourceRegion ( destTexture, 0, 0, 0, 0, sourTexture, 0, &srcBox );

	D3D11_MAPPED_SUBRESOURCE msr;
	m_pImmediateCotext->Map ( destTexture, 0, D3D11_MAP_READ, 0, &msr );
	BYTE *pixel = (BYTE*)msr.pData;
	// copy data
	m_pImmediateCotext->Unmap ( destTexture, 0 );

	return pixel;
}

void DXApp::Begin ()
{
	m_pImmediateCotext->ClearRenderTargetView ( m_pRenderTargetView, DirectX::Colors::Black );
	m_SpriteBatch->Begin ( DirectX::SpriteSortMode::SpriteSortMode_Immediate, m_pBlendState );
}

void DXApp::End ()
{
	m_SpriteBatch->End ();
	m_pSwapChain->Present ( 0, 0 );
}
