#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include "resource.h"

CONST CHAR g_sz_WINDOW_CLASS[] = "My Main Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	// 1) ����������� ������ ����:
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(wClass));

	wClass.style = 0;
	wClass.cbSize = sizeof(wClass);
	wClass.cbClsExtra = 0;
	wClass.cbWndExtra = 0;    // cb... - CountBytes;

	wClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE (IDI_ICON_COMPUTER));
	wClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE (IDI_ICON_FOLDER));

	//wClass.hIcon = 
		//(HICON)LoadImage(hInstance, "Ico\\computer_screen_icon_231558.ico",IMAGE_ICON,LR_DEFAULTSIZE,LR_DEFAULTSIZE,LR_LOADFROMFILE);
		
	//wClass.hIconSm = 
		//(HICON)LoadImage(hInstance, "Ico\\folder_icon_231576.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
		
	//wClass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE (IDC_CURSOR1)); // ������������ ��������������� ��� �� � ������


	wClass.hCursor = (HCURSOR)LoadImage(hInstance, "Cursors\\Call of Duty Simon Ghost & Knife Animated--cursor--SweezyCursors.ani",
		IMAGE_CURSOR, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE); // �������� ������� �� �����!
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wClass.hInstance = hInstance;
	wClass.lpszMenuName = NULL;
	wClass.lpszClassName = g_sz_WINDOW_CLASS;
	wClass.lpfnWndProc = (WNDPROC)WndProc;

	if (!RegisterClassEx(&wClass))
	{
		MessageBox(NULL, "Class registration failed", "", MB_OK | MB_ICONERROR);
		return 0;
	}


	// 2) �������� ����:
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT sreen_heigth = GetSystemMetrics(SM_CYSCREEN);
	INT window_width = screen_width * 3 / 4;
	INT window_height = sreen_heigth * .75;
	INT window_start_x = screen_width / 8;
	INT window_start_y = sreen_heigth / 8;
	HWND hwnd = CreateWindowEx
	(
		NULL,							//Ex-Styles
		g_sz_WINDOW_CLASS,				//Class name
		g_sz_WINDOW_CLASS,				//Window title
		WS_OVERLAPPEDWINDOW,			//Window style. ����� ����� ������ �������� ��� �������� ����.
		window_start_x, window_start_y,	//Position - ��������� ���� ��� �������
		window_width, window_height,	//Size     - ������ ������������ ����.
		NULL,
		NULL, //-------------------->	//hMenu:   - ��� �������� ���� ��� ResoureID �������� ����
										//��� ��������� ���� (�������� ������-�� ����) 
										//��� ResourseID ���������������� ��������.
										//�� ����� ResourseID ������� �������� ������ 
										//����� �������� ��� ������ ������� GetDlgItem()
		hInstance,
		NULL
	);

	// �������� �������� ����

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "", MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow); // ������ ����� ����������� ����(���������� �� ���� �����, �������� � ����, �������� �� ������ �����...)
	UpdateWindow(hwnd);			// ������������� ����.

	// 3) ������ ����� ���������:
	MSG msg;
	while (GetMessage(&msg,NULL,0,0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;


	return 0;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_MOVE:

	case WM_SIZE:
	{
		RECT window_rect;
		GetWindowRect(hwnd, &window_rect);
		INT window_width = window_rect.right - window_rect.left;
		INT window_heigt = window_rect.bottom - window_rect.top;

		CONST INT SIZE = 256;
		CHAR sz_title[SIZE]{};

		sprintf
		(
			sz_title, "%s. Position:%ix%i; Size: %ix%i",
			g_sz_WINDOW_CLASS,
			window_rect.left, window_rect.top,
			window_width, window_heigt
		);

		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
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
	return 0;

}