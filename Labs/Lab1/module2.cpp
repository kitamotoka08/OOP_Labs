#include "framework.h"
#include <math.h>
#include "module2.h"
INT_PTR CALLBACK Robota2_Window2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    HWND hWndParent = GetWindow(hDlg, GW_OWNER);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            ShowWindow(hWndParent, SW_SHOW);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDBack)
        {
            EndDialog(hDlg, LOWORD(wParam));
            DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_Work2_DIALOG1), hWndParent, Robota2_Window1);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Robota2_Window1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    HWND hWndParent = GetWindow(hDlg, GW_OWNER);
    switch (message)
    {
    case WM_INITDIALOG :
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            ShowWindow(hWndParent, SW_SHOW);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDNext)
        {
            EndDialog(hDlg, LOWORD(wParam));
            DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_Work2_DIALOG2), hWndParent, Robota2_Window2);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

