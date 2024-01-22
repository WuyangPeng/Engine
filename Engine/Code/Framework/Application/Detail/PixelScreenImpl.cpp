/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:27)

#include "Framework/FrameworkExport.h"

#include "PixelScreenDrawLine.h"
#include "PixelScreenImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

Framework::PixelScreenImpl::PixelScreenImpl(const WindowSize& size)
    : screenWidth{ size.GetWindowWidth() }, screenHeight{ size.GetWindowHeight() }, screen{}, doFlip{ false }
{
    const auto screenSize = screenWidth * screenHeight;
    screen.resize(screenSize);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::PixelScreenImpl::IsValid() const noexcept
{
    return CoreTools::Noexcept<bool, ClassType>(*this, &ClassType::IsScreenSizeValid, false);
}

bool Framework::PixelScreenImpl::IsScreenSizeValid() const
{
    if (0 < screenWidth && 0 < screenHeight && boost::numeric_cast<int>(screen.size()) == screenWidth * screenHeight)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::PixelScreenImpl::Resize(const WindowSize& size, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto width = size.GetWindowWidth();
    const auto height = size.GetWindowHeight();

    if (width != screenWidth || height != screenHeight)
    {
        screenWidth = width;
        screenHeight = height;
        const auto screenSize = screenWidth * screenHeight;
        screen.resize(screenSize);
    }

    ClearScreen(color);
}

void Framework::PixelScreenImpl::ClearScreen(const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto screenSize = screenWidth * screenHeight;
    screen.assign(screenSize, color);
}

void Framework::PixelScreenImpl::DoFlip(bool aDoFlip) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doFlip = aDoFlip;
}

bool Framework::PixelScreenImpl::IsDoFlip() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return doFlip;
}

void Framework::PixelScreenImpl::SetPixel(int x, int y, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_ASSERTION_1(0 <= x && x < screenWidth && 0 <= y && y < screenHeight, "数组索引越界！");

    const auto index = x + screenWidth * y;
    screen.at(index) = color;
}

void Framework::PixelScreenImpl::SetThickPixel(int x, int y, int thick, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto xMin = std::max(x - thick, 0);
    const auto xMax = std::min(x + thick, screenWidth - 1);
    const auto yMin = std::max(y - thick, 0);
    const auto yMax = std::min(y + thick, screenHeight - 1);

    for (auto yThick = yMin; yThick <= yMax; ++yThick)
    {
        SetLineOnX(xMin, xMax, yThick, color);
    }
}

Framework::PixelScreenImpl::Colour Framework::PixelScreenImpl::GetPixel(int x, int y) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;
    FRAMEWORK_ASSERTION_1(0 <= x && x < screenWidth && 0 <= y && y < screenHeight, "数组索引越界！");

    const auto index = x + screenWidth * y;
    return screen.at(index);
}

void Framework::PixelScreenImpl::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const PixelScreenDrawLine line{ xMin, yMin, xMax, yMax };

    const auto size = line.GetSize();

    for (auto i = 0; i < size; ++i)
    {
        const auto& point = line[i];

        // 处理像素。
        SetPixel(point.GetWindowX(), point.GetWindowY(), color);
    }
}

void Framework::PixelScreenImpl::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_ASSERTION_3(0 <= xMin && xMin <= xMax && xMax < screenWidth, "矩形不是有效的！");
    FRAMEWORK_ASSERTION_3(0 <= yMin && yMin <= yMax && yMax < screenHeight, "矩形不是有效的！");

    if (xMin == xMax || yMin == yMax)
    {
        DrawLine(xMin, yMin, xMax, yMax, color);
    }
    else if (solid)
    {
        for (auto y = yMin; y <= yMax; ++y)
        {
            SetLineOnX(xMin, xMax, y, color);
        }
    }
    else
    {
        SetLineOnX(xMin, xMax, yMin, color);
        SetLineOnX(xMin, xMax, yMax, color);
        if (yMin + 1 <= yMax - 1)
        {
            SetLineOnY(xMin, yMin + 1, yMax - 1, color);
            SetLineOnY(xMax, yMin + 1, yMax - 1, color);
        }
    }
}

void Framework::PixelScreenImpl::DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (solid)
    {
        DrawSolidCircle(xCenter, yCenter, radius, color);
    }
    else
    {
        DrawHollowCircle(xCenter, yCenter, radius, color);
    }
}

void Framework::PixelScreenImpl::DrawSolidCircle(int xCenter, int yCenter, int radius, const Colour& color)
{
    auto dec = 3 - 2 * radius;

    for (auto x = 0, y = radius; x <= y; ++x)
    {
        DoDrawSolidCircle1(xCenter, yCenter, x, y, color);
        DoDrawSolidCircle2(xCenter, yCenter, x, y, color);

        if (0 <= dec)
        {
            dec += -4 * y + 4;
            --y;
        }
        dec += 4 * x + 6;
    }
}

void Framework::PixelScreenImpl::DoDrawSolidCircle1(int xCenter, int yCenter, int x, int y, const Colour& color)
{
    const auto yMin = std::max(yCenter - y, 0);
    const auto yMax = std::min(yCenter + y, screenHeight - 1);

    if (const auto xCenterPlusX = xCenter + x;
        xCenterPlusX < screenWidth)
    {
        SetLineOnY(xCenterPlusX, yMin, yMax, color);
    }

    if (const auto xCenterMinusX = xCenter - x;
        0 <= xCenterMinusX)
    {
        SetLineOnY(xCenterMinusX, yMin, yMax, color);
    }
}

