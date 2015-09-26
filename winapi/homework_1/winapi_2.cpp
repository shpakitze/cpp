// Hello1.cpp
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <algorithm>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
///////////////////////////////////////////////////////////////////////////////////////////////
void game(HWND hWnd){
	INT try_count=0;
	INT player_ch;
std::vector <INT> num;
num.resize(101);
for (INT i=0;i<=100;++i){
	num[i]=i;
}
std::random_shuffle (num.begin(), num.end());

	TCHAR r[3];
	TCHAR message_user[32]=L"Ваше число равно ";
	TCHAR win_mess[32]=L"win. Попыток ";
	BOOL win=false;
	do{
		_itow_s(num[try_count],r,3,10);
		TCHAR all_mes[32]=L"";
		lstrcat(all_mes,message_user);
		lstrcat(all_mes,r);
		player_ch=MessageBox(hWnd, all_mes, TEXT("Играем"), MB_YESNOCANCEL|MB_ICONQUESTION);
		if (player_ch==IDYES) {
			_itow_s(try_count+1,r,3,10);
			lstrcat(win_mess,r);
			MessageBox(hWnd, win_mess, TEXT("Играем"), MB_OK|MB_ICONEXCLAMATION);
			return;
		}
		++try_count;
	} while((player_ch!=IDCANCEL));

}
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
		szClassName, TEXT("first Application"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL
		);

	if (!hMainWnd) {
		MessageBox(NULL, TEXT("Cannot create main window"), TEXT("Error"), MB_OK);
		return 0;
	}

	// Показываем наше окно
	CreateWindow(TEXT("button"),TEXT("start game"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 10, 80, 30, hMainWnd, (HMENU)10000, hInstance, NULL);
	CreateWindow(TEXT("button"),TEXT("exit"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 40, 80, 30, hMainWnd, (HMENU)10001, hInstance, NULL);
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
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	switch (msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &rect);
		DrawText(hDC, TEXT("GAME!"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER );

		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		if(LOWORD(wParam)==10000)
		{
			//MessageBox(hWnd, TEXT("Кнопка нажата"), TEXT(""), 0);
			game(hWnd);
		}
		if(LOWORD(wParam)==10001)
		{
			SendMessage(hWnd,WM_CLOSE,NULL,NULL);
		}

		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
