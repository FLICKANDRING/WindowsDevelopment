#include <Windows.h>
#include "resource.h"

//#define MESSAGE_BOX

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	/* 
	--------------------
	WinMain 
	hInstance - экземпляр нашего приложения в памяти (экземпляр *.exe - файла)
	hPrevInst - предидущий запущенный экземпляр (Deprecated, использовался в Windows 98)
	LPSTR lpCmdLine:
	LPSTR - LongPointer to String (Указатель на строку наподобие const char*)
	lpCmdLine - коммандная строка запуска приложения 
	nCmdShow - режим отображения окна: Свернуто в окно, Развернуто на весь экран, Свернуто в панель задач.....
	--------------------
	(WndProc) Процедура окна (DlgProc) - Самая обычная функция, которая НЕявно вызывается при любом обращении, к определеному окну.
	ПРОЦЕДУРА - ЭТО ФУНКЦИЯ
	--------------------
	Любая процедура окна всегда принимает 4 параметра:
	-------------------
	hwnd (Handler to Window) - Окно. Оработчик окна - это число через которое можно обратиться к окну.
	-------------------
	uMsg - сообщение, отправляемое окну.
	--------------------
	wParam, lParam - параметры сообщения - это сопровождающая инфо поступающая в окно вместе с сообщением
	--------------------
	Например: с сообщением WM_COMMAND: wParam всегда приходит дочерний элемент окна, который сгенерировал сообщение WM_COMMAND
	--------------------
	WPARAM and LPARAM - представляют собой целочисленное значение типа int(DWORD-Double Word)
	HIWORD - старшее слово
	LOWORD - младшее слово
	\\\\\\\\\\\\\\\\\\\\\
	Слово (WORD) = 2 Байта
	----------------------

	*/
#ifdef MESSAGE_BOX
	MessageBox(
		NULL,
		"Hello WinAPI!\nЭто окно сообщения",
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
	/*(WndProc)Процедура окна(DlgProc) - Самая обычная функция, которая НЕявно вызывается при любом обращении, к определеному окну.
		ПРОЦЕДУРА - ЭТО ФУНКЦИЯ
		--------------------
		Любая процедура окна всегда принимает 4 параметра:
		-------------------
		hwnd (Handler to Window) - Окно. Оработчик окна - это число через которое можно обратиться к окну.
		-------------------
		uMsg - сообщение, отправляемое окну.
		--------------------
		wParam, lParam - параметры сообщения - это сопровождающая инфо поступающая в окно вместе с сообщением
		--------------------
		Например: с сообщением WM_COMMAND: wParam всегда приходит дочерний элемент окна, который сгенерировал сообщение WM_COMMAND
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
		case IDOK: MessageBox(hwnd, "Была нажата кнопка ОК", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}