void Framework::PixelScreenImpl::DoDrawSolidCircle2(int xCenter, int yCenter, int x, int y, const Colour& color)
{
    const auto yMin = std::max(yCenter - x, 0);
    const auto yMax = std::min(yCenter + x, screenHeight - 1);

    if (const auto xCenterPlusY = xCenter + y;
        xCenterPlusY < screenWidth)
    {
        SetLineOnY(xCenterPlusY, yMin, yMax, color);
    }

    if (const auto xCenterMinusY = xCenter - y;
        0 <= xCenterMinusY)
    {
        SetLineOnY(xCenterMinusY, yMin, yMax, color);
    }
}

void Framework::PixelScreenImpl::DrawHollowCircle(int xCenter, int yCenter, int radius, const Colour& color)
{
    auto dec = 3 - 2 * radius;
    for (auto x = 0, y = radius; x <= y; ++x)
    {
        const auto xCenterMinusX = xCenter - x;
        const auto xCenterPlusX = xCenter + x;
        const auto xCenterMinusY = xCenter - y;
        const auto xCenterPlusY = xCenter + y;

        const auto yCenterMinusX = yCenter - x;
        const auto yCenterPlusX = yCenter + x;
        const auto yCenterMinusY = yCenter - y;
        const auto yCenterPlusY = yCenter + y;

        if (xCenterPlusX < screenWidth && yCenterPlusY < screenHeight)
        {
            SetPixel(xCenterPlusX, yCenterPlusY, color);
        }

        if (xCenterPlusX < screenWidth && 0 <= yCenterMinusY)
        {
            SetPixel(xCenterPlusX, yCenterMinusY, color);
        }

        if (0 <= xCenterMinusX && yCenterPlusY < screenHeight)
        {
            SetPixel(xCenterMinusX, yCenterPlusY, color);
        }

        if (0 <= xCenterMinusX && 0 <= yCenterMinusY)
        {
            SetPixel(xCenterMinusX, yCenterMinusY, color);
        }

        if (xCenterPlusY < screenWidth && yCenterPlusX < screenHeight)
        {
            SetPixel(xCenterPlusY, yCenterPlusX, color);
        }

        if (xCenterPlusY < screenWidth && 0 <= yCenterMinusX)
        {
            SetPixel(xCenterPlusY, yCenterMinusX, color);
        }

        if (0 <= xCenterMinusY && yCenterPlusX < screenHeight)
        {
            SetPixel(xCenterMinusY, yCenterPlusX, color);
        }

        if (0 <= xCenterMinusY && 0 <= yCenterMinusX)
        {
            SetPixel(xCenterMinusY, yCenterMinusX, color);
        }

        if (0 <= dec)
        {
            dec += -4 * y + 4;
            --y;
        }
        dec += 4 * x + 6;
    }
}

void Framework::PixelScreenImpl::Fill(int x, int y, const Colour& foreColor, const Colour& backColor)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    // 分配所需的最大空间数量。如果你喜欢分配更少的空间，
    // 你需要修改这个数据结构，以便在需要时动态重新分配。
    // 空堆栈顶部有top == -1。
    const auto xMax = screenWidth;
    const auto yMax = screenHeight;
    const auto stackSize = xMax * yMax;
    std::vector<int> xStack(stackSize);
    std::vector<int> yStack(stackSize);

    // 如果它是背景颜色，把种子点压入堆栈。背景颜色backColor的所有点压入到堆栈。
    auto top = 0;
    xStack.at(top) = x;
    yStack.at(top) = y;

    while (0 <= top)  // 堆栈不是空的
    {
        // 读堆栈的顶部。不要弹出它，因为在后面我们需要返回这个顶值，并在不同的方向重新填充。
        x = xStack.at(top);
        y = yStack.at(top);

        // 填充像素
        SetPixel(x, y, foreColor);

        if (const auto xPlus1 = x + 1;
            xPlus1 < xMax && GetPixel(xPlus1, y) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack.at(top) = xPlus1;
            yStack.at(top) = y;
            continue;
        }

        if (const auto xMinus1 = x - 1;
            0 <= xMinus1 && GetPixel(xMinus1, y) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack.at(top) = xMinus1;
            yStack.at(top) = y;
            continue;
        }

        if (const auto yPlus1 = y + 1;
            yPlus1 < yMax && GetPixel(x, yPlus1) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack.at(top) = x;
            yStack.at(top) = yPlus1;
            continue;
        }

        if (const auto yMinus1 = y - 1;
            0 <= yMinus1 && GetPixel(x, yMinus1) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack.at(top) = x;
            yStack.at(top) = yMinus1;
            continue;
        }

        // 我们正在做各个方向，所以弹出，并返回到搜索其他方向。
        --top;
    }
}

void Framework::PixelScreenImpl::SetLineOnX(int xMin, int xMax, int y, const Colour& color)
{
    FRAMEWORK_ASSERTION_1(0 <= xMin && xMin <= xMax && xMax < screenWidth && 0 <= y && y < screenHeight, "数组索引越界！");

    for (auto x = xMin; x <= xMax; ++x)
    {
        SetPixel(x, y, color);
    }
}

void Framework::PixelScreenImpl::SetLineOnY(int x, int yMin, int yMax, const Colour& color)
{
    FRAMEWORK_ASSERTION_1(0 <= x && x < screenWidth && 0 <= yMin && yMin <= yMax && yMax < screenHeight, "数组索引越界！");

    for (auto y = yMin; y <= yMax; ++y)
    {
        SetPixel(x, y, color);
    }
}

int Framework::PixelScreenImpl::GetScreenWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return screenWidth;
}

int Framework::PixelScreenImpl::GetScreenHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return screenHeight;
}
