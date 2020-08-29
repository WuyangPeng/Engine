//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/17 13:21)

#include "Rendering/RenderingExport.h"

#include "Utility.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

void Rendering::Utility::ReflectX(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel)
{
    RENDERING_ASSERTION_1(GetNumBytes(xSize, ySize, numBytesPerPixel) <= (end - begin), "迭代器范围不足");

    if (1 < xSize && 0 < ySize && 0 < numBytesPerPixel)
    {
        const auto step = GetNumBytes(xSize, 1, numBytesPerPixel);
        SpanIterator lhs{ begin, end, begin };
        SpanIterator rhs{ begin, end, begin };
        rhs += step;

        for (auto y = 0; y < ySize; ++y)
        {
            ReflectX(lhs, rhs, xSize, numBytesPerPixel);

            lhs += step;
            rhs += step;
        }
    }
}

// private
void Rendering::Utility::ReflectX(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel)
{
    RENDERING_ASSERTION_1(GetNumBytes(xSize, 1, numBytesPerPixel) <= (rhs - lhs), "迭代器范围不足");

    SpanIterator begin{ lhs.GetCurrent(), rhs.GetCurrent(), lhs.GetCurrent() };
    SpanIterator end{ lhs.GetCurrent(), rhs.GetCurrent(), rhs.GetCurrent() };
    const auto numBytesPerPixelPlus1 = numBytesPerPixel + 1;
    end -= numBytesPerPixelPlus1;

    const auto xMax = xSize / 2;
    for (auto x = 0; x < xMax; ++x)
    {
        for (auto i = 0; i < numBytesPerPixel; ++i)
        {
            IterSwap(begin, end);
            ++begin;
            ++end;
        }

        end -= numBytesPerPixel * 2;
    }
}

void Rendering::Utility::ReflectY(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel)
{
    RENDERING_ASSERTION_1(GetNumBytes(xSize, ySize, numBytesPerPixel) <= (end - begin), "迭代器范围不足");

    if (0 < xSize && 1 < ySize && 0 < numBytesPerPixel)
    {
        SpanIterator lhs{ begin, end, begin };
        SpanIterator rhs{ begin, end, begin };
        rhs += GetNumBytes(xSize, ySize - 1, numBytesPerPixel);

        const auto yMax = ySize / 2;
        for (auto y = 0; y < yMax; ++y)
        {
            ReflectY(lhs, rhs, xSize, numBytesPerPixel);

            lhs += xSize * numBytesPerPixel;
            rhs -= xSize * numBytesPerPixel;
        }
    }
}

// private
void Rendering::Utility::ReflectY(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel)
{
    SpanIterator begin{ lhs.GetCurrent(), rhs.GetEnd(), lhs.GetCurrent() };
    SpanIterator end{ lhs.GetCurrent(), rhs.GetEnd(), rhs.GetCurrent() };

    for (auto x = 0; x < numBytesPerPixel * xSize; ++x)
    {
        IterSwap(begin, end);
        ++begin;
        ++end;
    }
}