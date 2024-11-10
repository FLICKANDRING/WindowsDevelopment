#include <Windows.h>
#include "resource.h"

//#define MESSAGE_BOX

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	/* 
	--------------------
	WinMain 
	hInstance - ��������� ������ ���������� � ������ (��������� *.exe - �����)
	hPrevInst - ���������� ���������� ��������� (Deprecated, ������������� � Windows 98)
	LPSTR lpCmdLine:
	LPSTR - LongPointer to String (��������� �� ������ ��������� const char*)
	lpCmdLine - ���������� ������ ������� ���������� 
	nCmdShow - ����� ����������� ����: �������� � ����, ���������� �� ���� �����, �������� � ������ �����.....
	--------------------
	(WndProc) ��������� ���� (DlgProc) - ����� ������� �������, ������� ������ ���������� ��� ����� ���������, � ������������ ����.
	��������� - ��� �������
	--------------------
	����� ��������� ���� ������ ��������� 4 ���������:
	-------------------
	hwnd (Handler to Window) - ����. ��������� ���� - ��� ����� ����� ������� ����� ���������� � ����.
	-------------------
	uMsg - ���������, ������������ ����.
	--------------------
	wParam, lParam - ��������� ��������� - ��� �������������� ���� ����������� � ���� ������ � ����������
	--------------------
	��������: � ���������� WM_COMMAND: wParam ������ �������� �������� ������� ����, ������� ������������ ��������� WM_COMMAND
	--------------------
	WPARAM and LPARAM - ������������ ����� ������������� �������� ���� int(DWORD-Double Word)
	HIWORD - ������� �����
	LOWORD - ������� �����
	\\\\\\\\\\\\\\\\\\\\\
	����� (WORD) = 2 �����
	----------------------

	*/
#ifdef MESSAGE_BOX
	MessageBox(
		NULL,
		"Hello WinAPI!\n��� ���� ���������",
		"Question",
		MB_YESNOCANCEL | MB_ICONQUESTION
		| MB_HELP | MB_DEFBUTTON4
		| MB_SYSTEMMODAL
	);
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);

	return 0;
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/*(WndProc)��������� ����(DlgProc) - ����� ������� �������, ������� ������ ���������� ��� ����� ���������, � ������������ ����.
		��������� - ��� �������
		--------------------
		����� ��������� ���� ������ ��������� 4 ���������:
		-------------------
		hwnd (Handler to Window) - ����. ��������� ���� - ��� ����� ����� ������� ����� ���������� � ����.
		-------------------
		uMsg - ���������, ������������ ����.
		--------------------
		wParam, lParam - ��������� ��������� - ��� �������������� ���� ����������� � ���� ������ � ����������
		--------------------
		��������: � ���������� WM_COMMAND: wParam ������ �������� �������� ������� ����, ������� ������������ ��������� WM_COMMAND
		--------------------
	*/
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: MessageBox(hwnd, "���� ������ ������ ��", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}