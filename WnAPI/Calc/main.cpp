﻿#include <Windows.h>

#define IDC_EDIT_DISPLAY		999

#define IDC_BUTTON_0			1000
#define IDC_BUTTON_1			1001
#define IDC_BUTTON_2			1002
#define IDC_BUTTON_3			1003
#define IDC_BUTTON_4			1004
#define IDC_BUTTON_5			1005
#define IDC_BUTTON_6			1006
#define IDC_BUTTON_7			1007
#define IDC_BUTTON_8			1008
#define IDC_BUTTON_9			1009

#define IDC_BUTTON_POINT		1011
#define IDC_BUTTON_MINUS		1012
#define IDC_BUTTON_ASTER		1013	// '*'
#define IDC_BUTTON_SLASH		1014	// '/'
#define IDC_BUTTON_PLUS			1015

#define IDC_BUTTON_BSP			1016	// Backspace удалить
#define IDC_BUTTON_CLR			1017	// Очистить
#define IDC_BUTTON_EQUAL		1018	// Равно

CONST CHAR g_sz_WINDOW_CLASS[] = "Calc_VPD_311";

CONST INT g_i_SCREEN_WIDTH = 400;
CONST INT g_i_SCREEN_HEIGHT = 22;

CONST INT g_i_BUTTON_SIZE = 50; // Размер кнопки в пикселях
CONST INT g_i_INTERVAL = 5;		//расстояние между кнопками

CONST INT g_i_START_X = 10;
CONST INT g_i_START_Y = 10;
CONST INT g_i_BUTTON_START_X = g_i_START_X;
CONST INT g_i_BUTTON_START_Y = g_i_START_Y + g_i_SCREEN_HEIGHT + g_i_INTERVAL;

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(wClass));

	wClass.style = 0;
	wClass.cbSize = sizeof(wClass);
	wClass.cbClsExtra = 0;
	wClass.cbWndExtra = 0;

	//wClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	//wClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

	wClass.hIcon = (HICON)LoadImage(hInstance, "Ico\\Calculator.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wClass.hIconSm = (HICON)LoadImage(hInstance, "Ico\\Calculator.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);

	wClass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_ARROW));
	wClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(205, 127, 50));

	wClass.hInstance = hInstance;
	wClass.lpszClassName = g_sz_WINDOW_CLASS;
	wClass.lpszMenuName = NULL;
	wClass.lpfnWndProc = (WNDPROC)WndProc;

	if (!RegisterClassEx(&wClass))
	{
		MessageBox(NULL, "Class registrtion failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);
	INT window_start_x = screen_width / 3;
	INT window_start_y = screen_height / 4;

	INT window_width = screen_width /5;
	INT window_height = screen_height /2;

	HWND hwnd = CreateWindowEx
	(
		NULL,
		g_sz_WINDOW_CLASS,
		g_sz_WINDOW_CLASS,
		WS_OVERLAPPEDWINDOW,
		window_start_x, window_start_y,
		window_width, window_height,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Создание окна провалено!", "", MB_OK | MB_ICONERROR);
	}

	ShowWindow(hwnd, nCmdShow); // режимы отображения окна (свернуть,на весь, и т.д)
	UpdateWindow(hwnd); // отрисовка окна

	//3) Запуск сообщение:
	MSG msg;
	while (GetMessage(&msg,NULL,0,0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hEdit = CreateWindowEx 
		(
			NULL, "Edit", "0",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
			10, 10,
			350, 22,
			hwnd,
			(HMENU)1000,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hButton0 = CreateWindowEx
		(
			NULL, "Button", "0",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			100, 420,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_0,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hButton1 = CreateWindowEx
		(
			NULL, "Button", "1",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			40, 360,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_1,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton2 = CreateWindowEx
		(
			NULL, "Button", "2",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			100, 360,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_2,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton3 = CreateWindowEx
		(
			NULL, "Button", "3",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			160, 360,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_3,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton4 = CreateWindowEx
		(
			NULL, "Button", "4",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			40, 300,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_4,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton5 = CreateWindowEx
		(
			NULL, "Button", "5",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			100, 300,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_5,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton6 = CreateWindowEx
		(
			NULL, "Button", "6",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			160, 300,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_6,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton7 = CreateWindowEx
		(
			NULL, "Button", "7",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			40, 240,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_7,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton8 = CreateWindowEx
		(
			NULL, "Button", "8",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			100, 240,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_8,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButton9 = CreateWindowEx
		(
			NULL, "Button", "9",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			160, 240,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_9,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonPoint = CreateWindowEx
		(
			NULL, "Button", ".",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			160, 420,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_POINT,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonMinus = CreateWindowEx
		(
			NULL, "Button", "-",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 240,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_MINUS,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonAster = CreateWindowEx
		(
			NULL, "Button", "*",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 360,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_ASTER,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonSlash = CreateWindowEx
		(
			NULL, "Button", "/",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 300,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_SLASH,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonPlus = CreateWindowEx
		(
			NULL, "Button", "+",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 180,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_PLUS,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonBsp = CreateWindowEx
		(
			NULL, "Button", "<-",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 120,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_BSP,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hButtonEqual = CreateWindowEx
		(
			NULL, "Button", "=",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON | BS_CENTER,
			240, 420,
			50, 50,
			hwnd,
			(HMENU)IDC_BUTTON_EQUAL,
			GetModuleHandle(NULL),
			NULL
		);

	}
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}