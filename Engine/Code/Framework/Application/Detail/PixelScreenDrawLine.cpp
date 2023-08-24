///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 16:36)

#include "Framework/FrameworkExport.h"

#include "PixelScreenDrawLine.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::PixelScreenDrawLine::PixelScreenDrawLine(int xMin, int yMin, int xMax, int yMax)
    : xMin{ xMin },
      yMin{ yMin },
      xMax{ xMax },
      yMax{ yMax },
      distanceX{ xMax - xMin },
      distanceY{ yMax - yMin },
      stepX{ 0 < distanceX ? 1 : (distanceX < 0 ? -1 : 0) },
      stepY{ 0 < distanceY ? 1 : (distanceY < 0 ? -1 : 0) },
      line{}
{
    Calculate();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

void Framework::PixelScreenDrawLine::Calculate()
{
    // 像素决定参数的选择。
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    if (distanceY < 0)
    {
        distanceY = -distanceY;
    }

    // 使用有关的变量确定单步的最大方向分量。 使用Bresenham算法遍历线段。
    if (distanceY < distanceX)
    {
        DrawLineOnX();
    }
    else
    {
        DrawLineOnY();
    }
}

void Framework::PixelScreenDrawLine::DrawLineOnX()
{
    const auto twiceDistanceX = 2 * distanceX;
    const auto twiceDistanceY = 2 * distanceY;
    auto x = xMin;
    auto y = yMin;
    line.emplace_back(x, y);

    auto decY = twiceDistanceY - distanceX;
    while (x != xMax)
    {
        if (0 <= decY)
        {
            decY -= twiceDistanceX;
            y += stepY;
        }

        x += stepX;
        decY += twiceDistanceY;

        // 处理像素。
        line.emplace_back(x, y);
    }
}

void Framework::PixelScreenDrawLine::DrawLineOnY()
{
    const auto twiceDistanceX = 2 * distanceX;
    const auto twiceDistanceY = 2 * distanceY;
    auto x = xMin;
    auto y = yMin;
    line.emplace_back(x, y);

    auto decX = twiceDistanceX - distanceY;
    while (y != yMax)
    {
        if (0 <= decX)
        {
            decX -= twiceDistanceY;
            x += stepX;
        }

        y += stepY;
        decX += twiceDistanceX;

        // 处理像素。
        line.emplace_back(x, y);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::PixelScreenDrawLine::IsValid() const noexcept
{
    return CoreTools::Noexcept<bool, ClassType>(*this, &ClassType::IsEndpointCorrect, false);
}

bool Framework::PixelScreenDrawLine::IsEndpointCorrect() const
{
    if (line.empty())
    {
        return false;
    }
    else
    {
        if (const auto iter = line.cbegin();
            iter->GetWindowX() != xMin || iter->GetWindowY() != yMin)
        {
            return false;
        }

        if (const auto reverseIter = line.crbegin();
            reverseIter->GetWindowX() != xMax || reverseIter->GetWindowY() != yMax)
        {
            return false;
        }
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

int Framework::PixelScreenDrawLine::GetSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(line.size());
}

const Framework::WindowPoint& Framework::PixelScreenDrawLine::operator[](int index) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return line.at(index);
}