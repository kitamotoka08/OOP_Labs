#include "framework.h"
#include <math.h>
#include "module1.h"


INT_PTR CALLBACK Robota1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    int pos = 0;
    HWND hWndParent = GetWindow(hDlg, GW_OWNER);

    switch (message)
    {
    case WM_INITDIALOG:
    {
        HWND hScroll = GetDlgItem(hDlg, IDC_SCROLLBAR1);
        SetScrollRange(hScroll, SB_CTL, 0, 100, FALSE);
        SetScrollPos(hScroll, SB_CTL, 0, TRUE);
        SetDlgItemInt(hDlg, IDC_STATIC, 0, TRUE);
        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
			ShowWindow(hWndParent, SW_SHOW);
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDOK)
        {
            HWND hScroll = GetDlgItem(hDlg, IDC_SCROLLBAR1);
            PostMessage(hWndParent, WM_MY_CUSTOM_MESSAGE_FROM_ROBOTA1, GetScrollPos(hScroll, SB_CTL), 0);
            EndDialog(hDlg, LOWORD(wParam));
            ShowWindow(hWndParent, SW_SHOW);
            return (INT_PTR)TRUE;
        }
        break;
    }
    case WM_HSCROLL: {
        HWND hScroll = GetDlgItem(hDlg, IDC_SCROLLBAR1);
        pos = GetScrollPos(hScroll, SB_CTL);
        switch (LOWORD(wParam))
        {
        case SB_LINELEFT:
        case SB_PAGELEFT:
            pos--;
            break;
        case SB_PAGERIGHT:
        case SB_LINERIGHT:
            pos++;
            break;
        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            pos = HIWORD(wParam);
            break;
        }
        SetScrollPos(hScroll, SB_CTL, pos, TRUE);
        SetDlgItemInt(hDlg, IDC_STATIC, pos, TRUE);
    }
    }
    return (INT_PTR)FALSE;
}