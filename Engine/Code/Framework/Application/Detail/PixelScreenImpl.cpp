// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:18)

#include "Framework/FrameworkExport.h"

#include "PixelScreenImpl.h"
#include "PixelScreenDrawLine.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <vector>

using std::vector;

Framework::PixelScreenImpl
	::PixelScreenImpl(const WindowSize& size)
	:m_ScreenWidth(size.GetWindowWidth()),
	 m_ScreenHeight(size.GetWindowHeight()),
     m_Screen(m_ScreenWidth * m_ScreenHeight),
     m_DoFlip(false)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::PixelScreenImpl
	::IsValid() const noexcept
{
    if(0 < m_ScreenWidth && 0 < m_ScreenHeight &&
       static_cast<int>(m_Screen.size()) == m_ScreenWidth * m_ScreenHeight)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::PixelScreenImpl
	::Resize( const WindowSize& size,const Colour& color )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int width = size.GetWindowWidth();
	int height = size.GetWindowHeight();

    if (width != m_ScreenWidth || height != m_ScreenHeight)
    {
        m_ScreenWidth = width;
        m_ScreenHeight = height;
        m_Screen.resize(m_ScreenWidth * m_ScreenHeight);

		ClearScreen(color);
    } 
}
 
void Framework::PixelScreenImpl
	::Draw(const Rendering::RendererSmartPointer& renderer)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	Rendering::RendererSmartPointer copyRenderer = renderer;

	copyRenderer->Draw(reinterpret_cast<const unsigned char*>(&m_Screen[0]),m_DoFlip);
}

void Framework::PixelScreenImpl
	::ClearScreen (const Colour& color)
{
	FRAMEWORK_CLASS_IS_VALID_1;

    m_Screen.assign(m_ScreenWidth * m_ScreenHeight, Colour(color));
}

void Framework::PixelScreenImpl
	::DoFlip (bool doFlip)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_DoFlip = doFlip;
}

void Framework::PixelScreenImpl
	::SetPixel (int x, int y, const Colour& color)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_0(0 <= x && x < m_ScreenWidth && 0 <= y && y < m_ScreenHeight,"数组索引越界！");

    m_Screen[x + m_ScreenWidth * y] = color;
}

void Framework::PixelScreenImpl
	::SetThickPixel (int x, int y, int thick, const Colour& color)
{
	FRAMEWORK_CLASS_IS_VALID_1;

    for (int dy = -thick; dy <= thick; ++dy)
    {
        for (int dx = -thick; dx <= thick; ++dx)
        {
			if (0 <= x + dx && x + dx < m_ScreenWidth && 0 <= y + dy && y + dy < m_ScreenHeight)
			{
				SetPixel(x + dx, y + dy, color);
			}			
        }
    }
}


const Framework::PixelScreenImpl::Colour Framework::PixelScreenImpl
	::GetPixel (int x, int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;
	FRAMEWORK_ASSERTION_0(0 <= x && x < m_ScreenWidth && 0 <= y && y < m_ScreenHeight, "数组索引越界！");

    return m_Screen[x + m_ScreenWidth * y];
}


void  Framework::PixelScreenImpl
	::DrawLine (int beginX, int beginY, int endX, int endY, 
                const Colour& color)
{
	FRAMEWORK_CLASS_IS_VALID_1;

    PixelScreenDrawLine line(beginX, beginY, endX, endY);

    int size = line.GetSize();

    for (int i = 0; i < size; ++i)
    {
         WindowPoint point = line[i];

         // 处理像素。
         SetPixel(point.GetWindowX(), point.GetWindowY(), color);
    }
}

void  Framework::PixelScreenImpl
	::DrawRectangle (int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid)
{
	FRAMEWORK_CLASS_IS_VALID_1;

    if (m_ScreenWidth <= xMin || xMax < 0 ||   m_ScreenHeight <= yMin || yMax < 0)
    {
        // 矩形不是有效的。
        return;
    }

    if (solid)
    {
        for (int  y = yMin; y <= yMax; ++y)
        {
            for (int x = xMin; x <= xMax; ++x)
            {
                SetPixel(x, y, color);
            }
        }
    }
    else
    {
        for (int x = xMin; x <= xMax; ++x)
        {
            SetPixel(x, yMin, color);
            SetPixel(x, yMax, color);
        }
        for (int y = yMin + 1; y <= yMax - 1; ++y)
        {
            SetPixel(xMin, y, color);
            SetPixel(xMax, y, color);
        }
    }

}

