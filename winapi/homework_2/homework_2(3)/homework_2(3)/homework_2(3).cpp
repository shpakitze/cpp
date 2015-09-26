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
	TCHAR cap[16]=TEXT("");
	TCHAR oldname[]=TEXT("����");
	TCHAR newname[]=TEXT("blabla");
	HWND hStart;
	switch (msg)
	{		
	case WM_CLOSE:
		hStart=FindWindow(TEXT("Button"),newname);
		SetWindowText(hStart,oldname);
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		HWND hCalc;
		hCalc=FindWindow(TEXT("CalcFrame"),TEXT("�����������"));
		if (!hCalc) MessageBox(0,TEXT("need calc"),TEXT("error"),MB_OK);
		SetWindowText(hCalc,TEXT("blablabla"));
		break;
	case WM_RBUTTONDOWN:
		hStart=FindWindow(TEXT("Button"),oldname);
		SetWindowText(hStart,newname);
		RECT rStart;
		GetWindowRect(hStart,&rStart);
		MoveWindow(hStart,100,100,54,40,TRUE);//�� ��������
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
