#include "Core.h"
#include "Artist.h"
#include "NullArtist.h"
#include "MenuManager.h"
#include "FileManager.h"


static COLORREF color = RGB(0, 0, 0);
static Artist *artist = new NullArtist();
static FileManager *fileManager = new FileManager();

static MenuManager menuManager(&artist, fileManager, &color);

using namespace std;

void attachConsole() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stderr);
}

LRESULT WINAPI WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp) {
    switch (m) {
    case WM_CREATE:
        menuManager.setMenu(hwnd);
        break;
    case WM_COMMAND:
        menuManager.handleInput(hwnd, wp);
        break;
    case WM_LBUTTONDOWN:
        {
            HDC hdc = GetDC(hwnd);
            int x = LOWORD(lp);
            int y = HIWORD(lp);

            artist->onMouseLeftDown(hdc, x, y);

            ReleaseDC(hwnd, hdc);
        }
        break;
    case WM_LBUTTONUP:
        {
            HDC hdc = GetDC(hwnd);
            int x = LOWORD(lp);
            int y = HIWORD(lp);

            artist->onMouseLeftUp(hdc, x, y);

            ReleaseDC(hwnd, hdc);
        }
        break;
    case WM_RBUTTONDOWN:
        {
            HDC hdc = GetDC(hwnd);
            int x = LOWORD(lp);
            int y = HIWORD(lp);

            artist->onMouseRightDown(hdc, x, y);

            ReleaseDC(hwnd, hdc);
        }
        break;
    case WM_RBUTTONUP:
        {
            HDC hdc = GetDC(hwnd);
            int x = LOWORD(lp);
            int y = HIWORD(lp);

            artist->onMouseRightUp(hdc, x, y);

            ReleaseDC(hwnd, hdc);
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, m, wp, lp);
    }
    return 0;
}

int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns)
{
    attachConsole();
    
    WNDCLASS wc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hInstance = hi;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = LPCSTR("MyClass");
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(LPCSTR("MyClass"), LPCSTR("Paint"), WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hi, 0);
    ShowWindow(hwnd, ns);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
