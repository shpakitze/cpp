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

	// Заполняем структуру класса окна
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

	// Регистрируем класс окна
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, TEXT("Cannot register class"), TEXT("Error"), MB_OK);
		return 0;
	}

	// Создаем основное окно приложения
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

	// Показываем наше окно
	ShowWindow(hMainWnd, nCmdShow); 
	//	UpdateWindow(hMainWnd);

	// Выполняем цикл обработки сообщений до закрытия приложения
	while (GetMessage(&msg, NULL, 0, 0))  {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
///////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	RECT user_rec,unsize_user_rec;	
	TCHAR cap[16]=TEXT("");
	PAINTSTRUCT ps;
	HDC hDC;
	switch (msg)
	{
		case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &user_rec);
		unsize_user_rec.bottom=user_rec.bottom-10;
		unsize_user_rec.top=user_rec.top+10;
		unsize_user_rec.left=user_rec.left+10;
		unsize_user_rec.right=user_rec.right-10;
		ps.rcPaint=unsize_user_rec;
		FillRect(hDC,&unsize_user_rec,HBRUSH(CreateSolidBrush(RGB(0,0,0))));
		unsize_user_rec.bottom=user_rec.bottom-11;
		unsize_user_rec.top=user_rec.top+11;
		unsize_user_rec.left=user_rec.left+11;
		unsize_user_rec.right=user_rec.right-11;
		FillRect(hDC,&unsize_user_rec,HBRUSH(CreateSolidBrush(RGB(250,0,0))));
		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		GetClientRect(hWnd, &user_rec);
		if ((LOWORD(lParam)<10)||(LOWORD(lParam)>user_rec.right-10)||(
			HIWORD(lParam)<10)||(HIWORD(lParam)>user_rec.bottom-10)){
				_tcscpy(cap,TEXT("outside"));
				//wsprintf(cap,TEXT("X=%d, Y=%d"),LOWORD(lParam),HIWORD(lParam));
				SetWindowText(hWnd,cap);
		} else 
			if  ((LOWORD(lParam)==10)||(LOWORD(lParam)==user_rec.right-10)||(
				HIWORD(lParam)==10)||(HIWORD(lParam)==user_rec.bottom-10)){
					_tcscpy(cap,TEXT("border"));
					//wsprintf(cap,TEXT("X=%d, Y=%d"),LOWORD(lParam),HIWORD(lParam));
					SetWindowText(hWnd,cap);
			} else
			{
				_tcscpy(cap,TEXT("inside"));
				//wsprintf(cap,TEXT("X=%d, Y=%d"),LOWORD(lParam),HIWORD(lParam));
				SetWindowText(hWnd,cap);
			}
			//ldown
			break;
	case WM_RBUTTONDOWN:
		GetClientRect(hWnd, &user_rec);
		wsprintf(cap,TEXT("X=%i, Y=%i"),user_rec.right,user_rec.bottom);
		SetWindowText(hWnd,cap);
		//rdown
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
