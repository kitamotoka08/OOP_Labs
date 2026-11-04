#include "shape.h"

void PointShape::Draw(HDC hdc) {
    SetPixel(hdc, xs1, ys1, RGB(0, 0, 0));
}
void PointShape::DrawRubber(HDC hdc) {
    SetPixel(hdc, xs2, ys2, RGB(255, 0, 0));
}

void LineShape::Draw(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
}
void LineShape::DrawRubber(HDC hdc) {
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);
}

void RectShape::Draw(HDC hdc) {
    int left = 2 * xs1 - xs2;
    int top = 2 * ys1 - ys2;
    int right = xs2;
    int bottom = ys2;

    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); 
    HBRUSH hBrush = CreateSolidBrush(RGB(144, 238, 144));

    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(hdc, left, top, right, bottom);

    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}
void RectShape::DrawRubber(HDC hdc) {
    int left = 2 * xs1 - xs2;
    int top = 2 * ys1 - ys2;
    Rectangle(hdc, left, top, xs2, ys2);
}

void EllipseShape::Draw(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);

    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Ellipse(hdc, xs1, ys1, xs2, ys2);

    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
}
void EllipseShape::DrawRubber(HDC hdc) {
    Ellipse(hdc, xs1, ys1, xs2, ys2);
}