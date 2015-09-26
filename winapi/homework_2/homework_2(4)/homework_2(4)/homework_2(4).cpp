// Hello1.cpp
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <algorithm>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
///////////////////////////////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hMainWnd;  
	TCHAR szClassName[] = TEXT("MyClass");
	MSG msg;
	WNDCLASSEX wc;

	// ��������� ��������� ������ ����
	wc.cbSize        = sizeof(wc);		
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	// ������������ ����� ����
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, TEXT("Cannot register class"), TEXT("Error"), MB_OK);
		return 0;
	}

	// ������� �������� ���� ����������
	hMainWnd = CreateWindow( 
		szClassName, TEXT("homework_2"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL
		);

	if (!hMainWnd) {
		MessageBox(NULL, TEXT("Cannot create main window"), TEXT("Error"), MB_OK);
		return 0;
	}

	// ���������� ���� ����
	ShowWindow(hMainWnd, nCmdShow); 
	//	UpdateWindow(hMainWnd);

	// ��������� ���� ��������� ��������� �� �������� ����������
	while (GetMessage(&msg, NULL, 0, 0))  {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
///////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{		
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		RECT winsize;
		GetWindowRect(hWnd,&winsize);
		if (wParam==VK_LEFT)
			MoveWindow(hWnd,winsize.left-10,winsize.top,winsize.right-winsize.left,winsize.bottom-winsize.top,1);
		if (wParam==VK_RIGHT)
			MoveWindow(hWnd,winsize.left+10,winsize.top,winsize.right-winsize.left,winsize.bottom-winsize.top,1);
		if (wParam==VK_UP)
			MoveWindow(hWnd,winsize.left,winsize.top-10,winsize.right-winsize.left,winsize.bottom-winsize.top,1);
		if (wParam==VK_DOWN)
			MoveWindow(hWnd,winsize.left,winsize.top+10,winsize.right-winsize.left,winsize.bottom-winsize.top,1);
		if (wParam==VK_RETURN)
			MoveWindow(hWnd,0,0,300,300,1);

		break;
	case WM_RBUTTONDOWN:
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
