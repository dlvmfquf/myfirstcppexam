#include "pch.h"


//전역변수:
HINSTANCE	_hInstance;
HWND		_hWnd;

ATOM		MyRegisterClass(HINSTANCE hInstance);
BOOL		InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT		WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// 1. 윈도우클래스를 등록
	MyRegisterClass(hInstance);

	// 2. 윈도우를 생성
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 3. 윈도우 메세지 루프
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = _T("GameClient");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return ::RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;

	HWND hWnd = CreateWindowW(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}
int dan = 0;
int numberOfDan = 1;
int x = 500;
int y = 100;
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	
		//윈도우가 생성되었을 떄 발생하는 이벤트
		// 여기에서 초기화
	
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
			printf("1번키를 눌렀다. \n");
			dan = 1;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '2':
			printf("2번키를 눌렀다. \n");
			dan = 2;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '3':
			printf("3번키를 눌렀다. \n");
			dan = 3;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '4':
			printf("4번키를 눌렀다. \n");
			dan = 4;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '5':
			printf("5번키를 눌렀다. \n");
			dan = 5;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '6':
			printf("6번키를 눌렀다. \n");
			dan = 6;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '7':
			printf("7번키를 눌렀다. \n");
			dan = 7;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '8':
			printf("8번키를 눌렀다. \n");
			dan = 8;
			numberOfDan = 1;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '9':
			printf("9번키를 눌렀다. \n");
			dan = 9;
			numberOfDan = 1; 
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		case '0':
			printf("0번키를 눌렀다. \n");
			dan = 9;
			numberOfDan = 9;
			y = 100;
			::InvalidateRect(hWnd, nullptr, true);
			break;
		default:
			break;
		}

	case WM_PAINT:
	{
		//화면을 그리는 이벤트
		// 시작했을때 호출한번 되고 InvalidRect 라는 함수가 호출 됐을 때 한번 실행 

		PAINTSTRUCT ps;
		HDC hdc = ::BeginPaint(hWnd, &ps);


		//wchar* 형태로 만들어주기 위해서는
		//str.c_str()
		if (numberOfDan == 1)
		{
			
			wchar_t str[100];
			for (int i = 1; i <= 9; i++)
			{
				/*if (i )
				wsprintf(str, L"%d * %d = %d", i, j, i * j);
				::TextOut(hdc, 100 + 100 * i, 30 + 100 * j, str, lstrlenW(str));*/

				wstring str = format(L"{} x {} = {}", dan, i, i * dan);

				y += 50;
				::TextOut(hdc, x, y, str.c_str(), str.length());

			}
			//wstring str1 = format(L"안녕하세요{}", i);

		
		}

		else if (numberOfDan == 9)
		{
			for (int i = 1; i <= numberOfDan; i++)
			{
				wchar_t str[100];
				for (int j = 1; j <= numberOfDan; j++)
				{
					/*if (i )
					wsprintf(str, L"%d * %d = %d", i, j, i * j);
					::TextOut(hdc, 100 + 100 * i, 30 + 100 * j, str, lstrlenW(str));*/

					wstring str = format(L"{} x {} = {}", i, j, i * j);
					int x = 100 + ((i - 1) % 3) * 200;
					int y = 20 + ((i - 1) / 3) * 250;


					y += j * 20;
					::TextOut(hdc, x, y, str.c_str(), str.length());

				}
			}
		}

		//for (int i = 1; i <= dan; i++)
		//{
		//	wchar_t str[100];
		//	for (int j = dan-1; j <= numberOfDan; j++)
		//	{
		//		/*if (i )
		//		wsprintf(str, L"%d * %d = %d", i, j, i * j);
		//		::TextOut(hdc, 100 + 100 * i, 30 + 100 * j, str, lstrlenW(str));*/

		//		wstring str = format(L"{} x {} = {}", i, j, i * j);
		//		int x = 100 + ((i - 1) % 3) * 200;
		//		int y = 20 + ((i - 1) / 3) * 250;


		//		y += j * 20;
		//		::TextOut(hdc, x, y, str.c_str(), str.length());

		//	}
		//	//wstring str1 = format(L"안녕하세요{}", i);

		//}

		//Draw::Rectangle(hdc, 10, 10, 100, 100);

		////원그리기
		//Draw::Ellipse(hdc, 500, 500, 600, 600);

		::EndPaint(hWnd, &ps);


	}
		break;
	case WM_DESTROY:
	//윈도우 종료 메세지가 왔을 떄 발생되는 이벤트
		::PostQuitMessage(0);
	
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}