void  Framework::PixelScreenImpl
	::DrawCircle (int xCenter, int yCenter, int radius, const Colour& color,  bool solid)
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

void  Framework::PixelScreenImpl
	::DrawSolidCircle (int xCenter, int yCenter, int radius,  const Colour& color)
{
	int dec = 3 - 2 * radius;

    for (int x = 0, y = radius; x <= y; ++x)
    {
        int xValue = xCenter + x;
        int yMin = yCenter - y;
        int yMax = yCenter + y;
        for (int i = yMin; i <= yMax; ++i)
        {
            SetPixel(xValue, i, color);
        }

        xValue = xCenter - x;
        for (int i = yMin; i <= yMax; ++i)
        {
            SetPixel(xValue, i, color);
        }

        xValue = xCenter + y;
        yMin = yCenter - x;
        yMax = yCenter + x;
        for (int i = yMin; i <= yMax; ++i)
        {
            SetPixel(xValue, i, color);
        }

        xValue = xCenter - y;
        for (int i = yMin; i <= yMax; ++i)
        {
            SetPixel(xValue, i, color);
        }

        if (0 <= dec)
        {
            dec += -4 * y + 4;
			--y;
        }
        dec += 4 * x + 6;
    }
}

void  Framework::PixelScreenImpl
	::DrawHollowCircle (int xCenter, int yCenter, int radius,  const Colour& color)
{
	int dec = 3 - 2 * radius;
    for (int x = 0, y = radius; x <= y; ++x)
    {
        SetPixel(xCenter + x, yCenter + y, color);
        SetPixel(xCenter + x, yCenter - y, color);
        SetPixel(xCenter - x, yCenter + y, color);
        SetPixel(xCenter - x, yCenter - y, color);
        SetPixel(xCenter + y, yCenter + x, color);
        SetPixel(xCenter + y, yCenter - x, color);
        SetPixel(xCenter - y, yCenter + x, color);
        SetPixel(xCenter - y, yCenter - x, color);

        if (0 <= dec)
        {
            dec += -4 * y + 4;
			--y;
        }
        dec += 4 * x + 6;
    }
}

void  Framework::PixelScreenImpl
	::Fill (int x, int y, const Colour& foreColor, const Colour& backColor)
{
	FRAMEWORK_CLASS_IS_VALID_1;

    // 分配所需的最大空间数量。如果你喜欢分配更少的空间，
    // 你需要修改这个数据结构，以便在需要时动态重新分配。
    // 空堆栈顶部有top == -1。
    int xMax = m_ScreenWidth;
    int yMax = m_ScreenHeight;
    int stackSize = xMax * yMax;
    vector<int> xStack(stackSize);
    vector<int> yStack(stackSize);

    // 如果它是背景颜色，把种子点压入堆栈。背景颜色backColor的所有点压入到堆栈。
    int top = 0;
    xStack[top] = x;
    yStack[top] = y;

    while (0 <= top)  // 堆栈不是空的
    {
        // 读堆栈的顶部。不要弹出它，因为在后面我们需要返回这个顶值，并在不同的方向重新填充。
        x = xStack[top];
        y = yStack[top];

        // 填充像素
        SetPixel(x, y, foreColor);

        int xPlus1 = x + 1;
        if (xPlus1 < xMax && GetPixel(xPlus1, y) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack[top] = xPlus1;
            yStack[top] = y;
            continue;
        }

        int xMinus1 = x - 1;
        if (0 <= xMinus1 && GetPixel(xMinus1, y) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack[top] = xMinus1;
            yStack[top] = y;
            continue;
        }

        int yPlus1 = y + 1;
        if (yPlus1 < yMax && GetPixel(x, yPlus1) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack[top] = x;
            yStack[top] = yPlus1;
            continue;
        }

        int yMinus1 = y - 1;
        if (0 <= yMinus1 && GetPixel(x, yMinus1) == backColor)
        {
            // 推出像素使用背景色。
            ++top;
            xStack[top] = x;
            yStack[top] = yMinus1;
            continue;
        }

        // 我们正在做各个方向，所以弹出，并返回到搜索其他方向。
        --top;
    } 
}

bool Framework::PixelScreenImpl
	::IsDoFlip() const 
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_DoFlip;
}

