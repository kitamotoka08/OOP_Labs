#pragma once
#include <windows.h>

class Shape {
protected:
    long xs1, ys1, xs2, ys2;
public:
    Shape() : xs1(0), ys1(0), xs2(0), ys2(0) {}
    virtual ~Shape() {}

    void Set(long x1, long y1, long x2, long y2) {
        xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
    }

    virtual void Draw(HDC hdc) = 0;
    virtual void DrawRubber(HDC hdc) = 0;
};

class PointShape : public Shape {
public:
    void Draw(HDC hdc) override;
    void DrawRubber(HDC hdc) override;
};

class LineShape : public Shape {
public:
    void Draw(HDC hdc) override;
    void DrawRubber(HDC hdc) override;
};

class RectShape : public Shape {
public:
    void Draw(HDC hdc) override;
    void DrawRubber(HDC hdc) override;
};

class EllipseShape : public Shape {
public:
    void Draw(HDC hdc) override;
    void DrawRubber(HDC hdc) override;
};
