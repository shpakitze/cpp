// Hello1.cpp
#include <windows.h>
#include <tchar.h>
#include <string>
#include <list>
#include <algorithm>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
std::list<HWND> button_list;
HANDLE hCalc;
///////////////////////////////////////////////////////////////////////////////////////////////
void delkey(HANDLE hCalc){
	if (!button_list.empty()){
	UINT style = GetWindowLong(button_list.back(),GWL_STYLE);
				style &= ~WS_VISIBLE;
				SetWindowLong(button_list.back(),GWL_STYLE,style);
				//UpdateWindow((HWND)hCalc);
				SendMessage((HWND)hCalc,WM_PAINT,0,0);
				button_list.pop_back();
	}
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
BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND) lParam; // дескриптор окна нашего приложения
	TCHAR caption[MAX_PATH] = {0}, classname[100] = {0}, text[500] = {0};
	GetWindowText(hWnd, caption, 100); // получаем текст заголовка текущего дочернего окна
	GetClassName(hWnd, classname, 100); // получаем имя класса текущего дочернего окна
	if (!lstrcmp(classname,TEXT("Button")))
	{
		button_list.push_back(hWnd);
	}
	return TRUE; // продолжаем перечисление дочерних окон
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TCHAR cap[16]=TEXT("");
	static HWND hCalcButton=0;

	switch (msg)
	{		
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam==VK_RETURN){
			hCalc=FindWindow(TEXT("CalcFrame"),TEXT("Калькулятор"));
			//hCalcButton=FindWindowEx(hCalc,hCalcButton,TEXT("Button"),TEXT(""));
			//SetClassLong(hCalcButton,GCL_STYLE,CS_
			if (button_list.empty()){
			EnumChildWindows((HWND)hCalc, EnumChildProc, (LPARAM)hWnd);
			button_list.sort();
			}
			//ShowWindow(button_list.back(), SW_HIDE);
			SetTimer(hWnd,1,1000,NULL);
			
		}
		if (wParam==VK_ESCAPE) KillTimer(hWnd,1);
		break;
	case WM_TIMER:
		delkey(hCalc);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
